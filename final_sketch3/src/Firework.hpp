//
//  Firework.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/15/16.
//
//

#pragma once

#include "ofMain.h"

class Firework{
    
public:
    
    void draw();
    void setup(ofPoint _pos);
    void explosion();
    
    void restart(ofPoint _pos);
    
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    
    float radius;
    int someNumber;
    
};


