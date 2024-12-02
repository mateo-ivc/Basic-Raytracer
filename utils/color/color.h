#ifndef COLOR_H
#define COLOR_H
#include <ostream>

class Color {
private:
    float red, green, blue; // 0.0 - 1.0

public:
    Color(float red = 0.0, float green = 0.0, float blue = 0.0);

    float getRed() const;
    float getGreen() const;
    float getBlue() const;

    Color operator+(Color addend) const;
    Color operator*(Color factor) const;

    friend Color operator*(float factor, Color color);

};
void write_color(std::ostream &out, const Color &pixel_color);
#endif // COLOR_H