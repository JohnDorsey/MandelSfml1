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
    printf("Creating a FractalOrganizer with no arguments.\n");
    reset();
};

FractalOrganizer::FractalOrganizer(FractalPanel *nParentPanel) {
    printf("%s%p%s", "Creating a FractalOrganizer with parentPanel at memory adress ", nParentPanel, "\n");
    parentPanel = nParentPanel;
};

void FractalOrganizer::reset() {
    for (int i = 0; i < iOrder.size(); i++) {
        iOrder[i] = i;
    }
    for (int ii = 0; ii < iiOrder.size(); ii++) {
        iiOrder[ii] = ii;
    }
};

int FractalOrganizer::i(int fi) {
    return iOrder[fi];
};

int FractalOrganizer::ii(int fii) {
    return iiOrder[fii];
};


void FractalOrganizer::movei(int starti, int endi) {
    if (starti < 0 || endi > 255) {
        printf("%s%i%s%i%s", "movei: NO!!:", starti, ", ", endi, "\n"); return;
    } else {
        printf("%s%i%s%i%s", "movei: okay:", starti, ", ", endi, "\n");
    }
    
    int tempi;
    if (starti < endi) {
        //printf("%s %i %s %i%s", "FractalOrganizer::movei: moving", starti, "to", endi, "\n");
        tempi = iOrder[starti];
        for (int ati = starti; ati < endi; ati++) {
            iOrder[ati] = iOrder[ati+1];
        }
        iOrder[endi] = tempi;
    } else if (starti > endi) {
        tempi = iOrder[starti];
        for (int ati = starti; ati > endi; ati--) {
            iOrder[ati] = iOrder[ati-1];
        }
        iOrder[endi] = tempi;
        //printf("FractalOrganizer::movei not done yet!");
    } else {
        printf("%s%i%s", "FractalOrganizer::movei was asked to move ", starti, " to its current location, that shouldn't really ever happen");
    }
    //for (int ati = 0; ati < 64; ati++) { printf(" %i", iOrder[ati]); } printf("\n############\n");
};

void FractalOrganizer::moveii(int startii, int endii) {
    
    if (startii < 0 || endii > 255) {
        printf("%s%i%s%i%s", "moveii: NO!!:", startii, ", ", endii, "\n"); return;
    } else {
        printf("%s%i%s%i%s", "moveii: okay:", startii, ", ", endii, "\n");
    }
    
    int tempii;
    if (startii < endii) {
        //printf("%s %i %s %i%s", "FractalOrganizer::movei: moving", starti, "to", endi, "\n");
        tempii = iiOrder[startii];
        for (int atii = startii; atii < endii; atii++) {
            iiOrder[atii] = iiOrder[atii+1];
        }
        iiOrder[endii] = tempii;
    } else if (startii > endii) {
        tempii = iiOrder[startii];
        for (int atii = startii; atii > endii; atii--) {
            iiOrder[atii] = iiOrder[atii-1];
        }
        iiOrder[endii] = tempii;
        //printf("FractalOrganizer::moveii not done yet!");
    } else {
        printf("%s%i%s", "FractalOrganizer::moveii was asked to move ", startii, " to its current location, that shouldn't really ever happen");
    }

};


void FractalOrganizer::swapi(int first, int second) {
    int temp = iOrder[first];
    iOrder[first] = iOrder[second];
    iOrder[second] = temp;
};





void FractalOrganizer::inci(int amount) { for (int i = 0; i < iOrder.size(); i++) { iOrder[i] += amount; iOrder[i] %= iOrder.size(); } };
void FractalOrganizer::incii(int amount) { for (int ii = 0; ii < iiOrder.size(); ii++) { iiOrder[ii] += amount; iiOrder[ii] %= iiOrder.size(); } };



