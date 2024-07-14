#include <camera/Orthographic.hpp>
#include <glm/gtc/matrix_transform.hpp>

Orthographic::Orthographic(float left, float right, float bottom, float top, float near, float far)
	: m_left(left), m_right(right), m_bottom(bottom), m_top(top), m_near(near), m_far(far) {

}

glm::mat4 Orthographic::projection() const {
	return glm::ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
}
