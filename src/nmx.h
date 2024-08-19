//
// Created by miche on 17/07/2024.
// Contains literals for conversion to SI
//

#ifndef MECHANICS_CPP_NMX_H
#define MECHANICS_CPP_NMX_H

#include <cmath>
#include <gsl/gsl_const_mksa.h>
#include <gsl/gsl_math.h>


namespace nmx{
    constexpr double operator"" _km(long double km){
        return static_cast<double>(km) * 1e3;
    }
    constexpr double operator "" _cm(long double cm){
        return static_cast<double>(cm) * 1e2;
    }
    constexpr double operator "" _mm(long double mm){
        return static_cast<double>(mm) * 1e-3;
    }
    constexpr double operator "" _deg(long double deg){
        return static_cast<double>(deg) * M_PI / 180;
    }
    constexpr double operator"" _g(long double g){
        return static_cast<double>(g) * 1e-3;
    }
    constexpr double operator"" _h(long double h){
        return static_cast<double>(h) * GSL_CONST_MKSA_HOUR;
    }
    constexpr double operator"" _min(long double min){
        return static_cast<double>(min) * GSL_CONST_MKSA_MINUTE;
    }

    struct Math{
        inline static constexpr double PI = M_PI;
        inline static constexpr double E = M_E;
        inline static double to_radians(double degrees) { return PI / 180 * degrees;}
        inline static double to_degree(double radians) { return 180 / PI * radians;}
        inline static bool is_zero(double x, double epsilon){
            return std::abs(x) < epsilon;
        }
        inline static int cmp(double x, double y, double epsilon){
            return gsl_fcmp(x, y, epsilon);
        }
        inline static int sign(double x){
            return GSL_SIGN(x);
        }
    }; //Math

    namespace gravitation{
        struct Astronomy{
            inline static double G{ GSL_CONST_MKSA_GRAVITATIONAL_CONSTANT };
        };

        struct Earth{
            inline static constexpr double g{ GSL_CONST_MKSA_GRAV_ACCEL };
            inline static constexpr double mass{ 5.977e24 };
            inline static constexpr double radius{ 6378.137_km };
        };
    }// namespace gravitation

    struct Mechanics{
         inline static double potential_energy(double mass, double height){
             return mass * gravitation::Earth::g * height;
         }
         inline static double kinetic_energy(double mass, double velocity){
             return 0.5 * mass * std::pow(velocity, 2);
         }
    };
} //namespace nmx

#endif //MECHANICS_CPP_NMX_H
