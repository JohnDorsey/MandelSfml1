//
//  MathPoint.hpp (formerly FractalPoint.hpp)
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef MathPoint_hpp
#define MathPoint_hpp

#include <stdio.h>
#include "vector"
#include <cmath>
#include <ctime>

class MathPoint {
public:
    std::vector<float> thisPt;
    MathPoint();
    void moveTo(std::vector<float> newri);
    void solve();
    void iter();
    int getIters();
    void dbgPrintUniq();
};

#endif /* MathPoint_hpp */
