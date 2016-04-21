//
//  FractalPanel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/7/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPanel.hpp"

//float travel = 4;
//const int startRes = 256;
float x = 0.0f;
float y = 0.0f;
//const FractalPanel &myself;

FractalPixel pixels[256][256];

FractalPanel::FractalPanel() {
    populate();
};

void FractalPanel::populate() {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            //pixels[i][ii] = FractalPixel(this, i * ii);
            pixels[i][ii] = FractalPixel(this);
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            pixels[i][ii].startAt(std::vector<float> {(float) i, (float) ii});
        }
    }
    solveAll();
};

void FractalPanel::solveAll() {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            printf("%s %i %i", "\nsolveAll:", i, ii);
            pixels[i][ii].solve();
            //pixels[i][ii].dbgPrintUniq();
        }
    }
};

void FractalPanel::drawToPaletteArray(float (&drawTo)[256][256]) {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            drawTo[i][ii] = pixels[i][ii].getPalette();
            printf("%f", drawTo[i][ii]);
        }
    }
};

std::vector<float> FractalPanel::whatsMyri(std::vector<float> chxy) {
    return std::vector<float> { (((chxy[0] / 256) - 0.5f) * 4) + x, (((chxy[1] / 256) - 0.5f) * 4) + y };
};