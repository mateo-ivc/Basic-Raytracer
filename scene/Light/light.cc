//
// Created by mateo on 11/28/24.
//

#include "light.h"


Light::Light(Vector3df position = Vector3df({0.0, 0.0, 1000.0}),Color color = Color(1.0, 1.0, 1.0)): position(position), color(color) {
}


Color Light::getColor() const {
    return color;
}

Vector3df Light::getPosition() const {
    return position;
}
