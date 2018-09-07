//
//  Easing.cpp
//  EasingSketch
//
//  Created by 俊谷郭 on 9/7/18.
//
// useful refrences about easing:
// https://gist.github.com/gre/1650294
// https://easings.net/zh-cn


#include "Easing.hpp"
float Easing::easeInSine(float begin, float end, float pct)
{
    pct = sin(-(pct+1)*PI*0.5)+1;
    return end*pct+(1-pct)*begin;
}

float Easing::easeOutSine(float begin, float end, float pct)
{
    pct = sin( pct* PI* 0.5);
    return end*pct+(1-pct)*begin;
}

float Easing::easeInOutSine(float begin, float end, float pct)
{
    
    float InSine = easeInSine(begin,end,pct);
    float OutSine = easeOutSine(begin,end,pct);
    return ofLerp(InSine, OutSine, pct);
}

float Easing::easeInCubic(float begin, float end, float pct)
{
    pct = pow(pct,3);
    return end*pct+(1-pct)*begin;
}

float Easing::easeOutCubic(float begin, float end, float pct)
{
    pct = pow(pct-1,3)+1;
    return end*pct+(1-pct)*begin;
}

float Easing::easeInOutCubic(float begin, float end, float pct)
{
    
    float InCubic = easeInCubic(begin,end,pct);
    float OutCubic = easeOutCubic(begin,end,pct);
    return ofLerp(InCubic, OutCubic, pct);
}

float Easing::easeInElastic(float begin, float end, float pct)
{
    pct = (.04 - .04 / pct) * sin(25 * pct) + 1;
    return end*pct+(1-pct)*begin;
}

float Easing::easeOutElastic(float begin, float end, float pct)
{
    pct =  .04 * pct / (--pct) * sin(25 * pct);
    return end*pct+(1-pct)*begin;
}

float Easing::easeInOutElastic(float begin, float end, float pct)
{
    
    pct = (pct -= .5) < 0 ? (.02 + .01 / pct) * sin(50 * pct) : (.02 - .01 / pct) * sin(50 * pct) + 1;
    return end*pct+(1-pct)*begin;
}

void  Easing::plot(){
    
    ofSetLineWidth(2);
    ofSetColor(255);
    float graphSize = 100;
    
    float amt =ofGetElapsedTimef();
    amt = (amt - floor(amt/3)*3)/3;
    float mx=0;
    float ballSize = 5;
    //0 linear
    int index = 0;
    for(float x = 0;x<1;x+=0.1){
        float y = x;
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }
    mx = ofLerp(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //1 easeInSine
    index = 1;
    for(float x = 0;x<1;x+=0.1){
        float y = easeInSine(0, 1, x);
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }

    
    mx = easeInSine(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //2 easeOutSine
    index = 2;
    for(float x = 0;x<1;x+=0.1){
        float y = easeOutSine(0, 1, x);
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }
    
    
    mx = easeOutSine(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //3 easeInOutSine
    index = 3;
    for(float x = 0;x<1;x+=0.1){
        float y = easeInOutSine(0, 1, x);

        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;

        ofDrawCircle(xx, yy, 2);
    }
    
     mx = easeInOutSine(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //4 easeInCubic
    index = 4;
    for(float x = 0;x<1;x+=0.1){
        float y = easeInCubic(0, 1, x);
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }
    
    mx = easeInCubic(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //5 easeOutCubic
    index = 5;
    for(float x = 0;x<1;x+=0.1){
        float y = easeOutCubic(0, 1, x);
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }
    
    mx = easeOutCubic(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    //6 easeInOutCubic
    index = 6;
    for(float x = 0;x<1;x+=0.1){
        float y = easeInOutCubic(0, 1, x);
        
        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
        
        ofDrawCircle(xx, yy, 2);
    }
    
    mx = easeInOutCubic(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    
    //7 easeInElastic
//    index = 7;
//    for(float x = 0;x<1;x+=0.1){
//        float y = easeInElastic(0, 1, x);
//
//        float xx = ofMap(x, 0, 1, 0, graphSize);
//        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
//
//        ofDrawCircle(xx, yy, 2);
//    }
//
//    mx = easeInElastic(graphSize,ofGetWidth(),amt);
//    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
//    //8 easeOutElastic
//    index = 8;
//    for(float x = 0;x<1;x+=0.1){
//        float y = easeOutElastic(0, 1, x);
//
//        float xx = ofMap(x, 0, 1, 0, graphSize);
//        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;
//
//        ofDrawCircle(xx, yy, 2);
//    }
//
//    mx = easeOutElastic(graphSize,ofGetWidth(),amt);
//    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);

    //9 easeInOutElastic
    index = 7;
    for(float x = 0;x<1;x+=0.05){
        float y = easeInOutElastic(0, 1, x);

        float xx = ofMap(x, 0, 1, 0, graphSize);
        float yy = ofGetHeight() - ofMap(y, 0, 1, 0, graphSize)-graphSize*index;

        ofDrawCircle(xx, yy, 2);
    }

    mx = easeInOutElastic(graphSize,ofGetWidth(),amt);
    ofDrawCircle(mx, ofGetHeight()-graphSize/2-graphSize*index, ballSize);
    
    
}
