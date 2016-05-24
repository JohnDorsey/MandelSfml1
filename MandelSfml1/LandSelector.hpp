//
//  LandSelector.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef LandSelector_hpp
#define LandSelector_hpp

#include <stdio.h>

class LandSelector {
public:

    void selectSome(float idealCoords[256], float actualCoords[256], int (&outsideOrder)[256]);
    int closestTo(float workingCoords[256], float targetCoord);
    
};

#endif /* LandSelector_hpp */
