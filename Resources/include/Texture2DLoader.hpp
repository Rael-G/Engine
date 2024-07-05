#define STB_IMAGE_IMPLEMENTATION
#include <structs/Texture2D.hpp>

class Texture2DLoader {
public:
	static Texture2D load(const char* path);
	static void free(unsigned char* data);
};