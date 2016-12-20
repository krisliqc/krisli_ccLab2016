//
//  Firework.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/15/16.
//
//

#include "Firework.hpp"


void Firework::setup(ofPoint _pos){
    
    pos.x = _pos.x +ofRandom(5,10);
    pos.y = _pos.y +ofRandom(5,10);
    pos.z = _pos.z +ofRandom(5,10);
    
    
    radius = ofRandom(5,10);
    
    vel.x = ofRandom(-0.5,0.5);
    vel.y = 7*ofRandom(0,1);
    vel.z = ofRandom(-0.5, 0.5);

    float noise = ofNoise(ofGetElapsedTimef()/4);
    
    color = ofColor(235 + 20*noise, 225 + 20*noise, 150+ 10*noise);
    
    someNumber = ofRandom(1,400);
    
    
    
}

void Firework::explosion(){
    
    pos = pos + vel;
    
}

void Firework::draw(){
    for(int i = 0; i < 5; i ++){
    ofSetColor(color, i*5);
    ofDrawSphere(pos.x, pos.y, radius, radius-i);
    }
}

void Firework::restart(ofPoint _pos){
    pos = _pos;
}



