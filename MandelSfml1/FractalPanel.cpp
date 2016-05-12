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

//float travel = 4;
//const int startRes = 256;
//float xScale = 2;
//float yScale = 2;
float x = 0.0f;
float y = 0.0f;
float perAverage = 1.0f; //do not change this
float perFlyDeviation = 2.0f;
float perLandDeviation = 1.1f; //must always be lower in difference from 1 than perFlyDeviation, so no rows or columns are lost in space. that'd be bad.


//FractalPixel pixels[256][256];
//FractalArray pixels;
FractalArray pixels;

FractalPanel::FractalPanel() {
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
    pixels.inx.movei(20,40);
    pixels.inx.movei(80,60);
};


void FractalPanel::arrange() {
    bool flying[256]; //if a column is flying, it cast off into space to be ignored for a little while. by the end of this method, all rows and columns must land somewhere.
    bool landZone[256];
    float perBubble = ((1 / zoom) / 256) * perAverage; //base for determining how close two columns must be for one to be launched (always the one on the right)
    float tempDistances[257];
    float lastr = whatsMyr(0) - perBubble;
    for (int ati = 0; ati < 256; ati++) {
        tempDistances[ati] = (pixels.get(ati,0) -> mathPt.thisPt[2]) - lastr;
        lastr = (pixels.get(ati,0) -> mathPt.thisPt[2]);
        printf(" %f", tempDistances[ati]);
    }
    printf("%s %f %f %f %s", "\n######", perFlyDeviation, perLandDeviation, perBubble, "########\n" );
    tempDistances[256] = whatsMyr(256) - (pixels.get(255,0) -> mathPt.thisPt[2]);
    
    // there is now an array of
    // |    #    #    |
    //  dist,dist,dist
    // horizontally.
    // any column with a dist lower than (perFlyDeviation * perBubble) will take off,
    // any column with a dist higher than (perLandDeviation * perBubble) is a valid place to land. rearranging them will be FractalArray's responsibility.
    
    for (int ati = 0; ati < 256; ati++) {
        if (tempDistances[ati] < (perFlyDeviation * perBubble)) {
            flying[ati] = true;
        }
        if (tempDistances[ati] > (perLandDeviation * perBubble)) {
            landZone[ati] = true;
        }
    }
    
    //we now know which columns need to launch (flying[]) and where they need to end up in no particular order (landZone[])
    
    for (int flyi = 0; flyi < 256; flyi++) {
        if (flying[flyi]) {
            for (int landi = 0; landi <256; landi++) {
                if (landZone[landi]) {
                    pixels.inx.movei(flyi, landi);
                    solvei(landi);
                    //break;
                }
            }
            //break;
        }
    }
    
};



//void FractalPanel::arrange() {
    
//};


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
    for (int ii = 0; ii < 256; ii++) {
        pixels.get(iToSolve,ii) -> startAt(std::vector<float> {(float) iToSolve, (float) ii});
        pixels.get(iToSolve, ii) -> solve();
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


float FractalPanel::whatsMyr(float chx) { return (((chx / 256.0f) - 0.5f) / zoom) + x; };
float FractalPanel::whatsMyi(float chy) { return (((chy / 256.0f) - 0.5f) / zoom) + y; };





