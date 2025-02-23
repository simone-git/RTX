#pragma once

#include "World.h"
#include "Camera.h"
#include "Ray.h"
#include <vector>

class Tracer {
    uint32_t width, height;
    uint8_t* image;

    World* world;
    Camera* camera;

    std::vector<Ray> rays;


    uint32_t closestHitObjID(const Ray&) const;
    void perPixel(uint32_t);
    // void travel(const Ray&);

public:
    Tracer(uint32_t, uint32_t, World*, Camera*);

    void setWorld(World*);
    void setCamera(Camera*);

    void render();
    uint8_t* getImage() { return image; };
};