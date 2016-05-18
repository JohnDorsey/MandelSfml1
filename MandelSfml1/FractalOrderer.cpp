//
//  FractalOrderer.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/16/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalOrderer.hpp"
#include <cmath>


void FractalOrderer::figureOrder(float actualCoords[256], float idealCoords[256]){
    
    int startingOrder[256]; for (int i = 0; i < 256; i++) { startingOrder[i] = i; } // starting order counts up from left to right.
    
    //float lastCoord = actualCoords[0];
    //for (int i = 0; i < 256; i++) {
    //
    //    lastCoord = actualCoords[i];
    //}
    
    for (int ideali = 0; ideali < 256; ideali++) {
        publicOrder[ideali] = closestTo(actualCoords, idealCoords[ideali]);
    }
    
    
};



int FractalOrderer::closestTo(float workingCoords[256], float targetCoord) {
    float lowDist = 65535;
    float distIndex = 0;
    for (int workingi = 0; workingi < 256; workingi++) {
        if (std::abs(workingCoords[workingi] - targetCoord) < lowDist * 0.99) {
            lowDist = std::abs(workingCoords[workingi] - targetCoord);
            distIndex = workingi;
        }
    }
    return distIndex;
};

void FractalOrderer::writeOrderTo(int *outsideOrder){
    for (int i = 0; i < 256; i++) {
        outsideOrder[i] = publicOrder[i];
    }
};