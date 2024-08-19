//
// Created by miche on 17/07/2024.
//

#include "pendulum.h"

Pendulum::Pendulum(double l, double m) : length_{l}, mass_{m}{
    if (l <= 0 || m <= 0){
        throw std::domain_error(__func__ );
    }
}

double Pendulum::length() const {
    return length_;
}

double Pendulum::mass() const {
    return mass_;
}

