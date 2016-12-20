//
//  Jelly.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#include "Jelly.hpp"

Jelly::Jelly(){
    pos = ofPoint(0,0,0);
}

void Jelly::init(ofPoint _pos){
    pos = _pos;
//    vel = _vel;
    acc.set(0,0,0);
    damp = 0.995;
    
    //bell
    bellA.init(pos);
    
    //arm
//    armNum = 36;
//    for(int i = 0; i < 36; i++){
//        Arm temp;
//        arms.push_back(temp);
//        arms[i].init();
//    }
//    arm1.init();
    
    //tentacles
    tentaSize = 36;
    
    float tentAngle = PI;
    
    for(int i = 0; i < tentaSize; i ++){
        Tenta temp;
        tenticles.push_back(temp);
        
//        tenticles[i].init(ofPoint(pos.x + sin(tentAngle)*100, pos.y + cos(tentAngle)*100, 0));
        tenticles[i].init(ofPoint(0,0));
        tentAngle += PI/6;
    }
    
    
    for(int i =0; i< 80; i++){
        Firework tempVar;
        tempVar.setup(pos);
        fireworks.push_back(tempVar);
    }
}

void Jelly::update(float _rad1, float _rad2){

    ofPoint perlin;
    
    perlin.x = ofNoise(ofGetElapsedTimef()/4-1000)*ofGetWidth();
    perlin.y = ofNoise(ofGetElapsedTimef()/4+1000)*ofGetHeight();
    pos = perlin;
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
    
    //bell
    rad1 = _rad1;
    rad2 = _rad2;
    bellA.update(rad1, rad2);
    bellA.getLink();
    
    
    //arm1
//    arm1.update(bellA.links[1]);
    
    
//    
    for(int i = 0; i < 36; i ++){
        
        float noise =ofNoise(i/5,ofGetElapsedTimef()/4);
        
        tenticles[i].update(bellA.links[i],noise*20);
//        arms[i].update(bellA.links2[i]);
    }
    
}

void Jelly::draw(){
    ofSetColor(255, 0, 0);
    ofDrawCircle(pos, 10);
    
    ofPushMatrix();
    
    ofTranslate(pos);
    
    //bell
    bellA.draw(pos);
    
    for(int i = 0; i < tentaSize; i ++){
        //tentacles
        tenticles[i].draw();
        //arm
//        arms[i].draw();
    }
    
//    arm1.draw();
    
//    //link test
//    for(int i = 0; i < links.size(); i ++){
//        ofDrawCircle(links[i], 10);
//    }
    
    
    ofPopMatrix();
    
    
//    for(int i=0; i< 80; i++){
//        fireworks[i].explosion();
//        fireworks[i].draw();
//        
//        if(ofGetFrameNum() % fireworks[i].someNumber  == 0){
//            fireworks[i].restart(pos);
//        }
//    }
    
}

void Jelly::bound(){
    if( pos.x < 0.0 || pos.x > ofGetWidth()){
        pos.x -= vel.x;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0|| pos.y > ofGetHeight()){
        pos.y -= vel.y;
        vel.y *= -1.0;
    }
    
    if( pos.z < -1000.0|| pos.z > 1000.0){
        pos.z -= vel.z;
        vel.z *= -1.0;
    }
}
