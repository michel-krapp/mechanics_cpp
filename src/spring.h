//
// Created by miche on 17/07/2024.
//

#ifndef MECHANICS_CPP_SPRING_H
#define MECHANICS_CPP_SPRING_H


class Spring {
private:
    double k_;
    double elongation_;
    double force_{ 0 };
    double ePotential_{0 };
public:
    explicit Spring(double k);
    void set_elongation(double x);
    [[nodiscard]] double k() const;
    [[nodiscard]] double force() const;
    [[nodiscard]] double elongation() const;
    [[nodiscard]] double ePotential() const;
    auto values() const;
};

inline static Spring add_parallel(const Spring& s1, const Spring& s2){
    double k = s1.k() + s2.k();
    return Spring{ k };
}

inline static Spring add_series(const Spring& s1, const Spring& s2){
    double tmp = 1. / s1.k() + 1. / s2.k();
    return Spring { 1. / tmp};
}

#endif //MECHANICS_CPP_SPRING_H
