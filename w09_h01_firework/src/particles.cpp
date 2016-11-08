//
//  particles.cpp
//  w09_h01_firework
//
//  Created by Kris Li on 11/8/16.
//
//

#include "particles.hpp"


void Particle::setup(){
    
    pos.x = ofGetWidth()/2+ofRandom(-10,10);
    pos.y = 200+ofRandom(-5,5);
    radius = ofRandom(1,8);
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-10,-5);
    
    color = ofColor(ofRandom(200,255), ofRandom(200,255), 200);
    
    someNumber = ofRandom(1,400);
}

void Particle::explosion(){
    
    pos = pos + vel;
    
}

void Particle::update(){
    vel.y += 0.5;
}

void Particle::draw(){
    
    ofSetColor(color);
    ofDrawEllipse(pos.x, pos.y, radius, radius);
    
}

void Particle::restart(){
    
    //    pos.x = ofGetWidth()/2+ofRandom(-10,10);
    //    pos.y = 200+ofRandom(-5,5);
    
    pos.x = ofGetMouseX()+ofRandom(-10,10);
    pos.y = ofGetMouseY()+ofRandom(-5,5);
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-10,-5);
    
}