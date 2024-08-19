//
// Created by miche on 23/07/2024.
//

#include <stdexcept>
#include <cmath>
#include <numeric>
#include "righttriangle.h"

RightTriangle::RightTriangle(double a, double b) {
    if(a <= 0 || b <= 0){
        throw std::domain_error(__func__ );
    }
    double c = std::hypot(a, b);
    sides_ = {a, b, c};
    angles_ = {asin(a/c), asin(b/c), 0.5 * M_PI};
    area_ = 0.5 * a * b;
    perimeter_ = std::accumulate(std::begin(sides_),
                          std::end(sides_),
                          0.0);
}

const auto &RightTriangle::sides() const {
    return sides_;
}

const auto &RightTriangle::angles() const {
    return angles_;
}

const auto &RightTriangle::side(Idx idx) const {
    return sides_.at(idx);
}

const auto &RightTriangle::angle(Idx idx) const {
    return angles_.at(idx);
}

const auto &RightTriangle::area() const {
    return area_;
}

const auto &RightTriangle::perimeter() const {
    return perimeter_;
}
