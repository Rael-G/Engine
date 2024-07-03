#pragma once

#include <vector>

class VertexArrayObject {
public:
	
	unsigned int m_vao_id;
	unsigned int m_vbo_id;
	unsigned int m_ebo_id;

	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indexes;

	VertexArrayObject(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

	void generate();
};