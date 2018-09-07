//
//  Easing.hpp
//  EasingSketch
//
//  Created by 俊谷郭 on 9/7/18.
//

#pragma once
#include "ofMain.h"

class Easing {
public:
    

    float static easeInSine(float begin,float end,float pct);
    
    float static easeOutSine(float begin,float end,float pct);
    
    float static easeInOutSine(float begin,float end,float pct);
    
    float static easeInCubic(float begin,float end,float pct);
    
    float static easeOutCubic(float begin,float end,float pct);
    
    float static easeInOutCubic(float begin,float end,float pct);
    
    float static easeInElastic(float begin,float end,float pct);
    
    float static easeOutElastic(float begin,float end,float pct);
    
    float static easeInOutElastic(float begin,float end,float pct);
    
    void static plot();
};
