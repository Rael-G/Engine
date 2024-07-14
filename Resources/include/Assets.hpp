#pragma once

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

static fs::path currentPath = fs::current_path();

namespace Assets {
	const std::string RECTANGLE_VERTEX_SHADER = currentPath.string() + "/assets/shaders/RectangleVertexShader.glsl";

	const std::string RECTANGLE_FRAGMENT_SHADER = currentPath.string() + "/assets/shaders/RectangleFragmentShader.glsl";
}

