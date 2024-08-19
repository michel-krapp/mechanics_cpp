//
// Created by mbk on 23/07/2024.
//

#include <iomanip>
#include <limits>
#include "motionuserinput.h"
#include "motion.h"


MotionUserInput::MotionUserInput() {
    for(const auto& label : {"x0", "v0", "a", "t1"}){
        in_.emplace_back(label, 0);
    }
    for(const auto& label : {"x", "v", "s", "vbar"}){
        out_.emplace_back(label,0);
    }
}

double MotionUserInput::read(std::string &label) {
    double val;
    std::cout << label << "?\t";
    std::cin >> val;
    if(std::cin.fail()){
        throw std::invalid_argument(label);
    }
    return val;
}

void MotionUserInput::calculate() {
    Motion motion{ 1, in_[Idx::a].second,
                   {in_[Idx::x0].second, in_[Idx::v0].second }} ;

    double t1 = in_[Idx::time].second;
    out_[0].second = motion.x(t1);
    out_[1].second = motion.v(t1);
    out_[2].second = motion.distance(t1);
    out_[3].second = motion.vmean(t1);
}

void MotionUserInput::input() {
    for (auto& vals: in_){
        vals.second = read(vals.first);
    }
    if(in_.back().second <= 0){
        throw std::domain_error("Time muse be >0");
    }
}

void MotionUserInput::output() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-------------output-----------" << std::endl;
    for(const auto& [label, val]: out_){
        std::cout << label << "=" << val << std::setw(3) << "\t";
    }
    std::cout << std::endl;
}

void MotionUserInput::ui() {
    constexpr auto maxstreamsize=
            std::numeric_limits<std::streamsize>::max();
    try {
        input();
        calculate();
        output();
    }catch (std::domain_error& ex1){
        std::cin.clear();
        std::cin.ignore(maxstreamsize);
        std::cerr << "input error: " << ex1.what() << std::endl;
    }catch (std::invalid_argument& ex2){
        std::cin.clear();
        std::cin.ignore(maxstreamsize);
        std::cerr << "input error: " << ex2.what() << std::endl;
    }
}

void MotionUserInput::run() {
    char cmd = 'y';
    std::cout << "--------------input-------------" << std::endl;
    while (cmd == 'y'){
        ui();
        do{
            std::cout << "new calulation? y[yes] / n[no]" << std::endl;
            std::cin >> cmd;
        }while(cmd != 'y' && cmd != 'n');
    }
}

