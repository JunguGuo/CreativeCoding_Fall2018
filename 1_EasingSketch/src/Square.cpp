//
//  Square.cpp
//  EasingSketch
//
//  Created by 俊谷郭 on 9/7/18.
//

#include "Square.hpp"
#include "Easing.hpp"
Square::Square(){
    width = 0;
    height = 0;
    col = ofColor::grey;
    angle = 0;
}
void Square::draw(){
    ofFill();
    ofSetColor(col);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(angle);
    ofDrawRectangle(0, 0, width, height);
    ofPopMatrix();
    
}

void Square::update(float pct){
    //animate property with easing
    
    //---
    float posX = Easing::easeInSine(pos1.x, pos2.x, pct);
    float posY = Easing::easeInSine(pos1.y, pos2.y, pct);
    
    pos.set(posX, posY);
    
    //---
    width = Easing::easeInOutElastic(width1, width2, pct);
    height = Easing::easeInOutElastic(height1, height2, pct);
    
    //---
    angle = Easing::easeInOutSine(angle1, angle2, pct);
    
    if(pct>0.995 && flipped == false){
        swap(pos1,pos2);
        swap(width1,width2);
        swap(height1,height2);
        swap(angle1,angle2);        
        flipped = true;

    }
    if(pct<0.1 && flipped)
        flipped = false;

    
    
}

void Square::swap(float& a,float& b){
    float tmp = a;
    a = b;
    b = tmp;
}

void Square::swap(ofPoint& a,ofPoint& b){
    ofPoint tmp = a;
    a = b;
    b = tmp;
}
