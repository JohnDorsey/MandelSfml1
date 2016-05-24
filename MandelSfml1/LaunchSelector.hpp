//
//  LaunchSelector.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 5/18/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//

#ifndef LaunchSelector_hpp
#define LaunchSelector_hpp

#include <stdio.h>

class LaunchSelector {
public:
    
    void selectSome(float (&idealCoords)[256], float (&actualCoords)[256], int (&outsideOrder)[256]);
    
};

#endif /* LaunchSelector_hpp */
