#pragma once

#include <GraphicalObject.hpp>
#include <ProgramShader.hpp>
#include <VAOCube2D.hpp>

class Cube2DObj : public GraphicalObject
{
public:
    ProgramShader m_program_shader;
    VAOCube2D& m_vao;

    Cube2DObj(ProgramShader program_shader, VAOCube2D& vao, Transform3D& transform);

    void start() override;
    void render() const override;
    void free() const override;
};
