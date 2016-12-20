//
//  Arm.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#pragma once
#include "ofMain.h"
#include "Anchor.hpp"
#include "Spring.hpp"

class Arm {
public:
    Arm();
    
    void init();
    void update(ofPoint _pos);
    void draw();
    
    int width;
    
    //arm
    Anchor anchors[4];
    Spring springs[3];
    ofMesh armMesh;
    
    ofPoint pos;
    
private:
};