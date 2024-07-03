#include <VertexArrayObject.hpp>
#include <GlErrorUtils.hpp>
#include <glad/glad.h>
#include <iostream>

VertexArrayObject::VertexArrayObject(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
    : m_vao_id(NULL), m_vbo_id(NULL), m_ebo_id(NULL), m_vertices(vertices), m_indexes(indexes) { }


void VertexArrayObject::generate() {
    glGenVertexArrays(1, &m_vao_id);
    glGenBuffers(1, &m_vbo_id);
    glGenBuffers(1, &m_ebo_id);

    glBindVertexArray(m_vao_id);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(unsigned int), m_indexes.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    GlErrorUtils::check_vbo(m_vbo_id);
    GlErrorUtils::check_ebo(m_ebo_id);
    GlErrorUtils::check_vao(m_vao_id);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
