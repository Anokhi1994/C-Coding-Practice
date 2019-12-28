#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <numeric>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>
class Student{
    private:
        std::vector<int> scores;
     public:
        void input(); 
        int calculateTotalScore();

};

#endif
