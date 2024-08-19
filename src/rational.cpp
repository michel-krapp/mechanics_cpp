//
// Created by miche on 17/07/2024.
//

#include <stdexcept>
#include <numeric>
#include "rational.h"


void Rational::simplify() {
    long gcd = std::gcd(num_, den_);
    num_ /= gcd;
    den_ /= gcd;
}

Rational::operator double() const{
        return static_cast<double>(num_) / static_cast<double>(den_);
    }

Rational::Rational(long long int n, long long int d) : num_{n}, den_{d} {
    if (d == 0){
        throw std::domain_error(__func__);
    }
    if (d < 0) {
        num_ *= -1;
        den_ *= -1;
    }
}

