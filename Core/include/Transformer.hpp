#pragma once

#include <structs/Transform3D.hpp>
#include <Camera.hpp>
#include <glm/glm.hpp>

class Transformer {
public:
    static glm::mat4 CalculateMvp(Transform3D transform3D);

private:
    static const glm::vec3 X_AXIS;
    static const glm::vec3 Y_AXIS;
    static const glm::vec3 Z_AXIS;

    static glm::mat4 Transform(Transform3D transform3D);

};
