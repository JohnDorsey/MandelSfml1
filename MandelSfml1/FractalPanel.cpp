//
//  FractalPanel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/7/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPanel.hpp"

float travel = 4;
const int startRes = 256;
float x = 0.0f;
float y = 0.0f;

FractalPixel pixels[startRes][startRes];

FractalPanel::FractalPanel() {
    
};

void FractalPanel::populate() {
    for (int i = 0; i < startRes; i++) {
        for (int ii = 0; ii < startRes; i++) {
            pixels[i][ii] = new FractalPixel(&this);
        }
    }
};

std::vector<float> FractalPanel::whatsMyri(std::vector<float> chxy) {
    return std::vector<float> { ((chxy[0] - 0.5f) * travel) + x, ((chxy[1] - 0.5f) * travel) + y };
};