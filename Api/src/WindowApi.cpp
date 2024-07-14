#include <WindowApi.hpp>

void init(int width, int height, const char* title) {
	Window::init(width, height, title);
}

void config() {
	Window::config();
}

void begin_render() {
	Window::begin_render();
}

void end_render() {
	Window::end_render();
}

void close() {
	Window::close();
}

int key_status(int key) {
	return Window::key_status(key);
}

void set_config(const WindowData& data) {
	Window::set_config(data);
}

bool get_is_running() {
	return Window::get_isRunning();
}

void set_is_running(bool isRunning) {
	Window::set_isRunning(isRunning);
}

int* get_viewport() {
	int vp_ptr[2] = { Window::getViewport().x, Window::getViewport().y };
	return vp_ptr;
}

void set_viewport(int* viewport) {
	Window::setViewport(glm::ivec2(*viewport, *(viewport + 1)));
}