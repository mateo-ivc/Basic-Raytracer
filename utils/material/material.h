//
// Created by mateo on 12/3/24.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


// Assuming Color is defined in Color.h

#include "utils/color/color.h"

class Material {
private:
    Color color;            // Color of the material
    float ambient;         // Ambient light contribution (percent)
    float diffuse;         // Diffuse light contribution (percent)
    float reflection;      // Reflection contribution (percent)
    float transmission;     // Transmission contribution (percent)

    // Sum of all four should be <= 1.0

public:
    Material(Color color = Color(1.0, 0.7, 0.8),
             float ambient = 0.3,
             float diffuse = 0.7,
             float reflection = 0.0,
             float transmission = 0.0);

    // Getters
    Color getColor() const;

    float getAmbient() const;

    float getDiffuse() const;

    float getReflection() const;

    float getTransmission() const;
};

#endif // RAYTRACER_MATERIAL_H