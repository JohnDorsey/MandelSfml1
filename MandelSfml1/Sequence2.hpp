//
//  Sequence2.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/2/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef Sequence2_hpp
#define Sequence2_hpp

#include <stdio.h>
#include "Sequence.hpp"

class Sequence2 {
public:
    Sequence2();
    int type = 0;
    Sequence sequences[256];
};

#endif /* Sequence2_hpp */