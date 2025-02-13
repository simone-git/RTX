#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;


int main() {
    int width, height, channels;

    unsigned char* img = stbi_load(PROJECT_ROOT "/res/colors.png", &width, &height, &channels, 0);

    // stride = width * channels: bytes per row
    stbi_write_png(PROJECT_ROOT "/res/img.png", width, height, channels, img, width * channels);
}