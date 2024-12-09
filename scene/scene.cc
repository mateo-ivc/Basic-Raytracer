//
// Created by mateo on 11/28/24.
//

#include "scene.h"

Scene::Scene() = default;


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




