//
//  MovementAdvisor.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef MovementAdvisor_hpp
#define MovementAdvisor_hpp

#include <stdio.h>
#include "vector"
#include "LaunchSelector.hpp"
#include "LandSelector.hpp"


class MovementAdvisor {
public:
    std::vector<int> publicInstructions;
    void writeInstructionsTo(float (&actualCoords)[256], float (&idealCoords)[256], std::vector<int> (&outsideInstructions)[256]);
    void writeInstructionsTo2(float (&actualCoords)[256], float (&idealCoords)[256], std::vector<int> (&outsideInstructions)[256]);
};

#endif /* MovementAdvisor_hpp */
