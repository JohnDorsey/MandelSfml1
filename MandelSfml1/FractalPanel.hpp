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
#include "FractalPixel.hpp"

class FractalPanel {
public:
    FractalPanel();
    void populate();
    std::vector<float> whatsMyri(std::vector<float> chxy);
};

#endif /* FractalPanel_hpp */
