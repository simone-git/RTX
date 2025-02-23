#include "../src/base/Tracer.h"
#include "../src/base/Camera.h"
#include "../src/base/objects/Sphere.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <iostream>

using namespace std;

int main() {
    constexpr uint32_t width = 100, height = 100, area = width * height;

    World world;
    Camera camera(45.0f, 0.1f, 100.0f);

    Tracer rtx(width, height, &world, &camera);


    glm::vec3 pos = camera.GetPosition();
    camera.OnResize(width, height);
    vector<glm::vec3> dirs = camera.GetRayDirections();

    vector<Ray> rays(area);
    for(int i = 0; i < area; i++) {
        rays[i].src = pos;
        rays[i].dir = dirs[i];
    }

    // Sphere s({0, 0, -10}, 10);
    std::shared_ptr<Sphere> s(new Sphere({0, 0, -10}, 1));
    world.addObject(s);
    std::shared_ptr<Sphere> t(new Sphere({0, 0, -10}, 1));
    world.addObject(t);
    std::shared_ptr<Sphere> u(new Sphere({0, 0, -10}, 1));
    world.addObject(u);

    rtx.render();
    uint8_t* img = rtx.getImage();

    stbi_write_png(PROJECT_ROOT "/res/img.png", width, height, 3, img, width * 3);
}