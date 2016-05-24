//
//  FractalPanel.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 4/7/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalPanel.hpp"
#include "FractalPixel.hpp"
#include "FractalArray.hpp"
#include "MovementAdvisor.hpp"

//float travel = 4;
//const int startRes = 256;
//float xScale = 2;
//float yScale = 2;
float perAverage = 1.0f; //do not change this
float perFlyDeviation = 2.0f;
float perLandDeviation = 1.1f; //must always be lower in difference from 1 than perFlyDeviation, so no rows or columns are lost in space. that'd be bad.


//FractalPixel pixels[256][256];
//FractalArray pixels;
FractalArray pixels;
//FractalOrderer consultant;

MovementAdvisor consultant;

FractalPanel::FractalPanel() {
    printf("creating a FractalPanel with no arguments.\n");
    //publicPixels = &pixels;
    populate();
};


void FractalPanel::populate() {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            //pixels[inx.i(i)][inx.ii(ii)] = FractalPixel(this);
            *pixels.get(i,ii) = FractalPixel(this);
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            //pixels[inx.i(i)][inx.ii(ii)].startAt(std::vector<float> {(float) i, (float) ii});
            pixels.get(i,ii) -> startAt(std::vector<float> {(float) i, (float) ii});
        }
    }
    solveAll();
    
};


void FractalPanel::dah() {
    pixels.inx.movei(20,80);
    //solvei(40);
    pixels.inx.movei(240,180);
    //solvei(60);
};



//};

void FractalPanel::arrange() {
    arrange(true);
    arrange(false);
};

void FractalPanel::arrange(bool p) {
    //std::vector<int> instructions[256] = std::__1::vector<int, std::__1::allocator<int>>(2);
    //std::__1::vector<int, std::__1::allocator<int>>(2); instructions[256];
    std::vector<int> instructions[256]; fill(instructions, instructions + 256, std::vector<int>(2));
    float tmpActualCoords[256];
    float tmpIdealCoords[256];
    for (int at = 0; at < 256; at++) {
        tmpIdealCoords[at] = p? whatsMyr(at) : whatsMyi(at);
        tmpActualCoords[at] = pixels.get(p? at : 0, p? 0 : at) -> mathPt.thisPt[p? 2 : 3];
    }
    consultant.writeInstructionsTo(tmpActualCoords, tmpIdealCoords, instructions);
    
    int handling;
    for (handling = 0; handling < 256; handling++) {
        if (instructions[handling][0] < 0) { printf("%s %i %s %i%s%i%s", "breaking because instruction", handling, "is", instructions[handling][0], ", ", instructions[handling][1], ".\n\n"); break; }
        //pixels.inx.swapi(instructions[handling][0], instructions[handling][1]);
        printf("%s%i%s", "handling instruction ", handling, ": "); printf("%i%s%i%s", instructions[handling][0], ", ", instructions[handling][1], ":\n");
        if (p) {
            pixels.inx.movei(instructions[handling][0], instructions[handling][1]);
            solvei(instructions[handling][1]);
        } else {
            pixels.inx.moveii(instructions[handling][0], instructions[handling][1]);
            solveii(instructions[handling][1]);
        }
    }
};



void FractalPanel::dbgSet(int i, int ii, int value) {
    //pixels[inx.i(i)][inx.ii(ii)].mathPt.thisPt[4] += value;
    pixels.get(i,ii) -> mathPt.thisPt[4] += value;
};


void FractalPanel::solveAll() {
    for (int i = 0; i < 256; i++) {
        for (int ii = 0; ii < 256; ii++) {
            //printf("%s %i %i", "\nsolveAll:", i, ii);
            //pixels[i][ii].solve();
            pixels.get(i,ii) -> solve();
            //pixels[i][ii].dbgPrintUniq();
        }
    }
};

void FractalPanel::solvei(int iToSolve) {
    printf("%s%i%s", "solvei: solving ", iToSolve, ".\n");
    for (int ii = 0; ii < 256; ii++) {
        pixels.get(iToSolve, ii) -> startAt(std::vector<float> {(float) iToSolve, (float) ii});
        pixels.get(iToSolve, ii) -> solve();
    }
};

void FractalPanel::solveii(int iiToSolve) {
    printf("%s%i%s", "solveii: solving ", iiToSolve, ".\n");
    for (int i = 0; i < 256; i++) {
        pixels.get(i, iiToSolve) -> startAt(std::vector<float> {(float) i, (float) iiToSolve});
        pixels.get(i, iiToSolve) -> solve();
    }
};

void FractalPanel::drawToPaletteArray(float (&drawTo)[256][256]) {
    
    //x += 0.01f; y += 0.01f;
    //populate(); //solveAll();
    
    for (int i = 0; i < 256; i++) {
        //printf("%i\n", i);
        for (int ii = 0; ii < 256; ii++) {
            //printf("    %i\n", ii);
            //drawTo[i][ii] = pixels[inx.i(i)][inx.ii(ii)].getPalette();
            drawTo[i][ii] = pixels.get(i,ii) -> getPalette();
            //printf("%f", drawTo[i][ii]);
        }
    }
    //printf("DRAWING TO PALETTE ARRAY");
};


std::vector<float> FractalPanel::whatsMyri(std::vector<float> chxy) {
    //std::vector<float> result = { ((((float) chxy[0] / 256.0f) - 0.5f) / zoom) + x, ((((float) chxy[1] / 256.0f) - 0.5f) / zoom) + y }; //works
    std::vector<float> result = { whatsMyr(chxy[0]), whatsMyi(chxy[1]) };
    //printf(" %f %f", result[0], result[1]);
    return result;
    //return std::vector<float> { ((((float) chxy[0] / 256.0f) - 0.5f) * 4.0f) + x, ((((float) chxy[1] / 256.0f) - 0.5f) * 4.0f) + y };
};


float FractalPanel::whatsMyr(float chx) {
    return (((chx / 256.0f) - 0.5f) / zoom) + x;
};

float FractalPanel::whatsMyi(float chy) {
    return (((chy / 256.0f) - 0.5f) / zoom) + y;
    //return (((chy / 256.0f) - 0.5f) / 0.25);
};





