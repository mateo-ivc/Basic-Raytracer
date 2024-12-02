//
// Created by mateo on 12/2/24.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <memory>
#include "utils/color/color.h"


class Screen {
    size_t pixel_width, pixel_height;
    std::unique_ptr<Color []> buffer;

public:
    Screen(size_t pixel_width, size_t pixel_height);

    void setPixel(size_t x, size_t y, Color color);

    void clear(Color color = Color(0, 0, 0));

    size_t getHeight() const;

    size_t getWidth() const;

    Color getPixel(size_t x, size_t y) const;
};


#endif //SCREEN_H
