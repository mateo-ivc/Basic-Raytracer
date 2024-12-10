//
// Created by mateo on 11/28/24.
//

#include "scene.h"

static Material WHITE({1.0f, 1.0f, 1.0f}, 1.0f, 0.4f, 0.0f, 0.0f);
static Material MATTE_WHITE({1.0f, 1.0f, 1.0f}, 0.9f, 0.2f, 0.0f, 0.0f);
static Material GRAY({0.7f, 0.7f, 0.7f}, 0.7f, 0.2f, 0.0f, 0.0f);
static Material MATTE_RED({1.0f, 0.0f, 0.0f}, 0.5f, 0.2f, 0.0f, 0.0f);
static Material MATTE_GREEN({0.0f, 1.0f, 0.0f}, 0.5f, 0.2f, 0.0f, 0.0f);
static Material REFLECTIVE_BLUE({0.0f, 0.0f, 1.0f}, 1.0f, 0.2f, 1.0f, 0.0f);
static Material MATTE_BLUE({0.0f, 0.0f, 1.0f}, 1.0f, 0.2f, 0.0f, 0.0f);
static Material REFLECTIVE_WHITE({1.0f, 1.0f, 1.0f}, 1.0f, 0.2f, 1.0f, 0.0f);

void Scene::addObject(Hittable object) {
    this->objects.push_back(object);
}

void Scene::addLight(const Light &light) {
this->lights.push_back(light);
}

std::shared_ptr<HitContext> Scene::find_nearest_object(Ray3df ray, float t_min, float t_max) {
    std::shared_ptr<HitContext> nearest_object = nullptr;
    float minimal_t = INFINITY;
    for (Hittable &h : objects) {
            float t = h.sphere.intersects(ray);
            if (t > t_min && t < minimal_t && t < t_max)
            {
                nearest_object = std::make_shared<HitContext>(t, ray, h);
                minimal_t = t;
            }

    }
    return nearest_object;
}

std::shared_ptr<std::vector<Light>> Scene::find_light_soruces(HitContext &hit_context) {
    std::shared_ptr<std::vector<Light> > light_sources = std::make_shared<std::vector<Light> >();
    float bias = 0.001f;
    for (Light light: lights)
    {
        Vector3df towards_light = light.getPosition() - hit_context.intersection_point;
        towards_light.normalize();
        Ray3df shadow_ray(hit_context.intersection_point + bias * hit_context.normal, towards_light);
        std::shared_ptr<HitContext> shadow_hit_context = find_nearest_object(shadow_ray, 0.001f);
        bool vis = shadow_hit_context == nullptr || shadow_hit_context->t > (light.getPosition() - hit_context.intersection_point).length();
        if (vis)
        {
            light_sources->push_back(light);
        }
    }
    return light_sources;
}

void Scene::initialize()
{
    // walls
    Sphere3df white_back_wall_sphere = {{0.0, 0.0, -310.0}, 300.0};
    Hittable white_back_wall(GRAY, white_back_wall_sphere);
    objects.push_back(white_back_wall);

    Sphere3df white_floor_sphere = {{0.0, -303.0, -1.0}, 300};
    Hittable white_floor(MATTE_WHITE, white_floor_sphere);
    objects.push_back(white_floor);

    Sphere3df green_right_wall_sphere = {{306.0, -1.0, -4.0}, 300.0};
    Hittable green_right_wall(MATTE_GREEN, green_right_wall_sphere);
    objects.push_back(green_right_wall);

    Sphere3df red_left_wall_sphere = {{-308.0, -1.0, -4.0}, 300.0};
    Hittable red_left_wall(MATTE_RED, red_left_wall_sphere);
    objects.push_back(red_left_wall);

    Sphere3df gray_ceiling_sphere = {{0.0, 307.0, -1.0}, 300.0};
    Hittable gray_ceiling(WHITE, gray_ceiling_sphere);
    objects.push_back(gray_ceiling);

    // spheres
    Sphere3df blue_sphere_sphere = {{-4.0, -1.0, -2.5}, 2.0};
    Hittable blue_sphere(MATTE_BLUE, blue_sphere_sphere);
    objects.push_back(blue_sphere);

    Sphere3df white_sphere_sphere = {{-1.5, -1.0, -8.0}, 2.0};
    Hittable white_sphere(MATTE_RED, white_sphere_sphere);
    objects.push_back(white_sphere);

    Sphere3df reflective_sphere_sphere = {{3.5, -1.0, -5.0}, 2.0};
    Hittable reflective_sphere(REFLECTIVE_WHITE, reflective_sphere_sphere);
    objects.push_back(reflective_sphere);


    lights.push_back(Light(Vector3df{0.0, 10.0, 0.0}, Color{1,1,1}));
    lights.push_back(Light(Vector3df{2.0, 5.0, -7.0}, Color{1,1,1}));

}


