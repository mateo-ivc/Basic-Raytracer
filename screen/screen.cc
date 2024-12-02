//
// Created by mateo on 12/2/24.
//

#include "screen.h"

Screen::Screen(const size_t pixel_width, const size_t pixel_height) {
    this->pixel_width = pixel_width;
    this->pixel_height = pixel_height;
    this->buffer = std::unique_ptr<Color[]>(new Color[this->pixel_width * this->pixel_height]);
}

void Screen::setPixel(const size_t x, const size_t y, const Color color) {
    this->buffer[y * this->pixel_width + x] = color;
}

void Screen::clear(const Color color) {
    for (size_t x = 0u; x < getWidth(); x++) {
        for (size_t y = 0u; y < getHeight(); y++) {
            setPixel(x, y, color);
        }
    }
}

size_t Screen::getWidth() const {
    return this->pixel_width;
}

size_t Screen::getHeight() const {
    return this->pixel_height;
}

Color Screen::getPixel(size_t x, size_t y) const {
    return this->buffer[y * this->pixel_width + x];
}
