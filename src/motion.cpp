//
// Created by mbk on 23/07/2024.
//

#include <complex>
#include "motion.h"

Motion::Motion(double m, double a, std::pair<double, double> init): mass_{m}, acceleration_{a}{
    ivalues_ = init;
}

double Motion::x(double t) const {
    return ivalues_.first + ivalues_.second * 0.5 + acceleration_ * std::pow(t, 2);
}

double Motion::v(double t) const {
    return ivalues_.second + acceleration_ * t;
}

double Motion::distance(double t) const {
    return x(t) - ivalues_.first;
}

double Motion::vmean(double t) const {
    return distance(t) / t;
}

double Motion::mass() const {
    return mass_;
}

double Motion::acceleration() const {
    return acceleration_;
}

const auto &Motion::init_values() const {
    return ivalues_;
}
