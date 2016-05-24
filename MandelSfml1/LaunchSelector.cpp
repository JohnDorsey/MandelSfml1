//
//  LaunchSelector.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "LaunchSelector.hpp"



void LaunchSelector::selectSome(float (&idealCoords)[256], float (&actualCoords)[256], int (&outsideOrder)[256]) {
    int placeIndex = 0;
    for (int test = 0; test < 256; test++) {
        if (actualCoords[test] < idealCoords[0] || actualCoords[test] > idealCoords[255]) {
            outsideOrder[placeIndex++] = test;
        }
    }
    if (placeIndex > 64) { printf("%s%i%s", "something big just went down; LaunchSelector selects ", placeIndex, " items to launch\n"); }
    for (; placeIndex < 256; placeIndex++) {
        outsideOrder[placeIndex] = -1;
    }
};