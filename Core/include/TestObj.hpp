#pragma once

#include <GraphicalObject.hpp>
#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>

class TestObj : public GraphicalObject
{
public:
    ProgramShader m_program_shader;
    VertexArrayObject& m_vao;

    TestObj(ProgramShader program_shader, VertexArrayObject& vao);

    void start() override;
    void render() const override;
    void free() const override;
};
