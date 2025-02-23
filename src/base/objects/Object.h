#pragma once

#include "../Ray.h"

struct HitPayload {
    bool isHit;
    uint32_t id;
    float distance;

    HitPayload(bool, uint32_t, float);
};

class Object {
    static uint32_t seqIdGen;

public:
    uint32_t id;

    Object();

    virtual HitPayload hit(Ray) = 0;
};