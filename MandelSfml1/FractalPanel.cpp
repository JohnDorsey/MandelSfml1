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
//const FractalPanel &myself;

FractalPixel pixels[startRes][startRes];

FractalPanel::FractalPanel() {
    populate();
};

void FractalPanel::populate() {
    for (int i = 0; i < startRes; i++) {
        for (int ii = 0; ii < startRes; i++) {
//            pixels[i][ii] = *new FractalPixel(this);
            pixels[i][ii] = *new FractalPixel();
        }
    }
    for (int i = 0; i < startRes; i++) {
        for (int ii = 0; ii < startRes; i++) {
            pixels[i][ii].startAt(std::vector<float> {(float) i, (float) ii});
        }
    }
};

void FractalPanel::drawToPaletteArray(float (&drawTo)[256][256]) {
    for (int i = 0; i < startRes; i++) {
        for (int ii = 0; ii < startRes; ii++) {
            drawTo[i][ii] = pixels[i][ii].getPalette();
        }
    }
};

std::vector<float> FractalPanel::whatsMyri(std::vector<float> chxy) {
    return std::vector<float> { ((chxy[0] - 0.5f) * travel) + x, ((chxy[1] - 0.5f) * travel) + y };
};