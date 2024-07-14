#pragma once

#include <VertexArrayObject.hpp>
#include <vector>

class RectangleVAO : public VertexArrayObject {
public:

private:
	unsigned int m_vboId;
	unsigned int m_eboId;

	std::vector<float> m_vertices;
	static std::vector<unsigned int> m_indexes;

public:
	RectangleVAO(float width, float height);
	~RectangleVAO();
private:
	void generate();
	unsigned int size() override;

	static std::vector<float> generateVertices(float width, float height);
};