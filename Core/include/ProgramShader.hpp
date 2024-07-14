#pragma once

#include <vector>
#include <string>
#include <structs/Shader.hpp>

class ProgramShader
{
private:
    unsigned int m_id;

    std::vector<Shader> m_shaders;

public:
    ProgramShader(std::vector<Shader> shaders);

    unsigned int get_id() const;

    void generate();
    void use() const;

    void setTransform(const float* transform) const;
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec4f(const std::string& name, const float* value) const;
    void setMat4f(const std::string& name, const float* value) const;

    ~ProgramShader();

private:
    void generate_ids();
    void compile_shader(Shader shader);
};