//
//  Jelly.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#pragma once
#include "ofMain.h"
#include "Arm.hpp"
#include "Bell.hpp"
#include "Tenta.hpp"
#include "Firework.hpp"

class Jelly {
public:
    Jelly();
    void init(ofPoint _pos);
    
    void addForce(ofPoint _force);
    void update(float rad1, float rad2);
    void bound();
    void draw();
    
    //bell
    Bell bellA;
    float rad1, rad2;
    
    //arm
//    vector<Arm> arms;
//    int armNum;
//    Arm arm1;
    
    //tenta
    vector<Tenta> tenticles;
    int tentaSize;
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    //firework
    vector<Firework> fireworks;
    
private:
    float damp;
    
};