//
//  FractalArray.cpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/6/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#include "FractalArray.hpp"
#include "FractalPanel.hpp"
#include "FractalPixel.hpp"

FractalPixel arr[256][256];

FractalArray::FractalArray() {
    printf("Creating a FractalArray.\n");
};

FractalArray::FractalArray(FractalPanel *nParentPanel) {
    parentPanel = nParentPanel;
};

FractalPixel* FractalArray::get(int i, int ii) {
    return &arr[inx.i(i)][inx.ii(ii)];
};
