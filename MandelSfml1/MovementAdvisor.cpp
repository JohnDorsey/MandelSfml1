//
//  MovementAdvisor.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "MovementAdvisor.hpp"


LaunchSelector launchSelect;
LandSelector landSelect;



void MovementAdvisor::writeInstructionsTo(float (&actualCoords)[256], float (&idealCoords)[256], std::vector<int> (&outsideInstructions)[256]) {
    int toLaunch[256];
    int toLand[256];
    launchSelect.selectSome(idealCoords, actualCoords, toLaunch);
    landSelect.selectSome(idealCoords, actualCoords, toLand);
    
    int writing;
    //int len = 0;
    //for (len = 0; len < 256; len++) {
    //    if (toLaunch[len] < 0 || toLand[len] < 0) { break; }
    //}
    for (writing = 0; writing < 256; writing++) {
        if (toLaunch[writing] < 0 || toLand[writing] < 0) { break; }
        outsideInstructions[writing] = {toLaunch[writing], toLand[writing]};
    }
    for (; writing < 256; writing++) {
        outsideInstructions[writing] = {-1, -1};
    }
    
};

void MovementAdvisor::writeInstructionsTo2(float (&actualCoords)[256], float (&idealCoords)[256], std::vector<int> (&outsideInstructions)[256]) {
    
};