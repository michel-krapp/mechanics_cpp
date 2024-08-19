//
// Created by mbk on 18/08/2024.
//

#ifndef MECHANICS_CPP_CACHE_H
#define MECHANICS_CPP_CACHE_H

#include <map>
#include <functional>
#include <iostream>
#include <complex>
#include <chrono>
#include "nmx.h"

using namespace nmx;
/**
 * @brief Helper class to save function call results for
 * futher calculation (f.e. factorial)
 */
template<class X, class Y, bool DEBUG = false>
class Cache{
private:
    std::map<X, Y> table_; //map x <-> f(x)
    std::function<Y(X)> function_ptr_;

public:
    /**
     * @brief Cache constructor
     * @param fn function pointer
     */
     explicit Cache(Y (*fn)(X)) : function_ptr_{fn}{ }

     /**
      * @brief get returns value from map, if not yet in map it will be calculated
      * @param x variable
      * @return function value (y / f(x))
      */
     Y get(X x){
         const auto entry = table_.find(x);
         if (entry != table_.end()){
             if constexpr (DEBUG){
                 std:: cout << "from cache: ";
             }
             return entry->second;
         }
         Y val = function_ptr_(x); // calculate values
         table_[x] = val;
         return val;
     }

     auto size() const { return table_.size(); }

};

double fac(size_t n){
    if (n < 1000) {
        return n == 0 ? 1 : n * fac(n - 1);
    }
    return std::sqrt(2 * Math::PI * n) * std::pow(n / Math::E, n);
}

inline void ex1(){
    Cache<size_t, double> c1{fac };
    for (auto n : {2, 9, 50, 100, 2, 9}) {
        std::cout << n << "! = " << c1.get(static_cast<size_t>(n)) << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    Cache<size_t , double, true> c2{fac};
    for(auto n : {2, 9, 50, 100, 2, 9}) {
        std::cout << n << "! =" << c2.get(static_cast<size_t>(n)) << std::endl;
    }
}

inline void ex2(){

    Cache<size_t, double> c1{fac};

    const size_t N = 1e5;
    double sum1 = 0;
    auto start1 = std::chrono::steady_clock::now();
    for(size_t n = 0; n < N; n++){
        sum1 = 1 / c1.get(n);
    }
    auto end1 = std::chrono::steady_clock::now();
    auto difference1 = std::chrono::duration<double, std::milli>(end1 - start1).count();

    double sum2 = 0;
    auto start2 = std::chrono::steady_clock::now();
    for(size_t n = 0; n < N; n++){
        sum2 += 1 / c1.get(n);
    }
    auto end2 = std::chrono::steady_clock::now();
    auto difference2 = std::chrono::duration<double, std::milli>(end2 -start2).count();

    // Ausgabe der Ergebnisse auf dem Bildschirm
    std::cout << "dt1=" << difference1 << " ms" << std::endl;
    std::cout << "value=" << sum1 << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "dt2=" << difference2 << " ms" << std::endl;
    std::cout << "value=" << sum2 << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "dt2/dt1=" << difference2 / difference1 << std::endl;
    std::cout << "cache size=" << c1.size() << std::endl;
}

#endif //MECHANICS_CPP_CACHE_H
