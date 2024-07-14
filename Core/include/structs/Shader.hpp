#pragma once

#include <enums/ShaderType.hpp>

struct Shader {
    unsigned int id = 0;
    std::string source = "";
    ShaderType shaderType = ShaderType::Vertex;
};