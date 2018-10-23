//
//  Square.cpp
//  attractLines
//
//  Created by 俊谷郭 on 9/18/18.
//

#include "Square.hpp"


void Square::setup(Particle _pos1,Particle _pos2) {
    pos1 = _pos1;
    pos2 = _pos2;
    center.pos = (pos1.pos+ pos2.pos)/2;
}

void Square::setup(Particle _center) {
    center = _center;
    ofPoint p1 = center.pos+ofPoint( ofRandom(30,60),ofRandom(30,60));
    ofPoint p2 = center.pos-ofPoint( ofRandom(30,60),ofRandom(30,60));
    
    pos1.setup(p1,
                 ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)));
    pos2.setup(p2,
               ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)));
    
}


void Square::update() {
    center.pos = (pos1.pos+pos2.pos)/2;
    pos1.addRepulsion(center.pos, 50, 10);
    pos2.addRepulsion(center.pos, 50, 10);
    pos1.addRepulsion(pos2.pos, 50, 10);
    //pos2.addRepulsion(pos1.pos, 50, 1);
    //cout<<pos1.pos<<endl;
    pos1.addAttraction(center.pos, (pos1.pos-center.pos).length(), 100);
    pos2.addAttraction(center.pos, (pos2.pos-center.pos).length(), 100);
    
    pos1.update();//cout<<pos1.pos.x<<endl;
    pos2.update();
    //center.update();
}

void Square::draw() {
    ofSetColor(255,50);
    ofDrawRectangle(center.pos, abs(pos1.pos.x-pos2.pos.x), abs(pos1.pos.y-pos2.pos.y));
    ofDrawCircle(center.pos, 5);
    ofDrawCircle(pos1.pos, 2);
}
