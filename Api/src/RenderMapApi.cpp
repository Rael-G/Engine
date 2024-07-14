#include <RenderMapApi.hpp>
#include <unit/Rectangle.hpp>
#include <RenderMap.hpp>
#include <memory>
#include <string>
#include <camera/Orthographic.hpp>
#include <vao/RectangleVAO.hpp>

void render_unit(const char* id) {
	RenderMap::render(id);
}

void remove_unit(const char* id) {
	RenderMap::remove(id);
}

void add_rectangle(const char* id, const float* transform, float width, float height, const float* color) {
	RenderMap::add(id, std::make_unique<Rectangle>(RectangleData{ transform, width, height, color }));
}

void update_rectangle(const char* id, const float* transform, float width, float height, const float* color) {
	RenderMap::update<RectangleData>(id, RectangleData{ transform, width, height, color });
}
