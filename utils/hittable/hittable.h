//
// Created by mateo on 12/9/24.
//

#ifndef HITTABLE_H
#define HITTABLE_H
#include <geometry/geometry.h>
#include <utils/math/math.h>

#include "utils/material/material.h"


class Hittable {
public:
    Material material; // Material properties of the object
    Sphere3df sphere; // Geometric representation (e.g., a sphere)

    // Constructor to initialize the Hittable object
    Hittable(const Material &material, const Sphere3df &sphere)
        : material(material), sphere(sphere) {
    }
};

class HitContext {
public:
    float t;
    Vector3df intersection_point;
    Vector3df normal;
    Hittable &hittable;
    bool front_face;

    HitContext(float t, Ray3df &ray, Hittable &hittable)
        : t(t),
          intersection_point(ray.origin + t * ray.direction), // Calculate intersection point
          normal(intersection_point - hittable.sphere.center), // Calculate outwards normal
          hittable(hittable) {
        normal.normalize(); // Normalize the normal vector
        front_face = ray.direction * normal < 0.0f; // Check if it's a front face hit
        normal = front_face ? normal : -1.0f * normal; // Flip normal if it's a back face hit
    }
};

#endif //HITTABLE_H
