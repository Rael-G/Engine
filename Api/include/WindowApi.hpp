#pragma once

#include <ApiHeader.hpp>
#include <Window.hpp>

extern "c" ENGINE_API void init() {
	Window::init();
}