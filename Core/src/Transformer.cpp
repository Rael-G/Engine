#include <Transformer.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <camera/Camera.hpp>

const glm::vec3 Transformer::X_AXIS = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Transformer::Y_AXIS = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 Transformer::Z_AXIS = glm::vec3(0.0f, 0.0f, 1.0f);

glm::mat4 Transformer::CalculateMvp(Transform3D transform3D) {

	auto proj = Camera::projection();
	auto view = Camera::view();
	auto trans = Transform(transform3D);
	return proj * view * trans;
	//return Camera::projection() * Camera::view() * Transform(transform3D);
}

glm::mat4 Transformer::Transform(Transform3D transform3D) {
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, transform3D.position);
	transform = glm::rotate(transform, transform3D.rotation.x, Transformer::X_AXIS);
	transform = glm::rotate(transform, transform3D.rotation.y, Transformer::Y_AXIS);
	transform = glm::rotate(transform, transform3D.rotation.z, Transformer::Z_AXIS);
	transform = glm::scale(transform, transform3D.scale);
	return transform;
}