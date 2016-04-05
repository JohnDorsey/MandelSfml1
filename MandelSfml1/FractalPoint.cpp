//
//  FractalPoint.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPoint.hpp"


std::vector<float> thisPt;
float thresh;
bool escaped;

FractalPoint::FractalPoint(float r, float i) {
    thisPt = std::__1::vector<float, std::__1::allocator<float>>(5);
    thisPt = {r, i, r, i, 0};
    escaped = false;
};

void FractalPoint::solve() {
    for (; thisPt[4] < 32; ) {
        iter();
        if ((thisPt[0] * thisPt[0]) + (thisPt[1] * thisPt[1]) > thresh) { escaped = true; break; }
    }
};

void FractalPoint::iter() {
    thisPt = { (thisPt[0] * thisPt[0]) - (thisPt[1] * thisPt[1]) + thisPt[2], (thisPt[0] * thisPt[1] * 2) + thisPt[3], thisPt[2], thisPt[3], thisPt[4] + 1 };
};



