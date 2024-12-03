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
    Camera(Vector3df position, Vector3df direction, Vector3df up_vector, const Screen &screen);

    Vector3df position, direction, up_vector, right_vector{};

    float fov{};

    const Screen *screen{};



    Ray<float, 3> getRay(size_t x, size_t y) const;


};

#endif // CAMERA_H
