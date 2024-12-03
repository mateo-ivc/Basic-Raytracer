//
// Created by mateo on 12/3/24.
//

#include "material.h"

Material::Material(Color color, float ambient, float diffuse, float reflection, float transmission)
        : color(color), ambient(ambient), diffuse(diffuse), reflection(reflection), transmission(transmission) {
    // Optionally, you could add validation here to ensure the sum of the properties is <= 1.0
}

Color Material::getColor() const {
    return color;
}

float Material::getAmbient() const {
    return ambient;
}

float Material::getDiffuse() const {
    return diffuse;
}

float Material::getReflection() const {
    return reflection;
}

float Material::getTransmission() const {
    return transmission;
}
