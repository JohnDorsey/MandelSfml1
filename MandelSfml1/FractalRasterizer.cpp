//
//  FractalRasterizer.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/13/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalRasterizer.hpp"

FractalPanel fractPanel;
float paletteArray[256][256];

FractalRasterizer::FractalRasterizer() {
};


void FractalRasterizer::drawTo1DArray(sf::Uint8 (&drawTo)[65536]) {
    updatePalette();
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            drawTo[(i * 256) + ii] = colorFromPalette(paletteArray[i][ii]);
        }
    }
};

void FractalRasterizer::updatePalette() {
    fractPanel.drawToPaletteArray(paletteArray);
};

int FractalRasterizer::colorFromPalette(float index) {
    return (int) index * 65793;
};