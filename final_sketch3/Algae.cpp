//
//  Algae.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/10/16.
//
//

#include "Algae.hpp"

Algae::Algae(){
    attract = true;
}

void Algae::init(){
    pos = ofPoint(ofRandomHeight(), ofRandomWidth(), ofRandom(-1000,1000));
    vel = ofPoint(0,0,0);
    frc = ofPoint(0,0,0);
    rep = ofPoint(0,0,0);
    
//    damp = 0.98;
}

void Algae::update(int _num){
    
//    vel += frc*0.25;
//    vel *= damp;
    pos.y += 2;
    
    
    pos += vel*0.05;
    
//    pos.x = ofNoise(ofGetElapsedTimef()/4-1000+_num*2)*ofGetWidth()*2;
//    pos.y = ofNoise(ofGetElapsedTimef()/6+1000-_num*3)*ofGetHeight()*2;
//    pos.z = ofNoise(ofGetElapsedTimef()/7-2000+_num*2)*2000 -500;
}

void Algae::repel(ofPoint _rep){
    
    ofPoint attractPt = _rep;
    
    //attract
    if(attract == true){
        
        
        frc = attractPt - pos;
        float dist = frc.length();
        frc.normalize();
        if(dist < 500 && dist > 200){
            vel += frc*0.1;
        }
        
    } else {
        // repel
        frc = attractPt - pos;
        float dist = frc.length();
        frc.normalize();
        
        if(dist < 200){
            vel -= frc;
        }
    }
}

void Algae::noise(float _a, float _b){
    float xForce = ofSignedNoise(pos.x, pos.y, 0+_a, ofGetElapsedTimef()+_b);
    float yForce = ofSignedNoise(pos.x, pos.y, 10000+_a, ofGetElapsedTimef()+_b);
    float zForce = ofSignedNoise(pos.y, pos.z, 5000+_a, ofGetElapsedTimef()+_b);
    frc += ofPoint(xForce*5,yForce*5,zForce*5);
}

void Algae::space(vector<Algae> *algaes){
    for(int i = 0; i< algaes->size(); i++){
        if (&(*algaes)[i] == this) {
            continue;
        }
        float dist = ofDist((*algaes)[i].pos.x,(*algaes)[i].pos.y, pos.x, pos.y);
        if(dist < 30){
            rep = pos - (*algaes)[i].pos;
            rep.normalize();
            vel += rep*0.25;
        }
    }
    
    float dist = ofDist(ofGetMouseX(),ofGetMouseY(), pos.x, pos.y);
    if(dist < 100){
        rep = pos - ofPoint(ofGetMouseX(),ofGetMouseY());
        rep.normalize();
        vel += rep;
    }
}

void Algae::bound(){
    if(pos.x < 0 || pos.x > ofGetWidth()){
        vel.x = -vel.x;
    }
    
//    if(pos.y < 0 || pos.y > ofGetHeight()){
//        vel.y = -vel.y;
//    }
    
    if(pos.y > ofGetHeight()){
        pos.y = 0;
    }
    
    if(pos.z < -1000 || pos.z > 1000){
        vel.z = -vel.z;
    }
}

void Algae::draw(){
    
    for(int i=0; i < 10; i++){
        ofSetColor(0,88,169, 20-2*i);
        ofDrawCircle(pos, i*4);
        
    }
}






