//
// Created by miche on 17/07/2024.
//

#ifndef MECHANICS_CPP_RATIONAL_H
#define MECHANICS_CPP_RATIONAL_H


class Rational {
private:
    long long num_;
    long long den_;
public:
    explicit Rational(long long int n = 0, long long int d = 1);
    [[nodiscard]] auto num() const {
        return num_;
    }
    [[nodiscard]] auto den() const {
        return den_;
    }

    void simplify();

    explicit operator double() const;

    template<typename T>
    static constexpr bool is_int_like_v =
            (std::is_arithmetic_v<T> && std::is_integral_v<T>
            && !std::is_same_v<T, bool> && !std::is_same_v<T, char>);

    template<typename T>
    static constexpr bool is_rational_like_v = is_int_like_v<T> || std::is_same_v<T, Rational>;

    template<typename T, std::enable_if_t<is_rational_like_v<T>>* = nullptr>
    inline Rational& operator+=( const T& other) {
        if constexpr (is_int_like_v<T>){
            num_ = num_ + den_;
        } else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ = den_ * other.den_;
        }
        simplify();
        return *this;
    }

    template<typename T, std::enable_if_t<is_rational_like_v<T>>* = nullptr>
    inline Rational& operator-=(const T& other){
        if constexpr (is_int_like_v<T>){
            num_ = num_ - den_;
        } else{
            num_ = num_ * other.den_ - other.num_ * den_;
            den_ = den_ * other.den_;
        }
        simplify();
        return *this;
    }

    template<typename T, std::enable_if_t<is_rational_like_v<T>>* = nullptr>
    inline Rational& operator*=(const T& other){

        if constexpr (is_int_like_v<T>){
            num_ = num_ * other;
        }else{
            num_ = num_ * other.num_;
            den_ = den_ * other.den_;
        }
        simplify();
        return *this;
    }

};


#endif //MECHANICS_CPP_RATIONAL_H
