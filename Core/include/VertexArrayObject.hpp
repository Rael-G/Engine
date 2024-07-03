#pragma once

#include <vector>

class VertexArrayObject {
public:
	unsigned int m_id = NULL;
	virtual void generate() = 0;
	virtual unsigned int size() = 0;
	virtual void free() const = 0;
};