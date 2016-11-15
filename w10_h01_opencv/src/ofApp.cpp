#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(128);
    mCamWidth = 320;
    mCamHeight = 240;
    
    mVidGrabber.setDeviceID(0);
    mVidGrabber.setDesiredFrameRate(60);
    mVidGrabber.initGrabber(mCamWidth, mCamHeight);
    
    
    mColorImg.allocate(mCamWidth, mCamHeight);
    mGrayImg.allocate(mCamWidth, mCamHeight);
    mColorSnap.allocate(mCamWidth, mCamHeight);
    
    
    for(int i = 0; i < 10; i++){
        ofxCvColorImage temp;
        mColorSnaps.push_back(temp);
    }
    for(int i =0; i < 10; i++){
    mColorSnaps[i].allocate(mCamWidth, mCamHeight);
    }
    
    mThreshold = 10;
    mLearnBackground = true;
    
    record = false;
    
//    gui.setup();
//    gui.add(record.setup("record", false));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mVidGrabber.update();
    
    if(mVidGrabber.isFrameNew()){
        mColorImg.setFromPixels(mVidGrabber.getPixels());
        mGrayImg = mColorImg;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    mVidGrabber.draw(20, 20);
    mGrayImg.draw(400, 20);
    mColorSnap.draw(20, 300);
    
    ofEnableAlphaBlending();
    for(int i =0; i<10; i++){
        ofSetColor(255, 255, 255, 25);
        mColorSnaps[i].draw(400, 300);
    }
    ofDisableAlphaBlending();
    
//    gui.draw();
    

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
    
    record == true;
    mColorSnap = mColorImg;
//    mColorSnaps.push_back(mColorSnap);
    for(int i = 0 ; i < 10; i++){
        if(i == 9){
            continue;
        } else{
    mColorSnaps[i] = mColorSnaps[i+1];
        }
    }
    mColorSnaps[9] = mColorSnap;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    record == false;
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
