//
//  FractalVis.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 3/3/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//


#ifndef FractalVis_hpp
#define FractalVis_hpp

#include <stdio.h>
#include "vector"
#include "FractalPanel.hpp"

class FractalVis { //identical
public:
    FractalVis(); //identical
    void doFrame(sf::Texture&);
    void drawFrame(sf::Texture&);
    //void drawFrame(sf::Texture&);
};

#endif /* FractalVis_hpp */
