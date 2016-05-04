//
//  FractalOrganizer.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/4/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalOrganizer.hpp"
#include "FractalPanel.hpp"


FractalOrganizer::FractalOrganizer() {
    reset();
};

FractalOrganizer::FractalOrganizer(FractalPanel *nParentPanel) {
    parentPanel = nParentPanel;
};

void FractalOrganizer::reset() {
    for (int i = 0; i < iOrder.size(); i++) {
        iOrder[i] = i;
    }
    for (int ii = 0; ii < iiOrder.size(); ii++) {
        iiOrder[ii] = ii;
    }
    iiOrder[95] = 0;
    iiOrder[96] = 0;
};

int FractalOrganizer::i(int fi) {
    return iOrder[fi];
};

int FractalOrganizer::ii(int fii) {
    return iiOrder[fii];
};

void FractalOrganizer::inci(int amount) {
    for (int i = 0; i < iOrder.size(); i++) {
        iOrder[i] += amount;
        iOrder[i] %= iOrder.size();
        //printf(" %i", iOrder[i]);
    }
    //printf("###########################");
};

void FractalOrganizer::incii(int amount) {
    for (int ii = 0; ii < iiOrder.size(); ii++) {
        iiOrder[ii] += amount;
        iiOrder[ii] %= iiOrder.size();
    }
};



