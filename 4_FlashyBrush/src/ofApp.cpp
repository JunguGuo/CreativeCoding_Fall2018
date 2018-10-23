#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
    //ofSetBackgroundAuto(false);
	// create the flow field at window size, with 20 px grid gaps
	flowField = FlowField(ofGetWidth(), ofGetHeight(), 20.);
	
	// add noise to the field, with .1 magnitude forces
	flowField.initNoise(0.1);
	
//    // make a bunch of particles
//    for (int i=0; i<5000; i++){
//
//        Particle p;
//        p.pos.x = ofRandom(0, ofGetWidth());
//        p.pos.y = ofRandom(0, ofGetHeight());
//
//        particles.push_back(p);
//    }
	
	// draw particle trails - 't' on keyboard

	bDrawTrails = false;
	
	// draw the flow field - 'f' on keyboard
	
	bDrawField = false;
	
	// animate the flow field noise - 'a' on keyboard
	
	bAnimateField = true;
	
	// adjust damping using up/down arrows:
	// damping slows particles
	damping = 0.05;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (bAnimateField)
	{
		// if we're animating the field, update noise
		flowField.initNoise(0.1);
	}
	
	for (int i=0; i<particles.size(); i++)
	{
		// get the force at the particle position
		ofVec3f force = flowField.getForceAt(particles[i].pos);
		
		particles[i].applyForce(force);
		particles[i].applyDamping(damping);
		
		particles[i].update();
        
        if(particles[i].life<0-i*10)
            particles.erase(particles.begin()+i);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	if (bDrawTrails)
	{
		// draw a semi-transparent black background
		// to create fading particle trails
		ofPushStyle();
		ofSetColor(0, 20);
		ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
		ofPopStyle();
	}
	
	if (bDrawField)
	{
		// draw forces x100 magnitude to see them
		flowField.draw(100.);
	}
    int index = 0;
    if(particles.size()>0 ){
        ofNoFill();
    ofSetLineWidth(2);
        ofSetColor(ofNoise(0.1*ofGetElapsedTimef())*255,ofNoise(0.1*ofGetElapsedTimef()+10000)*255,ofNoise(0.1*ofGetElapsedTimef()+20000)*255);
    ofBeginShape();
    ofCurveVertex(particles[0].pos);
	for (int i=0; i<particles.size(); i++)
	{
        
        ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
		particles[i].draw();
	}
        ofCurveVertex(particles[particles.size()-1].pos);
    ofEndShape();
    }
    
    if(particles.size()>1){
    for (int i=0; i<particles.size(); i++)
    {
        
        for (int j=i; j<particles.size(); j++)
        {
            
            if(particles[i].pos.distance(particles[j].pos)<100&&particles[i].pos.distance(particles[j].pos)>30){
                ofSetColor(particles[i].col,particles[i].alpha); ofDrawLine(particles[i].pos,particles[j].pos);}
        }
    }
        
    }
    
    
    
	
	// draw the text labels
	
	string label =	"press 'T' : draw particles trails \n";
	label +=			"press 'F' : draw flow field \n";
	label +=			"press 'A' : animate field \n";
	label +=			"press ' ' : reset particle positions \n";
	label +=			"'UP'/'DN' : damping = " + ofToString(damping);
	ofDrawBitmapStringHighlight(label, 20,20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == ' ')
	{
		// ' ' (space) reset particle positions
		
		for (int i=0; i<particles.size(); i++)
		{
			particles[i].pos.x = ofRandom(0, ofGetWidth());
			particles[i].pos.y = ofRandom(0, ofGetHeight());
			particles[i].vel = ofVec3f();
		}
	}
	else if (key == 'f' || key == 'F')
	{
		// 'F' toggle field draw
		bDrawField = !bDrawField;
	}
	else if (key == 't' || key == 'T')
	{
		// 'T' toggle trails
		bDrawTrails = !bDrawTrails;
		ofSetBackgroundAuto(!bDrawTrails);
	}
	else if (key == 'a' || key == 'A')
	{
		// 'A' toggle field animation
		bAnimateField = !bAnimateField;
	}
	
	// adjust damping using up, down arrows

	else if (key == OF_KEY_UP)
	{
		damping += 0.01;
	}
	else if (key == OF_KEY_DOWN)
	{
		damping -= 0.01;
		if (damping < 0) damping = 0;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Particle p;
    p.setup(ofVec3f(ofGetMouseX(),ofGetMouseY(),0));
    
    particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
