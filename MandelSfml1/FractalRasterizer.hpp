//
//  FractalRasterizer.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/13/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalRasterizer_hpp
#define FractalRasterizer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "FractalPanel.hpp"

class FractalRasterizer {
public:
    FractalPanel fractPanel;
    FractalRasterizer();
    void drawTo1DArray(sf::Uint8 (&drawTo)[262144]);
    void updatePalette();
    int colorFromPalette(float index);
};


#endif /* FractalRasterizer_hpp */
