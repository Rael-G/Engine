#pragma once

#include <Frustum.hpp>

class Perspective : public Frustum {
public:
	float m_fov;
	float m_aspect;
	float m_near;
	float m_far;

	Perspective(float fov, float aspect, float near, float far);

	glm::mat4 projection() const override;
};