#pragma once

#include <IRenderUnit.hpp>
#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>
#include <memory>
#include <array>

template<typename TData>
class RenderUnit : public IRenderUnit {
private:
    std::unique_ptr<VertexArrayObject> m_vao;
    std::unique_ptr<ProgramShader> m_programShader;

protected:
    std::unique_ptr<TData> m_data;

public:
    virtual void render() const override = 0;

    TData* get_data() const;
    virtual void set_data(TData data) = 0;
    VertexArrayObject* get_vao() const;
    void set_vao(std::unique_ptr<VertexArrayObject> vao);

protected:
    ProgramShader* get_programShader() const;
    void set_programShader(std::vector<Shader> shaders);
};

template<typename TData>
TData* RenderUnit<TData>::get_data() const{
    return m_data.get();
}

template<typename TData>
VertexArrayObject* RenderUnit<TData>::get_vao() const {
    return m_vao.get();
}

template<typename TData>
void RenderUnit<TData>::set_vao(std::unique_ptr<VertexArrayObject> vao) {
    m_vao = std::move(vao);
}

template<typename TData>
ProgramShader* RenderUnit<TData>::get_programShader() const {
    return m_programShader.get();
}

template<typename TData>
void RenderUnit<TData>::set_programShader(std::vector<Shader> shaders) {
    auto p = new ProgramShader(shaders);
}