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
//    FractalPanel fractPanel;
    FractalPanel* sourcePanel;
    FractalRasterizer();
    FractalRasterizer(FractalPanel *nSourcePanel);
    void drawTo1DArray(sf::Uint8 (&drawTo)[262144]);
    void updatePalette();
    std::vector<sf::Uint8> colorFromPalette(float index);
    int partFromPalette(float index);
    void dbgFillCorner();
};


#endif /* FractalRasterizer_hpp */
