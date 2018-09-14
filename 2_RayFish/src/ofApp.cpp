#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 800);
    ofBackground(37,68,112);
    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(255);
    
    int Width = 400;
    int Height = 400;
    int step = 50;
    int sizeScale = 6;
//    sizeScale = ofMap(Width, 0, 500, 0, 10);
//    step = ofMap(Width, 0, 500, 0,50);
    ofTranslate(0,ofGetHeight());
    ofTranslate(ofGetWidth()/2,-ofGetElapsedTimef()*40);
    ofRotate(45);
    
    for(int i =0; i<Width; i+=step){
        for(int j =0;j<Height;j+=step){
            
            
            float size = sin(3*(ofGetElapsedTimef()+j*2+i*2))*sizeScale+sizeScale+3;
            //ofDrawRectangle(i, j, size, size);
            float r = ofMap(ofGetMouseX(),0,ofGetWidth(),0,size);
            //ofMap(ofGetMouseY(),0,ofGetHeight())
            //r = sin(2*ofGetElapsedTimef())*size+size;
            
            int hue =int(i+j+r)%255;
            ofColor c = ofColor::fromHsb(hue, 255*0.44, 255*0.9);
            ofSetColor(c);
            ofDrawCircle(i+ (sin(3*ofGetElapsedTimef()+i)* ofMap(j, 0, Height, -50, 50))+sin(3*ofGetElapsedTimef()+i+Width/2)*50,
                         j+(sin(3*ofGetElapsedTimef()+j)* ofMap(i, 0, Width, -50, 50)) +sin(3*ofGetElapsedTimef()+j+Height/2)*50,
                         size);
//
//            ofDrawCircle(i+ (sin(ofGetElapsedTimef()+i)* ofMap(j, 0, ofGetHeight(), -ofGetWidth(), ofGetWidth())), j,  r);
            
//            ofDrawRectRounded(i+ (sin(ofGetElapsedTimef()+i)* j), j, size, size, r);
            


        }
        
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
