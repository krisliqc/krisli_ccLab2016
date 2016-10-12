//http://playground.arduino.cc/Interfacing/Processing

import processing.serial.*;
import cc.arduino.*;
Arduino arduino;

int level;
int num;

void setup() {
  size(600, 600);
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  
  // Set the Arduino digital pins as inputs.
  //for (int i = 0; i <= 13; i++)
  //  arduino.pinMode(i, Arduino.INPUT);
  
  arduino.pinMode(12, Arduino.OUTPUT);
  arduino.pinMode(11, Arduino.OUTPUT);
  
}

void draw() {
  background(0);
  level = arduino.analogRead(0);
  
  println(level);
  int num = floor(map(level,0,1023,0,10));
  
  for(int i=0; i<num; i++){
     fill(255,150,0);
     rectMode(CENTER);
     rect(300,500-i*45,80+i*5,35);
  }
  
  if(level > 500){
    textSize(32);
    fill(255,255,0);
    text("Warning!", 240, 300); 
    arduino.digitalWrite(12, Arduino.HIGH);
    if(level > 800){
      textSize(60);
      fill(255,0,0);
      text("Danger!", 200, 400);   
      arduino.digitalWrite(11, Arduino.HIGH);
    } else {
      
      arduino.digitalWrite(11, Arduino.LOW);
      }
} else {
    arduino.digitalWrite(12, Arduino.LOW);
}
}