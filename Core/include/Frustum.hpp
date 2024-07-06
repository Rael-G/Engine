#pragma once

#include <glm/glm.hpp>

class Frustum {
public:
	virtual glm::mat4 projection() const = 0;
};