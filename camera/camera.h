//
// Created by mateo on 11/20/24.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <geometry/geometry.h>
#include <utils/math/math.h>

#include "scene/scene.h"
#include "screen/screen.h"
#include "utils/color/color.h"

class Camera {
public:
    Screen &screen;

    float focal_length;
    float viewport_height;
    float viewport_width;
    Vector3df camera_center;

    Vector3df viewport_u;
    Vector3df viewport_v;

    Vector3df pixel_delta_u;
    Vector3df pixel_delta_v;

    Vector3df viewport_upper_left;
    Vector3df pixel00_loc;

    Camera(Screen &screen, float focal_length, float viewport_height, int image_height, int image_width, Vector3df &camera_center);



    float fov = 1;



    Ray3df getRay(size_t x, size_t y) const;

    Color trace(Scene *scene, Ray<float, 3> ray, int depth) ;
    float calc_lambertian(int n, std::vector<Light> *lights, HitContext *hit_context);
};

#endif // CAMERA_H
