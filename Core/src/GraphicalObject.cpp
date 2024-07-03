#include <GraphicalObject.hpp>
#include <GlErrorUtils.hpp>
#include <glad/glad.h>

GraphicalObject::GraphicalObject(ProgramShader program_shader, VertexArrayObject vao)
    : m_program_shader(program_shader), m_vao(vao) {

}

void GraphicalObject::start() {
	m_program_shader.generate();
    m_vao.generate();
}

void GraphicalObject::render() const
{
    glUseProgram(m_program_shader.m_id);
    glBindVertexArray(m_vao.m_vao_id);
    glDrawElements(GL_TRIANGLES, m_vao.m_indexes.size(), GL_UNSIGNED_INT, 0);

    GlErrorUtils::check_error();

    glBindVertexArray(0);
}
