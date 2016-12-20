//
//  Bell.cpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#include "Bell.hpp"

Bell::Bell(){
    gridScale = 10;
    size = 360/gridScale;
    
    radius = 100;
    angle = 0;
}

void Bell::init(ofPoint pos){
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(j, 0, size, 0, 2*PI);
            phi = ofMap(i, 0, size, 0, 2*PI);
            
            float a = radius*abs(cos(theta))*sin(phi);
            float b = radius*abs(cos(theta))*cos(phi);
            float c = radius*sin(theta);
            bell.addVertex(ofPoint(a,b,c));
            bell.addColor(ofColor(252,244,162));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size-1; i++){
        for(int j = 0; j <size-1; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            bell.addTriangle(i1, i2, i3);
            bell.addTriangle(i2, i3, i4);
        }
    }
    
    //links
    linksNum = 36;
    for(int i=0; i < linksNum; i ++){
        ofPoint temp = ofPoint(0,0);
        links.push_back(temp);
    }
    
    linksNum = 36;
    for(int i=0; i < linksNum; i ++){
        ofPoint temp = ofPoint(0,0);
        links.push_back(temp);
    }
}

void Bell::update(float _rad1, float _rad2){
    bell.clear();
    
    rad1 = _rad1;
    rad2 = _rad2;
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(j, 0, size, rad1, rad2);
            phi = ofMap(i, 0, size, PI, 108/36*PI);
            
            float a = radius*abs(cos(theta))*sin(phi);
            float b = radius*abs(cos(theta))*cos(phi);
            float c = radius*sin(theta);
            bell.addVertex(ofPoint(a,b,c));
            bell.addColor(ofColor(252,244,162));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size-1; i++){
        for(int j = 0; j <size-1; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            bell.addTriangle(i1, i2, i3);
            bell.addTriangle(i2, i3, i4);
        }
    }
    
    
    for(int i = 0; i <size-1; i++){
        i1 = i + size*(size-1);
        i2 = i + 1 + size*(size - 1);
        i3 = i;
        i4 = i+1;
        
        bell.addTriangle(i1, i2, i3);
        bell.addTriangle(i2, i3, i4);
        
    }
//
//    
//    bell.addTriangle(684, 649, 720);
//    bell.addTriangle(649, 720, 685);
    
    float time = ofGetElapsedTimef();
    
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = bell.getVertex(index);
            
            float perlin = ofNoise(j*0.05, time *0.5);
//            radius = 175+ (perlin * 100);
            radius = 200 + sin(perlin)*50;
            
            bell.setVertex(index, p.normalize()*radius);
            bell.setColor(index, ofColor(250, perlin*250, perlin*100,75));
            
        }
    }
    
    angle += PI/72;
}


void Bell::getLink(){
    links.clear();
    links2.clear();
    theta = rad2;
    
//    for(int i = 0; i < links.size(); i ++){
//        i = ofMap(i, 0, links.size(), 0, 2*PI);
//        float a = radius*abs(cos(theta))*sin(i);
//        float b = radius*abs(cos(theta))*cos(i);
//        float c = radius*sin(theta);
//        ofPoint temp = ofPoint(a,b,c);
//        links.push_back(temp);
    
//        if (links.size() > linksNum){
//                    links.erase(links.begin());
//                }
    
    
//    cout << "links[1] = " << links[1].y << endl;

    for(int i = 0; i < 36*36; i+=36){
        ofPoint temp = bell.getVertex(i);
        links.push_back(temp);
    }

    for(int i = 12; i < 36*36; i+=36){
        ofPoint temp = bell.getVertex(i);
        links2.push_back(temp);
    }
//    one = bell.getVertex(5);
//    cout << "one x = " << one.y << endl;

}

void Bell::draw(ofPoint _pos){
    ofPoint pos = _pos;
    
    ofPushMatrix();
    
//    ofTranslate(pos);
    ofSetLineWidth(1);
    bell.drawWireframe();
    
    for(int i = 0; i < links.size(); i ++){
    ofSetColor(255,0,0,30);
//    ofDrawSphere(links[i], 20);
    }
    bell.draw();
    
    ofPopMatrix();
}





