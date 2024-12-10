//
// Created by mateo on 11/21/24.
//

#include "color.h"
#include <iostream> // Include for std::ostream

// Constructor implementation
Color::Color(float red, float green, float blue) : red(red > 1 ? 1 : red), green(green > 1 ? 1 : green), blue(blue > 1 ? 1 : blue) {}

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
