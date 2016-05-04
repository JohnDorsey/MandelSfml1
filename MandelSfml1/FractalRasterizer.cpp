//
//  FractalRasterizer.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/13/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalRasterizer.hpp"

float paletteArray[256][256];

FractalRasterizer::FractalRasterizer() {
};


void FractalRasterizer::drawTo1DArray(sf::Uint8 (&drawTo)[262144]) {
    updatePalette();
    for (int i = 0; i < 256; i++) {
        //printf("%i\n", i);
        for (int ii = 0; ii < 256; ii++) {
            //printf("    %i\n", ii);
            //drawTo[(ii * 256) + i] = colorFromPalette(paletteArray[i][ii]);
            std::vector<sf::Uint8> drawNow = colorFromPalette(paletteArray[i][ii]);
            drawTo[(((i * 256) + ii) * 4)] = drawNow[0];
            drawTo[(((i * 256) + ii) * 4) + 1] = drawNow[1];
            drawTo[(((i * 256) + ii) * 4) + 2] = drawNow[2];
            drawTo[(((i * 256) + ii) * 4) + 3] = drawNow[3];
        }
    }
};


void FractalRasterizer::recieveNewArray(float (&inputArray)[256][256]) {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            paletteArray[i][ii] = inputArray[i][ii];
        }
    }
};


void FractalRasterizer::updatePalette() {
    fractPanel.drawToPaletteArray(paletteArray); //get pallete indices
};




std::vector<sf::Uint8> FractalRasterizer::colorFromPalette(float index) {
    return (std::vector<sf::Uint8>) { (sf::Uint8) partFromPalette(index), (sf::Uint8) partFromPalette(index), (sf::Uint8) partFromPalette(index), (sf::Uint8) partFromPalette(index) };
};


int FractalRasterizer::partFromPalette(float index) {
    return (int) index * 65793;
};



void FractalRasterizer::dbgFillCorner() {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            if (i - ii < 32) {
                paletteArray[i][ii] = 255.0f;
            }
        }
    }
    
};