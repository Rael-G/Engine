#pragma once

#include <VertexArrayObject.hpp>
#include <vector>

class TestVAO : public VertexArrayObject {
public:

private:
	unsigned int m_vboId;
	unsigned int m_eboId;

	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indexes;

public:
	TestVAO(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);

	void generate() override;
	unsigned int size() override;
	void free() const override;
};