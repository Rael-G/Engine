#include <ProgramShader.hpp>
#include <GlErrorUtils.hpp>
#include <glad/glad.h>
#include <iostream>

ProgramShader::ProgramShader(std::vector<Shader> shaders)
    : m_id(NULL), m_shaders(shaders) { }

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

void ProgramShader::generate()
{
    generate_ids();

    try {
        for (const Shader& shader : m_shaders) {
            compile_shader(shader);
            glAttachShader(m_id, shader.id);
        }
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    glLinkProgram(m_id);
    GlErrorUtils::check_program_linking(m_id);

}

