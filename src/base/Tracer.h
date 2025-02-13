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


    void perPixel(uint32_t);
    void travel(Ray&);

public:
    Tracer(uint32_t, uint32_t, World*, Camera*);

    void setWorld(World*);
    void setCamera(Camera*);

    void render();
    uint8_t* getImage() { return image; };
};