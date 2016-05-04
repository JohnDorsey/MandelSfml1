//
//  FractalOrganizer.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/4/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef FractalOrganizer_hpp
#define FractalOrganizer_hpp

#include <stdio.h>
#include "ResourcePath.hpp"
#include <array>
class FractalPanel;

class FractalOrganizer {
public:
    std::array<int,256> iOrder;
    std::array<int,256> iiOrder;
    FractalPanel* parentPanel;
    FractalOrganizer();
    FractalOrganizer(FractalPanel *nParentPanel);
    void reset();
    int i(int fi);
    int ii(int fii);
    void inci(int amount);
    void incii(int amount);
    
    
    
};


#endif /* FractalOrganizer_hpp */
