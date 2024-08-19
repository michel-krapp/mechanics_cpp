//
// Created by miche on 23/07/2024.
//

#ifndef MECHANICS_CPP_RIGHTTRIANGLE_H
#define MECHANICS_CPP_RIGHTTRIANGLE_H


#include <vector>

enum Idx {a, b, c};
/**
 * @brief Class te represent a right triangle
 */
class RightTriangle {
private:
    double area_;
    double perimeter_;
    std::vector<double> sides_;
    std::vector<double> angles_;

public:
    /**
     * Right Triangle Constructor
     * @param a adjacent side
     * @param b opposite side
     */
    inline RightTriangle(double a, double b);
    [[nodiscard]] inline const auto& sides() const;
    [[nodiscard]] inline const auto& angles() const;
    [[nodiscard]] inline const auto& side(Idx idx) const;
    [[nodiscard]] inline const auto& angle(Idx idx) const;
    [[nodiscard]] inline const auto& area() const;
    [[nodiscard]] inline const auto& perimeter() const;

};


#endif //MECHANICS_CPP_RIGHTTRIANGLE_H
