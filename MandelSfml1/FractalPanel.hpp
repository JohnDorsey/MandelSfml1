//
//  FractalPanel.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/7/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalPanel_hpp
#define FractalPanel_hpp

#include <stdio.h>
#include "vector"
#include "FractalOrganizer.hpp"
#include "FractalOrderer.hpp"
class MovementAdvisor;

class FractalPixel;
class FractalArray;
//#include "Sequence2.hpp"
//#include "Sequence.hpp"

class FractalPanel {
public:
    
    float zoom = 0.25;
    float x = 0.0f;
    float y = 0.0f;
    //FractalArray* publicPixels;
    //FractalOrganizer inx;
    FractalPanel();
    void dbgSet(int i, int ii, int value);
    void populate();
    void arrange();
    void arrange(bool p);
    void drawToPaletteArray(float (&drawTo)[256][256]);
    void solveAll();
    void solvei(int iToSolve);
    void solveii(int iiToSolve);
    std::vector<float> whatsMyri(std::vector<float> chxy);
    float whatsMyr(float chx);
    float whatsMyi(float chy);
    
    void dah();
};

#endif /* FractalPanel_hpp */
