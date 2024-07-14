#pragma once

class VertexArrayObject {
protected:
	unsigned int m_id = 0;

public:
	unsigned int get_id() const;
	virtual unsigned int size() = 0;
};