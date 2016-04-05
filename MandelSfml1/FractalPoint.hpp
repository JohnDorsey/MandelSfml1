//
//  FractalPoint.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/5/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalPoint_hpp
#define FractalPoint_hpp

#include <stdio.h>
#include "vector"
#include <cmath>

class FractalPoint {
public:
    FractalPoint(float r, float i);
    void solve();
    void iter();
};

#endif /* FractalPoint_hpp */
