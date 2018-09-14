//
//  Worm.cpp
//  SquirmyWorms
//
//  Created by 俊谷郭 on 9/14/18.
//

#include "Worm.hpp"
Worm::Worm(){}
Worm::Worm(ofPoint pos){
    position = pos;
    initPosition = pos;
    
    Bob b = Bob(pos.x,pos.y);
    bobs.push_back(b);
    float initRot = ofRandom(360);
    
    int bobSize = ofRandom(4,12);
    for (int i = 1; i <bobSize; i++) {
        ofPoint dir = ofPoint(1,0);
        ofPoint newPos = bobs[i-1].position + dir.rotate(initRot*ofNoise(i*0.1+initRot*10000), ofVec3f(0,0,1))*30;//rotate would change the value of ofPoint
        Bob b = Bob(newPos.x,newPos.y);
        b.id = i;
        bobs.push_back(b);
    }
    for (int i = 0; i < bobSize-1; i++) {
        Spring s = Spring(&bobs[i], &bobs[i+1],10);
        springs.push_back(s);
    }
    
    int r = ofRandom(5);
    ofColor cols[] = {ofColor(233,139,40),ofColor::fromHex(0x3a97c6),ofColor::fromHex(0x40ac7e),ofColor::fromHex(0x9971a8),ofColor::fromHex(0xce512f)};
    col = cols[r];
    
    
}
void Worm::update(){
    for (Spring& s : springs) {
        s.update();
        
    }
 
    
    for (int i =0;i<bobs.size();i++) {
        bobs[i].update(i);
//        b.drag(ofGetMouseX(), ofGetMouseY());
    }
    
    initPosition += ofRandom(-10,10);
    if((initPosition.x>ofGetWidth() && initPosition.y>ofGetHeight()) ||(initPosition.x<0 && initPosition.y<0) )
        initPosition = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    if(ofGetMousePressed())
        target = ofPoint(ofGetMouseX(),ofGetMouseY());
    else
        target = initPosition;
    
    ofPoint dir =target -bobs[0].position;
    bobs[0].applyForce(dir*0.1);
//    bobs[0].velocity.scale( ofClamp(bobs[0].velocity.length(), 0.0, 0.0)  );

    
}
void Worm::display(){
    
    for (Spring& s : springs) {
        s.display();
    }
      ofSetColor(col);
        ofSetLineWidth(10);
    for (int i = 0;i<bobs.size()-1;i++) {
        bobs[i].display();
        ofDrawLine(bobs[i].position.x, bobs[i].position.y, bobs[i+1].position.x, bobs[i+1].position.y);
    }
  
//    ofSetLineWidth(10);
//    ofNoFill();
//    ofBeginShape();
//    ofCurveVertex(bobs[0].position.x,  bobs[0].position.y);
//    for(int i =0;i<bobs.size();i++){
//        ofCurveVertex(bobs[i].position.x, bobs[i].position.y);
//    }
//    ofCurveVertex(bobs[bobs.size()-1].position.x,  bobs[bobs.size()-1].position.y);
//    ofEndShape();
    
}

Bob::Bob(float x, float y) {
    position = ofPoint(x,y);
    velocity = ofPoint();
    acceleration = ofPoint();
    dragOffset = ofPoint();
    freq = ofRandom(1,4);
}
Bob::Bob(){
}

void Bob::update(int index) {
    velocity+=acceleration;
    if(index == 0){
        velocity.scale( ofClamp(velocity.length(), 0.2, 2)  );
        velocity.rotate(sin(freq*ofGetElapsedTimef()+id*10000)*70, ofVec3f(0,0,1));
    }
    velocity*=damping;
    position+=velocity;
    acceleration*=0;
}

void Bob::applyForce(ofPoint force) {
    ofPoint f = force;
    f/=mass;
    acceleration+=f;
}

void Bob::display() {

//    ofFill();
//    ofSetColor(175,120);
//    if (dragging) {
//        ofSetColor(50);
//    }
    ofDrawCircle(position.x,position.y,5);
}

void Bob::clicked(int mx, int my) {
    float d = position.distance(ofPoint(mx,my));
    if (d < mass) {
        dragging = true;
        dragOffset.x = position.x-mx;
        dragOffset.y = position.y-my;
    }
}

void Bob::stopDragging() {
    dragging = false;
}

void Bob::drag(int mx, int my) {
    if (dragging) {
        position.x = mx + dragOffset.x;
        position.y = my + dragOffset.y;
    }
}


Spring::Spring(Bob* a_, Bob* b_, int l){
        a = a_;
        b = b_;
        len = l;
    
}
Spring::Spring(){
}
void Spring::update() {
    // Vector pointing from anchor to bob position
    ofPoint force = a->position - b->position;
    // What is distance
    float d = force.length();
    // Stretch is difference between current distance and rest length
    float stretch = d - len;
    
    // Calculate force according to Hooke's Law
    // F = k * stretch
    force.normalize();
    force*=(-1 * k * stretch);
    a->applyForce(force);
    force*=-1;
    b->applyForce(force);
}
void Spring::display(){
    // line(a.position.x, a.position.y, b.position.x, b.position.y);
}
