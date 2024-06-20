#include "pyramid.h"
#include <iostream>

void draw_pyramid(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
