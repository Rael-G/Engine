#pragma once

#include <glm/glm.hpp>
#include <Frustum.hpp>

class Camera {
public:
	static glm::vec3 m_position;
	static glm::vec3 m_target;
	static glm::vec3 m_up;
	static Frustum* m_frustum;

	static glm::mat4 projection();
	static glm::mat4 view();
};