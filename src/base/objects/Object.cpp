#include "Object.h"

HitPayload::HitPayload(bool isHit, uint32_t id, float distance) {
    this->isHit = isHit;
    this->id = id;
    this->distance = distance;
}


Object::Object() {
    id = seqIdGen;
    seqIdGen++;
}

uint32_t Object::seqIdGen = 1;