#pragma once

#include <ApiHeader.hpp>
#include <Window.hpp>
#include <structs/WindowData.hpp>

extern "C" ENGINE_API void init(int width, int height, const char* title);

extern "C" ENGINE_API void config();

extern "C" ENGINE_API void begin_render();

extern "C" ENGINE_API void end_render();

extern "C" ENGINE_API void close();

extern "C" ENGINE_API int key_status(int key);

extern "C" ENGINE_API void set_config(const WindowData& data);

extern "C" ENGINE_API bool get_is_running();

extern "C" ENGINE_API void set_is_running(bool isRunning);

extern "C" ENGINE_API int* get_viewport();

extern "C" ENGINE_API void set_viewport(int* viewport);