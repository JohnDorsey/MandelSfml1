//
//  FractalArray.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/6/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalArray_hpp
#define FractalArray_hpp

#include <stdio.h>
#include "FractalOrganizer.hpp"
class FractalPanel;
class FractalPixel;

class FractalArray {
public:
    FractalOrganizer inx;
    FractalPanel* parentPanel;
    FractalArray();
    FractalArray(FractalPanel *nParentPanel);
    FractalPixel* get(int i, int ii);
};


#endif /* FractalArray_hpp */
