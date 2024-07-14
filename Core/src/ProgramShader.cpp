#include <ProgramShader.hpp>
#include <GlErrorUtils.hpp>

ProgramShader::ProgramShader(std::vector<Shader> shaders)
    : m_id(0) /*, m_shaders(shaders)*/
{
    generate();
}

unsigned int ProgramShader::get_id() const {
    return m_id;
}

void ProgramShader::generate()
{
    generate_ids();

    for (const Shader& shader : m_shaders) {
        compile_shader(shader);
        glAttachShader(m_id, shader.id);
    }

    //glLinkProgram(m_id);
    //GlErrorUtils::check_program_linking(m_id);

    for (const Shader& shader : m_shaders) {
        glDeleteShader(shader.id);
    }
}

void ProgramShader::use() const
{
    glUseProgram(m_id);
}

void ProgramShader::setTransform(const float* transform) const {
    unsigned int transformLoc = glGetUniformLocation(m_id, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transform);
}

void ProgramShader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
}
void ProgramShader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}
void ProgramShader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}

void ProgramShader::setVec4f(const std::string& name, const float* value) const {
    glUniform4fv(glGetUniformLocation(m_id, name.c_str()), 1, value);
}

void ProgramShader::generate_ids() {
    for (Shader& shader : m_shaders) {
        GLenum st = static_cast<GLenum>(shader.shaderType);
        unsigned int id = shader.id;
        id = glCreateShader(st);
        shader.id = id;
    }
    //m_id = glCreateProgram();
}

void ProgramShader::compile_shader(Shader shader) {
    auto src = shader.source.c_str();
    glShaderSource(shader.id, 1, &src, NULL);
    glCompileShader(shader.id);

    GlErrorUtils::check_shader_compilation(shader.id);
}

ProgramShader::~ProgramShader() {
    glDeleteProgram(m_id);
}
