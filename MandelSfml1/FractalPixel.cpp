//
//  FractalPixel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPixel.hpp"

MathPoint mathPt;
FractalPanel* parentPanel;

FractalPixel::FractalPixel(FractalPanel &nParentPanel) {
    parentPanel = &nParentPanel;
};

void startAt(std::vector<float> newxy) {
    mathPt.moveTo(parentPanel -> whatsMyri(newxy));
};

float getPalette() {
    return (float) mathPt.getIters(); //expand on this as soon as references to neighbors are available!
};