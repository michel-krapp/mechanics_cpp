//
// Created by mbk on 23/07/2024.
//

#ifndef MECHANICS_CPP_MOTIONUSERINPUT_H
#define MECHANICS_CPP_MOTIONUSERINPUT_H


#include <utility>
#include <string>
#include <vector>
#include <iostream>

class MotionUserInput {
    using Value = std::pair<std::string, double>;

    enum Idx { x0, v0, a, time };

private:
    std::vector<Value> in_;
    std::vector<Value> out_;
protected:
    double read(std::string& label);
public:
    MotionUserInput();
    void calculate();
    void input();
    void output();
    void ui();
    void run();

};


#endif //MECHANICS_CPP_MOTIONUSERINPUT_H
