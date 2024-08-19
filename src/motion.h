//
// Created by mbk on 23/07/2024.
//

#ifndef MECHANICS_CPP_MOTION_H
#define MECHANICS_CPP_MOTION_H


#include <array>

class Motion {
private:
    double mass_;
    double acceleration_;
    std::pair<double, double> ivalues_;
public:
    Motion(double m, double a, std::pair<double, double> init);
    [[nodiscard]] double x(double t) const;
    [[nodiscard]] double v(double t) const;
    [[nodiscard]] double distance(double t) const;
    [[nodiscard]] double vmean(double t) const;
    [[nodiscard]] double mass() const;
    [[nodiscard]] double acceleration() const;
    [[nodiscard]] const auto& init_values() const;

};


#endif //MECHANICS_CPP_MOTION_H
