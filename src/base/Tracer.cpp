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
    image[p * 3] = 255;
    image[p * 3 + 1] = 127;
    image[p * 3 + 2] = 0;
}

void Tracer::travel(Ray& ray) {

}