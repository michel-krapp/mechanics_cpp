//
// Created by miche on 17/07/2024.
//

#include <stdexcept>
#include <cmath>
#include <array>

#include "spring.h"

Spring::Spring(double k) : k_{ k } {
    if ( k <= 0 ){
        throw std::domain_error(__func__ );
    }
}

void Spring::set_elongation(double x) {
    elongation_ = x;
    force_ = -k_ * x;
    ePotential_ = 0.5 * k_ * std::pow(elongation_, 2);
}

double Spring::k() const {
    return k_;
}

double Spring::force() const {
    return force_;
}

double Spring::elongation() const {
    return elongation_;
}

double Spring::ePotential() const {
    return ePotential_;
}

auto Spring::values() const {
    return std::array{ elongation_, force_, ePotential_};
}
