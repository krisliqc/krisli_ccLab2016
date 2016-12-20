//
//  Tenta.hpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#pragma once
#include "ofMain.h"
#include "Bell.hpp"
#include "Anchor.hpp"
#include "Spring.hpp"

class Tenta {
public:
    
    Tenta();
    void init(ofPoint _pos);
    void update(ofPoint _pos, float _length);
    void draw();
    
    
    ofPolyline hand;
    ofPolyline handS;
    ofPoint pos;
    
    Bell myBell;
    
    //myBell.linksp[0];
    
    
private:
    
    int size;
    float angle;
    float angleCons;
    
    int res;
    float length;
    float width;
    int smooth;
    float step;
    float stepAdd;
    
    float noise;
    vector<ofPoint> steps;
};