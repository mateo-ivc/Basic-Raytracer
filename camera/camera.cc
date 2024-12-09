//
// Created by mateo on 11/20/24.
//

#include "camera.h"

#include "utils/hittable/hittable.h"

Camera::Camera(Vector3df position, Vector3df direction, Vector3df up_vector, const Screen &screen) :
        position(position), direction(direction), up_vector(up_vector), screen(&screen) {
    this->right_vector = direction.cross_product(up_vector);
    //warning: not sure if copy has to be sent
    this->direction.normalize();
    this->up_vector.normalize();

}

Ray<float, 3> Camera::getRay(size_t x, size_t y) const {
    //todo: properly set aspectRatio -> now set to 1.0f
    float nx = (2.0f * (x + 0.5f) / screen->getWidth() - 1.0f) * 1 * float(tan(fov / 2));
    float ny = (1.0f - 2.0f * (y + 0.5f) / screen->getHeight()) * float(tan(fov / 2));

    Vector<float, 3> ray_direction = (direction + nx * up_vector.cross_product(direction) + ny * up_vector);
    ray_direction.normalize();
    return Ray(position, ray_direction);
}

Color Camera::trace(Scene *scene, Ray<float, 3> ray, int depth) {
    if (depth<=0) {
        return {0.0f, 0.0f, 0.0f};
    }
    //some hit_context
    std::shared_ptr<HitContext> hit_context = scene->find_nearest_object(ray);
    //if it does not intersect -> return backgropund
    // if not hitting frontface return {1,1,1}

    //retrieve base color of hit object
    Color object_color;

    return {0,0,0};
}
