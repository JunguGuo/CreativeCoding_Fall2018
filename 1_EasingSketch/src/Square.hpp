//
//  Square.hpp
//  EasingSketch
//
//  Created by 俊谷郭 on 9/7/18.
//

#pragma once
#include "ofMain.h"
class Square {
    public:
    Square();
    ofPoint pos,pos1,pos2;
    float width,width1,width2;
    float height,height1,height2;
    ofColor col;
    float angle,angle1,angle2;
    
    bool flipped = false;
    //float pct = 0;
    void draw();
    void update(float pct);
    void swap(float& a,float& b);
    void swap(ofPoint& a,ofPoint& b);
};
