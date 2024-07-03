#pragma once

#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>

class GraphicalObject
{
public :
    ProgramShader m_program_shader;
    VertexArrayObject m_vao;

    GraphicalObject(ProgramShader program_shader, VertexArrayObject vao);

    void start();
    void render() const;
};
