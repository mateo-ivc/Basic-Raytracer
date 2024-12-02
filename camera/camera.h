//
// Created by mateo on 11/20/24.
//

#ifndef CAMERA_H
#define CAMERA_H
#include <geometry/geometry.h>
#include <utils/math/math.h>

#include "screen/screen.h"
#include "utils/color/color.h"

class Camera {
public:
    Camera(Vector3df position, Vector3df direction, const Screen &screen);
    Vector3df position, direction;
    float fow{};
    const Screen *screen{};
    static Color ray_color(Ray<float, 3u> &r);
};

#endif // CAMERA_H
