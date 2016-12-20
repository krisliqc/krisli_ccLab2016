#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(32,54,111);
    
    //jelly
    jelly1.init(ofPoint(0,0,0));
    
    //algae
    num = 500;
    
    for(int i =0; i < num; i++){
        Algae temp;
        algaes.push_back(temp);
        algaes[i].init();
    }
    
    gui.setup();
    gui.add(rad1.setup("rad1", 0.86*PI, 0, 2*PI));
    gui.add(rad2.setup("rad2", 1.5*PI, 0, 2*PI));
    gui.add(degree.setup("deg", 0, 0, 360));
    gui.add(a.setup("a", 5, 0, 100));
    gui.add(b.setup("b", 20, 0, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
    jelly1.update(rad1, rad2);
    
    //algae
    for(int i = 0; i < num; i++){
        algaes[i].update(i);

//        for(int j = 0; j < 3; j++){
//            algaes[i].repel(anchors[j].pos);
//        }
//        ofPoint rep = ofPoint(ofGetMouseX(),ofGetMouseY());
        ofPoint rep = jelly1.pos;
        algaes[i].repel(rep);
        algaes[i].noise(a, b);
        algaes[i].space(&algaes);
        algaes[i].bound();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofColor colorOne(50, 70, 141);
    ofColor colorTwo(0, 15, 60);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    
    
    cam.begin();
    
    ofPushMatrix();
    ofRotateX(120);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight());
//    ofRotateZ(degree);
        jelly1.draw();
    
//plane test
//    ofSetColor(255,50);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    
    cam.end();
    
    //bg
    
    for(int i = 0; i < num; i++){
        algaes[i].draw();
    }
    
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
