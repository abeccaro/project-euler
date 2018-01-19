//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM1_HPP
#define PROJECT_EULER_PROBLEM1_HPP


using uint = unsigned int;

namespace problems {

    class problem1 {
    public:
        static uint solve(uint = 1000);

    private:
        static uint multiplesSum(uint, uint);
    };
}


#endif //PROJECT_EULER_PROBLEM1_HPP
