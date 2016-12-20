//
//  Bell.hpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#pragma once
#include "ofMain.h"

class Bell {
public:
    
    Bell();
    void init(ofPoint _pos);
    void update(float _rad1, float _rad2);
    void draw(ofPoint _pos);
    
    void getLink();
    
    ofMesh bell;
    
    float rad1, rad2;
    
    int gridScale;
    int size;
    
    float theta;
    float phi;
    float angle;
    
    int radius;
    int i1,i2,i3,i4;
    
    vector<ofPoint> links;
    vector<ofPoint> links2;
    int linksNum;
    ofPoint one;
    
};