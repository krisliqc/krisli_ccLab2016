//
//  Algae.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/10/16.
//
//

#pragma once
#include "ofMain.h"

class Algae{
public:
    Algae();
    
    void init();
    void update(int _num);
    void repel(ofPoint _rep);
    void noise(float _a, float _b);
    void space(vector<Algae> *algaes);
    void bound();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    ofPoint rep;
    float damp;
    
    Boolean attract;
    
    vector <ofPoint> *attractPoints;
    
};