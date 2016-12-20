#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Jelly.hpp"
#include "Algae.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    Jelly jelly1;
    
    vector<Algae> algaes;
    int num;
    
    ofEasyCam cam;
    
    ofxPanel gui;
    ofxFloatSlider rad1;
    ofxFloatSlider rad2;
    
    ofxFloatSlider degree;
    
    ofxFloatSlider a;
    ofxFloatSlider b;
};