//
// Created by mateo on 11/21/24.
//

#include "color.h"
#include <iostream> // Include for std::ostream

// Constructor implementation
Color::Color(float red, float green, float blue): red(red), green(green), blue(blue) {}

// Getters implementation
float Color::getRed() const { return red; }
float Color::getGreen() const { return green; }
float Color::getBlue() const { return blue; }


Color Color::operator+(Color addend) const {
    return Color(red + addend.red, green + addend.green, blue + addend.blue);
}

Color Color::operator*(Color factor) const {
    return Color(red * factor.red, green * factor.green, blue * factor.blue);
}

Color operator*(const float factor, Color color) {
    return Color(factor * color.red, factor * color.green, factor * color.blue);
}


void write_color(std::ostream &out, const Color &pixel_color) {
    auto r = pixel_color.getRed();
    auto g = pixel_color.getGreen();
    auto b = pixel_color.getBlue();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = static_cast<int>(255.999 * r);
    int gbyte = static_cast<int>(255.999 * g);
    int bbyte = static_cast<int>(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}