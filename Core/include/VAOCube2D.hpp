#include <VertexArrayObject.hpp>

class VAOCube2D : public VertexArrayObject {
public:
	unsigned int m_textureId;
private:
	unsigned int m_vboId;

	std::vector<float> m_vertices;

	const char* m_texturePath;

public:
	VAOCube2D(const std::vector<float>& vertices, const char* texturePath);

	void generate() override;
	unsigned int size() override;
	void free() const override;

private:
	void generate_texture();
};