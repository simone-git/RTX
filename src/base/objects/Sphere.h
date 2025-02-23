#pragma once

#include "Object.h"

struct Sphere : public Object {
    glm::vec3 center;
    float radius;

    Sphere(glm::vec3, float);

    HitPayload hit(Ray) override;
};