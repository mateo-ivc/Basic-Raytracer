//
// Created by mateo on 11/21/24.
//

#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <utils/math/math.h>
using color = Vector3df;

void write_color(std::ostream &out, const color &pixel_color);
#endif //COLOR_H
