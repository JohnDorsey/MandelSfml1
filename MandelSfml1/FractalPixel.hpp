//
//  FractalPixel.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalPixel_hpp
#define FractalPixel_hpp

#include <stdio.h>
#include "MathPoint.hpp"
#include "FractalPanel.cpp"

class FractalPixel {
public:
    FractalPixel();
    FractalPixel(FractalPanel const &nParentPanel);
    float getPalette();
};

#endif /* FractalPixel_hpp */
