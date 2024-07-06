#include <Camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Perspective.hpp>

glm::vec3 Camera::m_position{ 0.0f, 0.0f, 3.0f };
glm::vec3 Camera::m_target{ 0.0f, 0.0f, -1.0f };
glm::vec3 Camera::m_up{ 0.0f, 1.0f, 0.0f };

static auto p = Perspective(45, 16.0f / 9.0f, 0.5f, 100.0f);
Frustum* Camera::m_frustum = &p;

glm::mat4 Camera::projection() {
	return m_frustum->projection();
}

glm::mat4 Camera::view() {
	return glm::lookAt(m_position, m_target, m_up);
}