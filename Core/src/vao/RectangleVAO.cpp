#include <vao/RectangleVAO.hpp>

#include <GlErrorUtils.hpp>
#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

std::vector<unsigned int> RectangleVAO::m_indexes = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

RectangleVAO::RectangleVAO(float width, float height)
    : m_vboId(0), m_eboId(0), m_vertices(generateVertices(width, height)){
    generate();
}

void RectangleVAO::generate() {

    if (!glfwGetCurrentContext()) {
        std::cout << "No OpenGL context active after initialization.\n";
    }
    else {
        std::cout << "OpenGL context is active.\n";
    }
    unsigned int id = 0;
    glGenVertexArrays(1, &id);
    glGenBuffers(1, &m_vboId);
    glGenBuffers(1, &m_eboId);

    glBindVertexArray(m_id);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(unsigned int), m_indexes.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    GlErrorUtils::check_vbo(m_vboId);
    GlErrorUtils::check_ebo(m_eboId);
    GlErrorUtils::check_vao(m_id);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int RectangleVAO::size() {
    return m_indexes.size();
}

std::vector<float> RectangleVAO::generateVertices(float width, float height) {
    std::vector<float> vertices {
        0.0f, 0.0f, 0.0f,  // Bottom left
        0.0f, height, 0.0f,  // Top left
        width, height, 0.0f,   //Top right
        width, 0.0f, 0.0f,    // Bottom right
    };

    return vertices;
}

RectangleVAO::~RectangleVAO() {
    glDeleteVertexArrays(1, &m_id);
    glDeleteBuffers(1, &m_vboId);
    glDeleteBuffers(1, &m_eboId);
}