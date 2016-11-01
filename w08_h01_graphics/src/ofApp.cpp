#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(240, 255, 200);
    wave.load("wave.png");
    
    gui.setup();
    gui.add(time.setup("Brightness", 200, 0, 200));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, PI);
    posX = ofMap(ofGetMouseX(), 0, ofGetWidth(), ofGetWidth()*0.2, ofGetWidth()*0.8);
    posY = ofMap(sin(angle), 0,1,600,200);
    radius = ofMap(posY, 200, 600, 80, 30);
    
    waveH = ofGetHeight()*0.8 + sin(angle)*100;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(40+time, 55+time, time);
    
    ofSetColor(255, 200, 0);
    ofDrawEllipse(posX, posY, radius, radius);
    
    ofSetColor(25, 80, 150);
    wave.draw(0, waveH, ofGetWidth(), 200);
    
    gui.draw();
    
    int hour = floor(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 24));
    cout << "Time of the day is " + ofToString(hour) + " o'clock" <<endl;
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
