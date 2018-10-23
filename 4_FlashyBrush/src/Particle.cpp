
#include "Particle.hpp"

Particle::Particle()
{
    
}

void Particle::setup(ofVec3f _pos)
{
	pos = _pos;
	//vel = _vel;
    col = ofColor::fromHsb((int)(_pos.x+_pos.y)%255,200,220);
//    cout<<col<<endl;
}

void Particle::applyForce(ofVec3f force)
{
	acc += force;
}

void Particle::applyDamping(float strength)
{
	acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
    life -=0.1;
}

void Particle::draw(){
	
	ofPushStyle();
    alpha =ofMap(life, 0, maxLife, 0, 255);
    if(life<0)
        alpha =0;
	ofSetColor(col);
    ofFill();
    
    ofDrawRectangle(pos, 8, 8);
    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofDrawCircle(pos, 2);
	ofPopStyle();
}

