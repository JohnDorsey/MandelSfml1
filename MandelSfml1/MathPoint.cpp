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


std::vector<float> thisPt;
float thresh = 4;
bool escaped;

MathPoint::MathPoint() {
    moveTo(*new std::vector<float> {0.0f, 0.0f});
};

void MathPoint::moveTo(std::vector<float> newri) {
    thisPt = std::__1::vector<float, std::__1::allocator<float>>(5);
    thisPt = {newri[0], newri[1], newri[0], newri[1], 0};
    escaped = false;
};

void MathPoint::solve() {
    for (; thisPt[4] < 32; ) {
        iter();
        if ((thisPt[0] * thisPt[0]) + (thisPt[1] * thisPt[1]) > thresh) { escaped = true; break; }
    }
};

void MathPoint::iter() {
    thisPt = { (thisPt[0] * thisPt[0]) - (thisPt[1] * thisPt[1]) + thisPt[2], (thisPt[0] * thisPt[1] * 2) + thisPt[3], thisPt[2], thisPt[3], thisPt[4] + 1 };
};

int MathPoint::getIters() {
    //return thisPt[4]; //fix this later!
    return (thisPt[0] + thisPt[1] + 2) * 64;
};



