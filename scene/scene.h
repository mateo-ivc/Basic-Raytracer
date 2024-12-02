//
// Created by mateo on 11/28/24.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <memory>
#include "camera/camera.h"
#include "scene/Light/light.h"

class Scene {
    std::vector<Sphere<float, 3>> spheres;
    std::vector<Light> lights;

public:

    void addObject(Sphere<float, 3> object);
    void addLight(const Light &light);



};


#endif //RAYTRACER_SCENE_H
