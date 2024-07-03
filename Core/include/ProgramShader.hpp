#pragma once

#include <vector>
#include <structs/Shader.hpp>

class ProgramShader
{
public:
    unsigned int m_id;
    std::vector<Shader> m_shaders;

    ProgramShader(std::vector<Shader> shaders);

    void generate();

private:
    void generate_ids();
    void compile_shader(Shader shader);
};