#pragma once

#include <ApiHeader.hpp>

extern "C" ENGINE_API void render_unit(const char* id);

extern "C" ENGINE_API void remove_unit(const char* id);

extern "C" ENGINE_API void add_rectangle(const char* id, const float* transfrom, float width, float height, const float* color);

extern "C" ENGINE_API void update_rectangle(const char* id, const float* transfrom, float width, float height, const float* color);
