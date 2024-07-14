#pragma once

#include <Frustum.hpp>

class Orthographic : public Frustum {
public:
	float m_left;
	float m_right;
	float m_bottom;
	float m_top;
	float m_near;
	float m_far;


	Orthographic(float left, float right, float bottom, float top, float near, float far);

	glm::mat4 projection() const override;

	static glm::mat4 ortho(float left, float right, float bottom, float top, float near, float far);
};