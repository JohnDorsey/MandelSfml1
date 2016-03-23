//
//  FractalPlane.hpp
//  MandelSfml1
//
//  Created by John Dorsey on 3/11/16.
//  Copyright © 2016 John Dorsey. All rights reserved.
//


#ifndef FractalPlane_hpp
#define FractalPlane_hpp

#include <stdio.h>
#include "vector"

class FractalPlane { //identical
public:
    FractalPlane(); //identical
    void drawToArray(int (&itrCount)[256][256]);
    void drawTo1DArray(int (&itrCount1D)[65536]);
    void iterate();
    void iteratePoint(int x, int y);
    void initPoint(std::vector<float> &landing, int x, int y);
};

#endif /* FractalPlane_hpp */



//#include <SFML/Uint8>
//#include <Uint8>
//#include <sf::Uint8>
//#include <SFML/Uint8>
//#include <sf/Uint8>
//#include <SF::Uint8>
//#include <SFML::Uint8>
//#include <SF/Uint8>

//#include "Uint8"
//#include "sf::Uint8"
//#include "SFML/Uint8"
//#include "sf/Uint8"
//#include "SF::Uint8"
//#include "SFML::Uint8"
//#include "SF/Uint8"

//#include <SFML/UInt8>
//#include <UInt8>
//#include <sf::UInt8>
//#include <SFML/UInt8>
//#include <sf/UInt8>
//#include <SF::UInt8>
//#include <SFML::UInt8>
//#include <SF/UInt8>

//#include "UInt8"
//#include "sf::UInt8"
//#include "SFML/UInt8"
//#include "sf/UInt8"
//#include "SF::UInt8"
//#include "SFML::UInt8"
//#include "SF/UInt8"