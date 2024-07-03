#pragma once

#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>

class GraphicalObject
{
public :
    virtual void start() = 0;
    virtual void render() const = 0;
    virtual void free() const = 0;
};
