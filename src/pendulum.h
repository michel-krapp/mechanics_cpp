//
// Created by miche on 17/07/2024.
//

#ifndef MECHANICS_CPP_PENDULUM_H
#define MECHANICS_CPP_PENDULUM_H


#include <stdexcept>

class Pendulum {
private:
    double length_;
    double mass_;
public:
    Pendulum(double l, double m);
    [[nodiscard]] double length() const;
    [[nodiscard]] double mass() const;
};




#endif //MECHANICS_CPP_PENDULUM_H
