#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 30; i++) {
        Particle p;
        p.setup(ofPoint( ofRandom(30,ofGetWidth()-30),ofRandom(30,ofGetHeight()-30)),
                ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)));
        
        Square s;
        s.setup(p);
        squares.push_back(s);
    }
    
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
float repulDist = 35;
float attractDist = 100;
void ofApp::update(){
    
    // particle to particle repulsion

    for( int i = 0; i < squares.size(); i++){

        for( int j = 0; j < i; j++){
            squares[i].pos1.addRepulsion(squares[j].center.pos, repulDist, 5);
            squares[i].pos2.addRepulsion(squares[j].center.pos, repulDist, 5);
            
        }
    }
//
//    // attraction to the mouse and update
    ofPoint mouse = ofPoint(mouseX,mouseY);

    for (int i = 0; i < squares.size(); i++) {
        squares[i].pos1.addAttraction(mouse, attractDist, 0.015);
        squares[i].pos2.addAttraction(mouse, attractDist, 0.015);

    }
    for(int i = 0;i<squares.size();i++){
        squares[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw lines between
//    ofNoFill();
//    for( int i = 0; i < particles.size(); i++){
//
//        for( int j = 0; j < i; j++){
//            ofPoint diffVec =particles[i].pos-particles[j].pos;
//            float d = diffVec.length();
//
//            if(d < 100 ){
//                float alpha = ofMap(d,100,0,0,255);
//                ofSetColor(255,alpha);
//                ofDrawLine(particles[i].pos,particles[j].pos);
//            }
//
//        }
//    }
//
    
   ofFill();
    for( int i = 0; i < squares.size(); i++){
        squares[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
     repulDist = 10;
     attractDist = 1000;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
     repulDist = 35;
     attractDist = 100;
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
