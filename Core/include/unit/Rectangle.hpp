#pragma once

#include <RenderUnit.hpp>
#include <data/RectangleData.hpp>

class Rectangle : public RenderUnit<RectangleData> {
public:
    Rectangle(RectangleData data);

    void render() const override;
    void set_data(RectangleData data) override;

private:
    static std::vector<Shader> get_shaders();
};