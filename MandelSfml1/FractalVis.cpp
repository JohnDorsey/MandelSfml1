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

#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Color.hpp>

sf::Image frame;
//sf::Texture screen;
//int itrCounts[256][256];
//int itrCounts1D[65536];
sf::Uint8 colors1DUint8[262144];

//FractalPanel fractPanel;


FractalVis::FractalVis() {
    //frame.loadFromFile(resourcePath() + "cute_image.jpg");
};


void FractalVis::doFrame(sf::Texture& screen) {
    //fractPlane.drawTo1DArray(itrCounts1D);
    fractRast.drawTo1DArray(colors1DUint8); //update Uint8 array of display
    drawFrame(screen); //display the new frame
};


void FractalVis::drawFrame(sf::Texture& screen) {
    frame.create(256, 256, &(*colors1DUint8)); //set the Image frame to the known display array
    frame.setPixel(128, 128, sf::Color::Yellow); //put a dot in the center
    screen.loadFromImage(frame); //display the image
};


//
//void FractalVis::drawFrame(sf::Texture& drawingOn) {
//        frame.flipVertically();
//        drawingOn.update(frame);
//}

