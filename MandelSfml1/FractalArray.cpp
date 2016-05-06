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
    
};

FractalArray::FractalArray(FractalPanel *nParentPanel) {
    parentPanel = nParentPanel;
};

FractalPixel* get(int i, int ii) {
    return &arr[i][ii];
};