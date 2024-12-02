//
// Created by mateo on 11/28/24.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H
#include <utils/math/math.h>
#include "utils/color/color.h"


class Light {
    Vector3df position;
    Color color;

public:
    Light(Vector3df position, Color color);

    Color getColor() const;

    Vector3df getPosition() const;
};


#endif //RAYTRACER_LIGHT_H
