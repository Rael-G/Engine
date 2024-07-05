#include <ProgramShader.hpp>
#include <GlErrorUtils.hpp>
#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

ProgramShader::ProgramShader(std::vector<Shader> shaders)
    : m_id(NULL), m_shaders(shaders) { }

void ProgramShader::generate()
{
    generate_ids();

    for (const Shader& shader : m_shaders) {
        compile_shader(shader);
        glAttachShader(m_id, shader.id);
    }

    glLinkProgram(m_id);
    GlErrorUtils::check_program_linking(m_id);

    for (const Shader& shader : m_shaders) {
        glDeleteShader(shader.id);
    }

}

void ProgramShader::use() const
{
    glUseProgram(m_id);
}

void ProgramShader::free() const {
    glDeleteProgram(m_id);
}

void ProgramShader::setTransform(glm::mat4 transform) const {
    unsigned int transformLoc = glGetUniformLocation(m_id, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
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

void ProgramShader::generate_ids() {
    for (Shader& shader : m_shaders) {
        shader.id = glCreateShader(static_cast<GLenum>(shader.shader_type));
    }
    m_id = glCreateProgram();
}

void ProgramShader::compile_shader(Shader shader) {
    glShaderSource(shader.id, 1, &shader.source, NULL);
    glCompileShader(shader.id);

    GlErrorUtils::check_shader_compilation(shader.id);
}
