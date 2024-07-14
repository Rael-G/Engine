#include <GlErrorUtils.hpp>
#include <iostream>

void GlErrorUtils::check_shader_compilation(int shader_id) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
        std::cerr << "A shader failed to compile.\n" << infoLog << std::endl;
    }
}

void GlErrorUtils::check_program_linking(int program_id) {
    int success;
    char infoLog[512];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(program_id, 512, NULL, infoLog);
        std::cerr << "The Program Shader linking failed.\n" << infoLog << std::endl;
    }
}

void GlErrorUtils::check_error() {
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << error << std::endl;
    }
}

void GlErrorUtils::check_program(int expected_program)
{
    if (!check_status(GL_CURRENT_PROGRAM, expected_program))
        std::cerr << "The current program shader is diferent from the expected.\n";

}

void GlErrorUtils::check_vao(int expected_vao) {
    if (!check_status(GL_VERTEX_ARRAY_BINDING, expected_vao))
        std::cerr << "The binded vertex array object is diferent from the expected.\n";
}

void GlErrorUtils::check_vbo(int expected_vbo) {
    if (!check_status(GL_ARRAY_BUFFER_BINDING, expected_vbo))
        std::cerr << "The binded vertex buffer object is diferent from the expected.\n";
}

void GlErrorUtils::check_ebo(int expected_ebo) {
    if (!check_status(GL_ELEMENT_ARRAY_BUFFER_BINDING, expected_ebo))
        std::cerr << "The binded element buffer object is diferent from the expected.\n";
}

void GlErrorUtils::check_texture(int expected_texture) {
    if (!check_status(GL_TEXTURE_BINDING_2D, expected_texture))
        std::cerr << "The binded texture buffer object is diferent from the expected.\n";
}

bool GlErrorUtils::check_status(GLenum pname, GLint expected) {
    GLint data;
    glGetIntegerv(pname, &data);
    return data == expected;
}

void GlErrorUtils::error_callback(int error, const char* description)
{
    std::cerr << "Glfw Error: " << error << ". " << description << std::endl;
}
