#pragma once

#include<enums/ShaderType.hpp>

struct Shader {
    unsigned int id;
    const char* source;
    ShaderType shader_type;
};