//
//  Worm.hpp
//  SquirmyWorms
//
//  Created by 俊谷郭 on 9/14/18.
//
//  Adapated from Nature of Code Spring Array Example. Click to attrack the worms.

#pragma once
#include "ofMain.h"


class Bob {
public:
    ofPoint position;
    ofPoint velocity;
    ofPoint acceleration;
    float freq = 2;
    float mass = 8;
    int id;
    // Arbitrary damping to simulate friction / drag
    float damping = 0.95;
    
    // For mouse interaction
    ofPoint dragOffset;
    bool dragging = false;
    
    // Constructor
    Bob(float x, float y);
    Bob();
    // Standard Euler integration
    void update(int index);
    
    // Newton's law: F = M * A
    void applyForce(ofPoint force);
    
    
    // Draw the bob
    void display();
    
    // The methods below are for mouse interaction
    
    // This checks to see if we clicked on the mover
    void clicked(int mx, int my);
    
    void stopDragging();
    
    void drag(int mx, int my);
};

class Spring {
public:
    // position
    ofPoint anchor;
    
    // Rest length and spring constant
    float len;
    float k = 0.2;
    
    Bob* a;
    Bob* b;
    
    // Constructor
    Spring(Bob* a_, Bob* b_, int l) ;
    Spring();
    // Calculate spring force
    void update();
    
    
    void display();
};



class Worm{
public:
    vector<Bob> bobs;
    vector<Spring> springs;
    ofPoint position;
    ofPoint initPosition;
    ofPoint target;
    void update();
    void display();
    Worm(ofPoint pos);
    Worm();
    ofColor col;
   
};
