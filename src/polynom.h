//
// Created by mbk on 23/07/2024.
//

#ifndef MECHANICS_CPP_POLYNOM_H
#define MECHANICS_CPP_POLYNOM_H

#include <cstddef>
#include <array>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_poly.h>
#include <ostream>

/**
 * @brief Class to represent a polynom
 * @param T Datatype of coefficients
 * @param N Degree of the Polynom
 */
template<typename T, size_t N>
class Polynom {
protected:
    std::array<T, N + 1> c_;
public:
    explicit Polynom(std::array<T, N + 1> clst){
        std::copy(std::begin(clst), std::end(clst), std::begin(c_));
    }

    T c(size_t idx){ return c_.at(idx);}

    auto eval(gsl_complex z) const{
        if constexpr (std::is_same_v<T, gsl_complex>){
            return gsl_complex_poly_complex_eval(c_.data(), N + 1, z);
        }else{
            return gsl_poly_complex_eval(c_.data(), N + 1, z);
        }
    }

    auto eval(double x) const{
        if constexpr (std::is_same_v<T, gsl_complex>) {
            return gsl_complex_poly_complex_eval(
                    c_.data(), N + 1, gsl_complex{x, 0});
        }else{
            return gsl_poly_eval(c_.data(), N + 1, x);
        }
    }

    template<class R>
    auto operator() (R x) const {
        return eval(x);
    }

    friend inline std::ostream& operator<<(std::ostream& os, const Polynom& p){
        os << "{" << p.c(0);
        for(size_t idx = 1; idx < p.c_.size(); idx++){
            os << "," << p.c_(idx);
        }
        return os << "}";
    }

    friend inline std::ostream& operator<<(std::ostream& os, const gsl_complex &c ){
        return os << "(" << GSL_REAL(c) << "," << GSL_IMAG(c) << ")";
    }

    inline constexpr size_t degree() const {
        return N;
    }

}; // Polynom

#endif //MECHANICS_CPP_POLYNOM_H
