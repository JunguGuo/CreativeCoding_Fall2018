#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
        ofBackground(44, 71, 98);

ofEnableSmoothing();
    ofSetCurveResolution(50);
    for(int i =0;i<50;i++){
           Worm w = Worm(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
        worms.push_back(w);
        // loop through the bobs
        for(int j = 0; j < worms[i].bobs.size()-1;j++){
            Spring s = Spring(&worms[i].bobs[j], &worms[i].bobs[j+1],10);
            springs.push_back(s);
        }
        //worms.push_back(w);
      
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (Spring& s : springs) {
        s.update();

    }
//
//    for (Bob& b : bobs) {
//        b.update();
//        b.drag(mouseX, mouseY);
//    }
    for(int i = 0;i<50;i++){
        worms[i].update();
        //cout<<i<<endl;
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
     ofBackground(44, 71, 98);
    for(int i = 0;i<50;i++){
        worms[i].display();

    }

//    ofBackground(255);
//
//    for (Spring& s : springs) {
//        s.display();
//    }
//
//    for (Bob& b : bobs) {
//        b.display();
//    }
//
//    ofNoFill();
//    ofBeginShape();
//    ofCurveVertex(bobs[0].position.x,  bobs[0].position.y);
//    for(int i =0;i<10;i++){
//        ofCurveVertex(bobs[i].position.x, bobs[i].position.y);
//    }
//    ofCurveVertex(bobs[9].position.x,  bobs[4].position.y);
//    ofEndShape();

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
    
//    for (Bob& b : w.bobs) {
//        b.clicked(mouseX, mouseY);
//    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    for (Bob& b : w.bobs) {
//        b.stopDragging();
//    }

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
