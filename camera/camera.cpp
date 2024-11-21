//
// Created by mateo on 11/20/24.
//

#include "camera.h"

auto aspect_ratio = 16.0 / 9.0;
int image_width = 400;


Camera::Camera(float viewport_height, float focal_length) {
    this->image_height = (image_height < 1) ? 1 : image_height;
    this->focal_length = focal_length;
    this->camera_center = Vector3df{0.0, 0.0, 0.0};

    this->viewport_height = viewport_height;
    this->viewport_width = viewport_height * (float(image_width) / float(image_height));

    this->viewport_u = Vector3df{viewport_width, 0, 0};
    this->viewport_v = Vector3df{0, -viewport_height, 0};

    this->pixel_delta_u = viewport_u / float(image_width);
    this->pixel_delta_v = viewport_v / float(image_height);
}


color Camera::ray_color(const Ray<float, 3u> &r) {
    r.direction.normalize();
    Vector3df unit_direction = r.direction;
    float a = 0.5f*(unit_direction[2] + 1.0f);
    return (1.0f-a)*color{1.0, 1.0, 1.0} + a*color{0.5, 0.7, 1.0};
}
