#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(740, 860);
    ofBackground(224,215,205);
    ofEnableSmoothing();
    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
    ofSetFrameRate(60);
    
    Square square;
    square.pos1 = ofPoint(465,314);square.pos2 = ofPoint(465,314);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 80;square.height2 = 80;
    square.col = ofColor(249,206,40); //yellow1
    square.angle1 = 0; square.angle2 = 90;
    squares.push_back(square);
    
    square.pos1 = ofPoint(257,298);square.pos2 = ofPoint(257,298);
    square.width1 = 85;square.width2 = 85;
    square.height1 = 85;square.height2 = 85;
    square.col = ofColor(249,206,40); //yellow2 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    //--row2
    square.pos1 = ofPoint(430,262);square.pos2 = ofPoint(430,262);
    square.width1 = 67;square.width2 = 67;
    square.height1 = 67;square.height2 = 67;
    square.col = ofColor(224,76,48); //red 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    square.pos1 = ofPoint(270,268);square.pos2 = ofPoint(270,268);
    square.width1 = 67;square.width2 = 67;
    square.height1 = 67;square.height2 = 67;
    square.col = ofColor(224,76,48); //red 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    square.pos1 = ofPoint(144,232);square.pos2 = ofPoint(144,232);
    square.width1 = 92;square.width2 = 92;
    square.height1 = 92;square.height2 = 92;
    square.col = ofColor(249,206,40); //yel 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    square.pos1 = ofPoint(97,260);square.pos2 = ofPoint(97,260);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 80;square.height2 = 80;
    square.col = ofColor(224,76,48); //red 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    //--- row3
    
    square.pos1 = ofPoint(541,206);square.pos2 = ofPoint(568,222);
    square.width1 = 180;square.width2 = 180;
    square.height1 = 234;square.height2 = 0;
    square.col = ofColor(0); //black
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    square.pos1 = ofPoint(428,200);square.pos2 = ofPoint(428,200);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 80;square.height2 = 80;
    square.col = ofColor(249,206,40); //yel 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    square.pos1 = ofPoint(344,109);square.pos2 = ofPoint(344,109);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 77;square.height2 = 77;
    square.col = ofColor(249,206,40); //yel 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    square.pos1 = ofPoint(372,177);square.pos2 = ofPoint(372,177);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 89;square.height2 = 89;
    square.col = ofColor(224,76,48); //red
    square.angle1 = 0; square.angle2 = 180;
    squares.push_back(square);
    
    square.pos1 = ofPoint(533,169);square.pos2 = ofPoint(533,169);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 73;square.height2 = 73;
    square.col = ofColor(224,76,48); //red 45rot
    square.angle1 = 45; square.angle2 = 135;
    squares.push_back(square);
    
    
    square.pos1 = ofPoint(316,219);square.pos2 = ofPoint(316,219);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 71;square.height2 = 71;
    square.col = ofColor(249,206,40); //yel 45rot
    square.angle1 = 0; square.angle2 = 180;
    squares.push_back(square);
    
    
    square.pos1 = ofPoint(153,137);square.pos2 = ofPoint(153,137);
    square.width1 = 90;square.width2 = 90;
    square.height1 = 94;square.height2 = 94;
    square.col = ofColor(249,206,40); //yel 45rot
    square.angle1 = 0; square.angle2 = 90;
    squares.push_back(square);
    
    
    square.pos1 = ofPoint(217,176);square.pos2 = ofPoint(217,176);
    square.width1 = 80;square.width2 = 80;
    square.height1 = 80;square.height2 = 80;
    square.col = ofColor(224,76,48);//red
    square.angle1 = 0; square.angle2 = 90;
    squares.push_back(square);
    
    //black stick
    square.pos1 = ofPoint(380,300);square.pos2 = ofPoint(380,300);
    square.width1 = 17;square.width2 = 17;
    square.height1 = 148;square.height2 = 100;
    square.col = ofColor(0);//ver big
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
    square.pos1 = ofPoint(279,311);square.pos2 = ofPoint(279,311);
    square.width1 = 151;square.width2 = 100;
    square.height1 = 15;square.height2 = 15;
    square.col = ofColor(0);//hor
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
    square.pos1 = ofPoint(254,250);square.pos2 = ofPoint(254,250);
    square.width1 = 18;square.width2 = 18;
    square.height1 = 50;square.height2 = 35;
    square.col = ofColor(0);//ver small
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
    //blue
    square.pos1 = ofPoint(365,563);square.pos2 = ofPoint(365,563);
    square.width1 = 304;square.width2 = 304;
    square.height1 = 339;square.height2 = 339;
    square.col = ofColor(20,36,80);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    //white
    square.pos1 = ofPoint(325,453);square.pos2 = ofPoint(325,453);
    square.width1 = 99;square.width2 = 102;
    square.height1 = 61;square.height2 = 44;
    square.col = ofColor(255);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    square.pos1 = ofPoint(435,473);square.pos2 = ofPoint(435,473);
    square.width1 = 90;square.width2 = 80;
    square.height1 = 31;square.height2 = 15;
    square.col = ofColor(255);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    square.pos1 = ofPoint(470,540);square.pos2 = ofPoint(470,540);
    square.width1 = 31;square.width2 = 45;
    square.height1 = 71;square.height2 = 100;
    square.col = ofColor(255);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    square.pos1 = ofPoint(400,590);square.pos2 = ofPoint(400,590);
    square.width1 = 32;square.width2 = 67;
    square.height1 = 112;square.height2 = 66;
    square.col = ofColor(255);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
    //black
    square.pos1 = ofPoint(245,603);square.pos2 = ofPoint(235,593);
    square.width1 = 217;square.width2 = 0;
    square.height1 = 168;square.height2 = 168;
    square.col = ofColor(0);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
    //small balck
    square.pos1 = ofPoint(90,135);square.pos2 = ofPoint(80,155);
    square.width1 = 40;square.width2 = 0;
    square.height1 = 40;square.height2 = 0;
    square.col = ofColor(0);//
    square.angle1 = 0; square.angle2 = 0;
    squares.push_back(square);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float amt =ofGetElapsedTimef();
    amt = (amt - floor(amt/3)*3)/3;
    
    for (int i=0; i<squares.size(); i++)
        squares[i].update(amt);
        
//        if(stars[i].age > 240)
//        {
//            stars.erase( stars.begin() + i );
//        }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Easing::plot();//ofSetWindowShape(640, 1600);ofBackground(0, 0, 0);
    for (int i=0; i<squares.size(); i++)
        squares[i].draw();
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
