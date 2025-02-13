#include "../src/base/Tracer.h"
#include "../src/base/Camera.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <iostream>

using namespace std;

int main() {
    uint32_t width = 4, height = 4, area = width * height;

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

    rtx.render();
    uint8_t* img = rtx.getImage();

    stbi_write_png(PROJECT_ROOT "/res/img.png", width, height, 3, img, width * 3);
}