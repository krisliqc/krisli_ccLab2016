//
//  particles.hpp
//  w09_h01_firework
//
//  Created by Kris Li on 11/8/16.
//
//


#pragma once

#include "ofMain.h"

class Particle{
    
public:
    
    void draw();
    void setup();
    void explosion();
    void update();
    
    void restart();
    
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    
    float radius;
    int someNumber;
    
};


