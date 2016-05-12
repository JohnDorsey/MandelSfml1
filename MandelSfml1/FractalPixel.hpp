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
#include "vector"
#include "MathPoint.hpp"
class FractalPanel;

class FractalPixel {
public:
    //float dbgPositionPalette = 0.0f;
    MathPoint mathPt;
    float timesSolved = 0.0f;
    bool clueless;
    void dbgPrintUniq();
    FractalPanel* parentPanel;
    FractalPixel();
    FractalPixel(FractalPanel *nParentPanel);
    void solve();
    void startAt(std::vector<float> newxy);
    float getPalette();
};

#endif /* FractalPixel_hpp */
