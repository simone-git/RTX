#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include <iostream>

#include <glm/vec3.hpp>


using namespace std;


int main() {
    int width, height, channels;
    unsigned char* img = stbi_load(PROJECT_ROOT "/res/colors.png", &width, &height, &channels, 0);

    cout << "Channels: " << channels << endl;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int p = (y * width + x) * channels;

            for(int c = 0; c < channels; c++) {
                cout << (int)img[p + c] << ' ';
                img[p + c] = 255;
            }
            cout << endl;
        }
    }

    stbi_write_png(PROJECT_ROOT "/res/password.png", width, height, channels, img, width * height * channels);
}