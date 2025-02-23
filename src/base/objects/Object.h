#pragma once

#include "../Ray.h"

struct HitPayload {
    bool isHit;
    float distance;

    HitPayload(bool isHit, float distance) : isHit(isHit), distance(distance) {}
};

class Object {
public:
    virtual HitPayload hit(Ray) = 0;
};