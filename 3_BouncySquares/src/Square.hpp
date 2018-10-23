//
//  Square.hpp
//  attractLines
//
//  Created by 俊谷郭 on 9/18/18.
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class Square{
public:
    Square()=default;
    
    void setup(Particle _pos1,Particle _pos2);
    void setup(Particle _center);

    
    void update();
    void draw();
    
    Particle pos1;
    Particle pos2;
    Particle center;
    float diagonalDist;

};
