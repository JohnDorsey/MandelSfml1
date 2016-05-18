//
//  FractalOrderer.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/16/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalOrderer_hpp
#define FractalOrderer_hpp

#include <stdio.h>

class FractalOrderer {
public:
    int publicOrder[256];
    void figureOrder(float actualCoords[256], float idealCoords[256]);
    int closestTo(float workingCoords[256], float targetCoord);
    void writeOrderTo(int *outsideOrder);
};

#endif /* FractalOrderer_hpp */
