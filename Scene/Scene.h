//
// Created by mateo on 11/28/24.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include <memory>
#include "camera/camera.h"
#include "Scene/Light/Light.h"

class Scene {
public:
    // Konstruktor
    Scene(const Camera &camera);

    // Methode zum Hinzufügen von Objekten zur Szene
    void addObject(Sphere<float, 3> object);

    // Methode zum Hinzufügen von Lichtquellen zur Szene
    void addLight(const Light &light);

    // Methode zur Berechnung der Farbe eines Pixels

private:
    Camera camera; // Kamera der Szene
    std::vector<Sphere<float, 3>> spheres; // Objekte in der Szene
    std::vector<Light> lights;

};


#endif //RAYTRACER_SCENE_H
