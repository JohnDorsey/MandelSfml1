//
//  MathPoint.cpp (formerly FractalPoint.cpp)
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//
//****************************************************
//
//  This class is responsible for all Fractal math.
//  it can only provide an iteration count. it makes no intelligent decisions.
//  changing the code in this class can change ONLY the output fractal shape.
//

#include "MathPoint.hpp"
#include <string>


float thresh = 4;

MathPoint::MathPoint() {
    moveTo(*new std::vector<float> {1.6f, 1.6f});
    //solve();
};

void MathPoint::moveTo(std::vector<float> newri) {
    thisPt = std::__1::vector<float, std::__1::allocator<float>>(5);
    thisPt = {newri[0], newri[1], newri[0], newri[1], 0};
    escaped = false;
    //std::printf(" %s %f %f", "MT", newri[0], newri[1]);
};

void MathPoint::solve() { //this is only for testing, points will be way smarter in the future.
    for (; thisPt[4] < 1024; ) {
        iter();
        if ((thisPt[0] * thisPt[0]) + (thisPt[1] * thisPt[1]) > 4) { escaped = true; break; }
    }
    //printf(escaped? "Esc" : "Tra");
};

void MathPoint::iter() {
    thisPt = { (thisPt[0] * thisPt[0]) - (thisPt[1] * thisPt[1]) + thisPt[2], (thisPt[0] * thisPt[1] * 2) + thisPt[3], thisPt[2], thisPt[3], thisPt[4] + 1 };
};

int MathPoint::getIters() {
    //return (int) ((thisPt[2] + thisPt[3]) * 30) + 128;
    return (escaped? (thisPt[4] * 8.0f) : 0.0f); //fix this later!
    //dbgPrintUniq();
    //return (thisPt[0] + thisPt[1] ) * 256;
    //printf("%f", srand(time()));
};

void MathPoint::dbgPrintUniq() {
    printf("%s%f%f%f%f%f%f", "Q", thisPt[0], thisPt[1], thisPt[2], thisPt[3], thisPt[4], (escaped? 3.14f : 6.28f));
    //printf("#");
};



