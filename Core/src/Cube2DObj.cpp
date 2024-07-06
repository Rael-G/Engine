#include <Cube2DObj.hpp>
#include <GlErrorUtils.hpp>
#include <Transformer.hpp>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>

Cube2DObj::Cube2DObj(ProgramShader program_shader, VAOCube2D& vao, Transform3D& transform)
    : m_program_shader(program_shader), m_vao(vao) {
    m_transform = transform;
}

void Cube2DObj::start() {
    m_vao.generate();
    m_program_shader.generate();
    glEnable(GL_DEPTH_TEST);
}

void Cube2DObj::render() const
{
    m_program_shader.use();
    m_program_shader.setInt("ourTexture", 0);
    m_program_shader.setMvp(Transformer::CalculateMvp(m_transform));
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_vao.m_textureId);
    glBindVertexArray(m_vao.m_id);
    glDrawArrays(GL_TRIANGLES, 0, m_vao.size());
    GlErrorUtils::check_error();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);
}

void Cube2DObj::free() const {
    m_vao.free();
    m_program_shader.free();
}
