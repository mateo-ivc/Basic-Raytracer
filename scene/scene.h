//
// Created by mateo on 11/28/24.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <memory>
#include "scene/Light/light.h"
#include "utils/hittable/hittable.h"

class Scene {
public:
    std::vector<Hittable> objects;
    std::vector<Light> lights;

    void addObject(Hittable object);

    void addLight(const Light &light);

    std::shared_ptr<HitContext> find_nearest_object(Ray3df ray, float t_min = 0.0f, float t_max = INFINITY);
    std::shared_ptr<std::vector<Light>> find_light_soruces(HitContext &hit_context);

    void initialize();
};


#endif //RAYTRACER_SCENE_H
