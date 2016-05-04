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
//#include "Sequence2.hpp"
//#include "Sequence.hpp"

class FractalPanel {
public:
    
    FractalOrganizer inx;
    FractalPanel();
    void dbgSet(int i, int ii, int value);
//    Sequence2 seqseq0;
//    Sequence2 seqseq1;
    void populate();
//    void populateSequences();
    void drawToPaletteArray(float (&drawTo)[256][256]);
    void solveAll();
    std::vector<float> whatsMyri(std::vector<float> chxy);
};

#endif /* FractalPanel_hpp */
