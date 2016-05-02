//
//  Sequence.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/26/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include <stdio.h>
//#include "FractalPixel.hpp"

class FractalPixel;

class Sequence {
public:
    Sequence();
    int type = 0;
    FractalPixel *refs[256];
};

#endif /* Sequence_hpp */
