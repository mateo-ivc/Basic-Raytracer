//
// Created by mateo on 11/20/24.
//

#ifndef CAMERA_H
#define CAMERA_H
#include <geometry/geometry.h>
#include <utils/math/math.h>
#include "utils/color/color.h"

class Camera {
public:
    Camera(int image_width,float viewport_height, float focal_length);
    color ray_color(Ray<float, 3u> &r);

public:
    float viewport_height;
    float viewport_width;
    int image_width{};
    int image_height{};
    float focal_length{};
    Vector3df camera_center{};
    Vector3df viewport_u{};
    Vector3df viewport_v{};
    Vector3df pixel_delta_u{};
    Vector3df pixel_delta_v{};
};

#endif // CAMERA_H
