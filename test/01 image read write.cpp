#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include <iostream>

using namespace std;

int main() {
    int width, height, channels;
    unsigned char* img = stbi_load(PROJECT_ROOT "/res/sudo password.png", &width, &height, &channels, 0);

    cout << PROJECT_ROOT << endl;

    stbi_write_png(PROJECT_ROOT "/res/password.png", width, height, channels, img, width * height * channels);
}