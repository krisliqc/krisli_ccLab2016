//
//  Arm.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#include "Arm.hpp"

Arm::Arm(){
    pos = ofPoint (0,0,0);
}

void Arm::init(){
    
    //arms
    for(int i =0; i < 4; i++){
        anchors[i].setInit(ofPoint(0,0,i*100), ofPoint(0,0));
//        anchors[i].setInit(ofPoint(ofRandomWidth(),ofRandomHeight(),i*200), ofPoint(0,0));
    }
    anchors[0].bFix = true;
    
    springs[0].set(&anchors[0], &anchors[1]);
    springs[0].restDist = 20;
    springs[1].set(&anchors[1], &anchors[2]);
    springs[1].restDist = 30;
    springs[2].set(&anchors[2], &anchors[3]);
    springs[2].restDist = 40;
}

void Arm::update(ofPoint _pos){
    //arm
    ofPoint link = _pos;
    
    for(int i =0; i< 3; i++){
        springs[i].update();
    }
    for(int i =0; i< 4; i++){
        anchors[i].update();
    }
    
    anchors[0].pos.set(link);
}

void Arm::draw(){
    
    ofSetLineWidth(2);
    //arm
    for(int i =0; i< 3; i++){
        springs[i].draw();
    }
    for(int i = 0; i < 4; i++){
        anchors[i].draw();
    }
    
}

