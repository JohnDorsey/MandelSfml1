//
//  LandSelector.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "LandSelector.hpp"
#include <cmath>


void LandSelector::selectSome(float idealCoords[256], float actualCoords[256], int (&outsideOrder)[256]) {
    int placeIndex = 0;
    float activeDistance;
    float width = idealCoords[255] - idealCoords[0];
    for (int pass = 2; pass < 256; pass++) { //decrease target width each time to get high priority items first
        for (int test = 0; test < 256; test++) {
            activeDistance = idealCoords[test] - actualCoords[closestTo(actualCoords, idealCoords[test])];
            //activeDistance = idealCoords[test] - idealCoords[test - 1]
            if (activeDistance > (width / (4 * pass)) && activeDistance < (width / (4 * (pass-1)))) {
                outsideOrder[placeIndex++] = test;
            }
        }
    }
    for (; placeIndex < 256; placeIndex++) {
        outsideOrder[placeIndex] = -1;
    }
};


int LandSelector::closestTo(float workingCoords[256], float targetCoord) {
    float lowDist = 65535;
    float distIndex = 0;
    for (int workingi = 0; workingi < 256; workingi++) {
        if (std::abs(workingCoords[workingi] - targetCoord) < lowDist * 0.999) {
            lowDist = std::abs(workingCoords[workingi] - targetCoord);
            distIndex = workingi;
        }
    }
    return distIndex;
};