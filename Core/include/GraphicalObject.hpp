#pragma once

#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>
#include <structs/Transform3D.hpp>

class GraphicalObject
{
public:
    Transform3D m_transform;

    virtual void start() = 0;
    virtual void render() const = 0;
    virtual void free() const = 0;
};
