#include <Perspective.hpp>
#include <glm/gtc/matrix_transform.hpp>


Perspective::Perspective(float fov, float aspect, float near, float far)
	: m_fov(fov), m_aspect(aspect), m_near(near), m_far(far) {

}

glm::mat4 Perspective::projection() const {
	return glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
}
