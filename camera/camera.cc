//
// Created by mateo on 11/20/24.
//

#include "camera.h"

Camera::Camera(const Vector3df position, const Vector3df direction, const Screen &screen): position(position), direction(direction), screen(&screen) {

}


Color Camera::ray_color(Ray<float, 3> &r) {
    r.direction.normalize();
    float a = 0.5f * (r.direction[2] + 1.0f);
    return (1.0f - a) * Color{1.0, 1.0, 1.0} + a * Color{0.5, 0.7, 1.0};
}
