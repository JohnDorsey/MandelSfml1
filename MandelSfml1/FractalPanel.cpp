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
float zoom = 0.25;
float x = 0.0f;
float y = 0.0f;
float personalSpace = 0.4f;


//FractalPixel pixels[256][256];
FractalArray pixels;

FractalPanel::FractalPanel() {
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


void FractalPanel::arrange() {
    //bool flying[256]; //if a row or column is flying, it cast off into space to be ignored for a little while. by the end of this method, all rows and columns must land somewhere.
    //float practicalSpace = ((1 / zoom) / 256) * personalSpace; //how close two rows or columns must be for one to be launched
    //float tempDistances[256];
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
    std::vector<float> result = { ((((float) chxy[0] / 256.0f) - 0.5f) / zoom) + x, ((((float) chxy[1] / 256.0f) - 0.5f) / zoom) + y };
    //printf(" %f %f", result[0], result[1]);
    return result;
    //return std::vector<float> { ((((float) chxy[0] / 256.0f) - 0.5f) * 4.0f) + x, ((((float) chxy[1] / 256.0f) - 0.5f) * 4.0f) + y };
};





