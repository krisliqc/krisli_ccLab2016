//
//  Tenta.cpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#include "Tenta.hpp"

Tenta::Tenta(){
    step = 500;
    stepAdd = 500;
    res = 20;
    length = 1;
    width = 1;
    smooth = 2;
    
    angle = 0;
    angleCons = PI;
}

void Tenta::init(ofPoint _pos){
    pos = _pos;
    
    ofPoint temp;
    steps.push_back(temp);
}

void Tenta::update(ofPoint _pos, float _length){
    steps.clear();
    
    pos = _pos;
    length = _length;
    hand.clear();
    
    for(int i=0; i< res; i++){
        float x, y, z;
        x = pos.x + sin(angle*i)*i*width + sin(angle)*i*width;
        y = pos.y + cos(angle)*i*width + ofNoise(ofGetElapsedTimef()/4);
        z = pos.z + i*(i+length);
        hand.addVertex(x,y,z);
        steps.push_back(ofPoint(x,y,z));
    }
    
    angle += PI/step;
    angleCons += PI/stepAdd;
    
    if(angle > 2*PI){
        angle = 0;
    }
    
}

void Tenta::draw(){
    
    ofSetColor(220, 88, 38);
//    hand.draw();
    
    handS = hand.getSmoothed(smooth);
    for(int i = 0; i < 10; i++){
        
        ofSetColor(220, 88, 38,20-2*i);
        ofSetLineWidth(4*i);
//        handS.draw();
    }

    for(int i=0; i< res; i++){
        
        noise = ofNoise(ofGetElapsedTimef()/10,i/10);
        ofSetColor(250-noise*50,noise*100,noise * 50);
        ofDrawSphere(steps[i], 4*sin(angle*i/10)+i/6);
    }
}




