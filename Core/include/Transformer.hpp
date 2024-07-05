#pragma once

#include <structs/Transform3D.hpp>
#include <glm/glm.hpp>

class Transformer {
public:
    static glm::mat4 Transform(Transform3D transform3D); // Declaração da função

private:
    static const glm::vec3 X_AXIS;
    static const glm::vec3 Y_AXIS;
    static const glm::vec3 Z_AXIS;
};
