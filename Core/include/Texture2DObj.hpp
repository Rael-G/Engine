#pragma once

#include <GraphicalObject.hpp>
#include <ProgramShader.hpp>
#include <VAOTexture2D.hpp>

class Texture2DObj : public GraphicalObject
{
public:
    ProgramShader m_program_shader;
    VAOTexture2D& m_vao;

    Texture2DObj(ProgramShader program_shader, VAOTexture2D& vao, Transform3D& transform);

    void start() override;
    void render() const override;
    void free() const override;
};
