#include <unit/Rectangle.hpp>
#include <ShaderLoader.hpp>
#include <Assets.hpp>
#include <vao/RectangleVAO.hpp>
#include <GlErrorUtils.hpp>

Rectangle::Rectangle(RectangleData data){
    m_data = std::make_unique<RectangleData>(data);
    set_vao(std::make_unique<RectangleVAO>(get_data()->width, get_data()->height));
    set_programShader(get_shaders());
}

void Rectangle::render() const
{
    glUseProgram(get_programShader()->get_id());
    get_programShader()->setTransform(get_data()->transform);
    get_programShader()->setVec4f("color", get_data()->color);
    auto vaoid = get_vao()->get_id();
    glBindVertexArray(get_vao()->get_id());
    glDrawElements(GL_TRIANGLES, get_vao()->size(), GL_UNSIGNED_INT, 0);

    //GlErrorUtils::check_error();

    glBindVertexArray(0);
}

std::vector<Shader> Rectangle::get_shaders() {
    std::vector<Shader> shaders = std::vector<Shader>(2);
    shaders[0] = ShaderLoader::read(Assets::RECTANGLE_VERTEX_SHADER);
    shaders[0].shaderType = ShaderType::Vertex;
    shaders[1] = ShaderLoader::read(Assets::RECTANGLE_FRAGMENT_SHADER);
    shaders[1].shaderType = ShaderType::Fragment;

    return shaders;\
}

void Rectangle::set_data(RectangleData data) {
    if (get_data()->width != data.width || get_data()->height != data.height)
        set_vao(std::make_unique<RectangleVAO>(RectangleVAO(data.width, data.height)));

    *m_data = data;
}

