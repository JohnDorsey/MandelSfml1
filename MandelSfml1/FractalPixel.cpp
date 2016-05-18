//
//  FractalPixel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPixel.hpp"

#include "FractalPanel.hpp"


FractalPixel::FractalPixel() {
    
}

FractalPixel::FractalPixel(FractalPanel *nParentPanel) {
    parentPanel = nParentPanel;
};

void FractalPixel::startAt(std::vector<float> newxy) {
    //printf(" %s %f %f", " SA", newxy[0], newxy[1]);
    //dbgPositionPalette = (newxy[0]) * (newxy[1]);
    mathPt.moveTo(parentPanel -> whatsMyri(newxy));
    mathPt.escaped = false;
};

float FractalPixel::getPalette() {
    //return dbgPositionPalette;
    return (float) mathPt.getIters() + (0.2 * timesSolved); //expand on this as soon as references to neighbors are available!
};

void FractalPixel::solve() {
    mathPt.solve();
    timesSolved += 1;
};

void FractalPixel::dbgPrintUniq() {
    mathPt.dbgPrintUniq();
};