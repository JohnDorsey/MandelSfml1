//
//  FractalPanel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/7/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPanel.hpp"

float travel = 4;
float x = 0.0f;
float y = 0.0f;

FractalPanel::FractalPanel() {
    
};

std::vector<float> FractalPanel::whatsMyri(std::vector<float> chxy) {
    return std::vector<float> { ((chxy[0] - 0.5f) * travel) + x, ((chxy[1] - 0.5f) * travel) + y };
};