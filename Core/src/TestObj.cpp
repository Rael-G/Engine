#include <TestObj.hpp>
#include <GlErrorUtils.hpp>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

TestObj::TestObj(ProgramShader program_shader, VertexArrayObject& vao)
    : m_program_shader(program_shader), m_vao(vao) {

}

void TestObj::start() {
    m_program_shader.generate();
    m_vao.generate();
}

void TestObj::render() const
{
    glUseProgram(m_program_shader.m_id);
    glBindVertexArray(m_vao.m_id);
    glDrawElements(GL_TRIANGLES, m_vao.size(), GL_UNSIGNED_INT, 0);
    GlErrorUtils::check_error();

    glBindVertexArray(0);
}

void TestObj::free() const {
    m_vao.free();
    m_program_shader.free();
}

