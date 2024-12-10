//
// Created by mateo on 11/20/24.
//

#include "camera.h"

#include "utils/hittable/hittable.h"


Ray3df Camera::getRay(size_t x, size_t y) const {
    //todo: properly set aspectRatio -> now set to 1.0f
    Vector3df pixel_center = pixel00_loc + static_cast<float>(x) * pixel_delta_u + static_cast<float>(y) * pixel_delta_v;
    return Ray3df (camera_center, pixel_center - camera_center);
}

float Camera::calc_lambertian(int n, std::vector<Light> *lights, HitContext *hit_context) {
    Material material = hit_context->hittable.material;
// todo implement different colors
    float average_light = 0.01;
    for (Light &light: *lights) {
        Vector3df direction_towards_light = light.getPosition() - hit_context->intersection_point;
        direction_towards_light.normalize();
        float l = material.getDiffuse() * std::max(0.0f, hit_context->normal * direction_towards_light);
        average_light += l;
    }
    average_light /= n;
    return material.getAmbient() + average_light;
}

Color Camera::trace(Scene *scene, Ray<float, 3> ray, int depth) {
    if (depth <= 0) {
        return {0.0f, 0.0f, 0.0f};
    }

    //some hit_context
    std::shared_ptr<HitContext> hit_context = scene->find_nearest_object(ray);
    if (hit_context == nullptr || hit_context->t < 0.0f) {
        return {0, 0, 0};
    }

    if (!hit_context->front_face) {
        return {1, 1, 1};
    }

    Color reflection_color = hit_context->hittable.material.getColor();
    if (hit_context->hittable.material.getReflection() > 0.0f) {
        Vector3df reflected_direction =
                ray.direction - 2.0f * (ray.direction * hit_context->normal) * hit_context->normal;
        Ray3df reflected_ray(hit_context->intersection_point + 0.001f * hit_context->normal, reflected_direction);
        Color reflected_color = trace(scene, reflected_ray, depth - 1);
        reflection_color = hit_context->hittable.material.getReflection() * reflected_color;
        reflection_color = reflection_color * hit_context->hittable.material.getColor();
    }

    std::shared_ptr<std::vector<Light>> lights = scene->find_light_soruces(*hit_context);

    return calc_lambertian(scene->lights.size(), lights.get(), hit_context.get()) * reflection_color;
}

Camera::Camera(Screen &screen, float focal_length, float viewport_height, int image_height, int image_width,
               Vector3df &camera_center) : screen(screen),
                                           focal_length(focal_length),
                                           viewport_height(viewport_height),
                                           viewport_width(
                                                   viewport_height * (static_cast<float>(image_width) / image_height)),
                                           camera_center(camera_center),
                                           viewport_u({viewport_width, 0.0f, 0.0f}),
                                           viewport_v({0.0f, -viewport_height, 0.0f}),
                                           pixel_delta_u((1.0f / image_width) * viewport_u),
                                           pixel_delta_v((1.0f / image_height) * viewport_v),
                                           viewport_upper_left(camera_center - Vector3df{0.0f, 0.0f, focal_length} -
                                                               0.5f * viewport_u - 0.5f * viewport_v),
                                           pixel00_loc(viewport_upper_left + 0.5f * (pixel_delta_u + pixel_delta_v)) {

}
