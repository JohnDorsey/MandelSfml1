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

class FractalPixel;
class FractalArray;
//#include "Sequence2.hpp"
//#include "Sequence.hpp"

class FractalPanel {
public:
    
    float zoom = 0.25;
    //FractalArray* publicPixels;
    //FractalOrganizer inx;
    FractalPanel();
    void dbgSet(int i, int ii, int value);
//    Sequence2 seqseq0;
//    Sequence2 seqseq1;
    void populate();
    void arrange();
//    void populateSequences();
    void drawToPaletteArray(float (&drawTo)[256][256]);
    void solveAll();
    void solvei(int iToSolve);
    std::vector<float> whatsMyri(std::vector<float> chxy);
    float whatsMyr(float chx);
    float whatsMyi(float chy);
    
    void dah();
};

#endif /* FractalPanel_hpp */
