//
// Created by mateo on 11/28/24.
//

#include "scene.h"



void Scene::addObject(Sphere<float, 3> object) {
    this->spheres.push_back(object);
}

void Scene::addLight(const Light &light) {
this->lights.push_back(light);
}



