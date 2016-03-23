//
//  FractalPlane.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 3/11/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//


#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "FractalPlane.hpp"
#include "FractalVis.hpp"

std::vector<float> vects[256][256];

FractalVis fractalVis;

FractalPlane::FractalPlane() {
    for (int x = 0; x < 256; x++) {
        for (int y = 0; y < 256; y++) {
            vects[x][y] = std::__1::vector<float, std::__1::allocator<float>>(5);
            initPoint(vects[x][y], x, y);
        }
    }
};


void FractalPlane::drawToArray(int (&itrCount)[256][256]) {
    for (int x = 0; x < 256; x++) {
        for (int y = 0; y < 256; y++) {
            itrCount[x][y] = vects[x][y][4];
        }
    }
};


void FractalPlane::drawTo1DArray(int (&itrCount1D)[65536]) {
    for (int x = 0; x < 256; x++){
        for (int y = 0; y < 256; y++) {
            itrCount1D[(x * 256) + y] = (int) vects[x][y][4];
        }
    }
};


void FractalPlane::initPoint(std::vector<float> &landing, int x, int y) {
    landing = { (float) (x / 128) - 1, (float) (y / 128) - 1, (float) (x / 128) - 1, (float) (y / 128) - 1, 0 };
};


void FractalPlane::iterate() {
    for (int x = 0; x < 256; x++) {
        for (int y = 0; y < 256; y++) {
            iteratePoint(x, y);
        }
    }
    
};


void FractalPlane::iteratePoint(int x, int y) {
    std::vector<float>* thisPt = &vects[x][y];
    
    for (; (*thisPt)[4] < 32; (*thisPt)[4]++) {
        (*thisPt) = {((*thisPt)[0] * (*thisPt)[0]) - ((*thisPt)[1] * (*thisPt)[1]) + (*thisPt)[2], ((*thisPt)[0] * (*thisPt)[1] * 2) + (*thisPt)[3], (*thisPt)[2], (*thisPt)[3], (*thisPt)[4] + 1};
    }
    
};