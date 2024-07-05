#pragma once

#include <vector>
#include <string>
#include <structs/Shader.hpp>
#include <glm/glm.hpp>

class ProgramShader
{
public:
    unsigned int m_id;

private:
    std::vector<Shader> m_shaders;

public:
    ProgramShader(std::vector<Shader> shaders);

    void generate();
    void use() const;
    void free() const;

    void setTransform(glm::mat4 transform) const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

private:
    void generate_ids();
    void compile_shader(Shader shader);
};