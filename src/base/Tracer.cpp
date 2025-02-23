#include "Tracer.h"

Tracer::Tracer(const uint32_t width, const uint32_t height, World* world, Camera* camera) {
    this->width = width;
    this->height = height;
    this->world = world;
    this->camera = camera;

    image = new uint8_t[width * height * 3];
}


void Tracer::setWorld(World* world) {
    this->world = world;
}

void Tracer::setCamera(Camera* camera) {
    this->camera = camera;
}


void Tracer::render() {
    rays = camera->GetRays();

    for(uint32_t p = 0; p < camera->GetSurfaceArea(); p++) {
        perPixel(p);
    }
}

void Tracer::perPixel(uint32_t p) {
    const uint32_t id = closestHitObjID(rays[p]);

    if(id > 0) {
        image[p * 3] = 0;
        image[p * 3 + 1] = 0;
        image[p * 3 + 2] = 0;
    } else {  // Capture free space
        image[p * 3] = 46;
        image[p * 3 + 1] = 200;
        image[p * 3 + 2] = 239;
    }
}

uint32_t Tracer::closestHitObjID(const Ray& ray) const {
    float hitDistance = std::numeric_limits<float>::max();
    uint32_t retID = 0;

    for(uint32_t id = 1; id <= world->objs.size(); id++) {
        std::shared_ptr<Object> o;
        HitPayload payload = world->objs[id - 1]->hit(ray);  // TODO: 'id - 1'

        if(payload.isHit) {
            hitDistance = glm::min(hitDistance, payload.distance);
            retID = id;
        }
    }

    return retID;
}

// void Tracer::travel(Ray& ray) {
//
// }