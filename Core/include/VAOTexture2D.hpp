#include <VertexArrayObject.hpp>

class VAOTexture2D : public VertexArrayObject {
public:
	unsigned int m_textureId;
private:
	unsigned int m_vboId;
	unsigned int m_eboId;

	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indexes;
	std::vector<float> m_texCoords;

	const char* m_texturePath;

public:
	VAOTexture2D(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, const std::vector<float>& texCoords, const char* texturePath);

	void generate() override;
	unsigned int size() override;
	void free() const override;

private:
	void generate_texture();
};