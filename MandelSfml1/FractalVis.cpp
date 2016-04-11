//
//  FractalVis.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 3/3/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//


#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "FractalVis.hpp"


sf::Image frame;
//sf::Texture screen;
int itrCounts[256][256];
int itrCounts1D[65536];
sf::Uint8 itrCounts1DUint8[65536];


FractalVis::FractalVis() {
    frame.loadFromFile(resourcePath() + "cute_image.jpg");
};

void FractalVis::doFrame(sf::Texture& screen) {
    //fractPlane.drawTo1DArray(itrCounts1D);
    drawFrame(screen);
};


void FractalVis::drawFrame(sf::Texture& screen) {
    for (int i = 0; i < 65536; i++) { itrCounts1DUint8[i] = (sf::Uint8) itrCounts1D[i]; } //convert int array to sf::Uint8 array
    frame.create(256, 256, &(*itrCounts1DUint8));
    screen.loadFromImage(frame);
};

//
//void FractalVis::drawFrame(sf::Texture& drawingOn) {
//        frame.flipVertically();
//        drawingOn.update(frame);
//}

