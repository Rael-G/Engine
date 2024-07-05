#include <Texture2DLoader.hpp>
#include <stb_image.h>
#include <exception>
#include <string>

Texture2D Texture2DLoader::load(const char* path) {
	Texture2D texture;
	stbi_set_flip_vertically_on_load(true);
	texture.data = stbi_load(path, &texture.width, &texture.height, &texture.nrChannels, 0);
	if (!texture.data)
		throw std::exception(("TextureLoader2D failed to load image from " + std::string(path) + ".\n").c_str());
	return texture;
}

void Texture2DLoader::free(unsigned char* data) {
	stbi_image_free(data);
}
