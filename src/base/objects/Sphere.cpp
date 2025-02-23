#include "Sphere.h"

#include "glm/ext/quaternion_geometric.hpp"

Sphere::Sphere(glm::vec3 center, float radius) {
    this->center = center;
    this->radius = radius;
}

HitPayload Sphere::hit(Ray ray) {
    // at^2 + bt + x = 0
    // a = dir_x^2 + dir_y^2 + dir_z^2
    // b = 2(pos_x*dir_x + pos_y*dir_y + pos_z*dir_z)
    // c = pos_x^2 + pos_y^2 + pos_z^2 - radius^2
    // t = hit distance

    glm::vec3 rayRelSrc = ray.src - center;

    float a = glm::dot(ray.dir, ray.dir);
    float b = 2.0f * glm::dot(rayRelSrc, ray.dir);
    float c = glm::dot(rayRelSrc, rayRelSrc) - radius * radius;

    float d = b * b - 4.0f * a * c;

    if(d < 0)
        return {false, 0, 0};

    float tNear = (-b - glm::sqrt(d)) / 2.0f / a;

    return {true, id, tNear};
}
