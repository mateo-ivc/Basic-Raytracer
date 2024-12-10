//
// Created by mateo on 11/28/24.
//

#include "light.h"



Light::Light(Vector3df position, Color color) : position(position), color(color) {

}


Color Light::getColor() const {
    return color;
}

Vector3df Light::getPosition() const {
    return position;
}

