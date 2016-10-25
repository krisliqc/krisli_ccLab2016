//http://playground.arduino.cc/Interfacing/Processing

import processing.serial.*;
import cc.arduino.*;
Arduino arduino;

int posX, posY;
float velX, velY;
float dist;
float opacity;
PImage myImage; 
PImage chest;

int joyX, joyY;
float speed, acc;

PVector lastPos;
float lastVelX = 0;
float lastVelY = 0;

void setup(){
  size(700 ,700);
  myImage = loadImage("06.png");
  chest = loadImage("treasure_chest.png");
  myImage.loadPixels();
  loadPixels();
  
  //println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  arduino.pinMode(11, Arduino.OUTPUT);
  
  posX = width/2+15;
  posY = height/2;
  velX = 0;
  velY = 0;
  
  opacity = 100;
}

void draw(){
  //setup background
  image(myImage, 0,50);
  chest.resize(20,20);
  image(chest,30,145);
  
  velX = 0;
  velY = 0;
  
  //import arduino data
  joyX = arduino.analogRead(2);
  joyY = arduino.analogRead(1);
  speed = arduino.analogRead(0);
 
  println(speed);
  velX = round(map(joyX,0,1023,-1.5,1.5));
  velY = round(map(joyY,0,1023,-1.5,1.5));
  acc = map(speed,0,1023,1,3);
  
  //draw dark grid system over
  int size = 3;
  noStroke();
  for(int i=0; i<width; i+=size){
    for(int j=0; j<height; j+=size){
      float distance = dist(posX,posY,i,j);
      opacity = map(distance,0,50,0,100);
      fill(0,opacity);
      rect(i,j,size,size);
    }
  }
  
  textSize(24);
  fill(255,255,255);
  text("FIND THE TREASURE", 250, 40); 
  
  //get pix brightness of current position
  int loc = posX + posY*myImage.width;
  float bright = brightness(myImage.pixels[loc]);
  println("brightness is" +bright);
  
  
  //test for the walls and bounce off
  if(bright < 100){    
    textSize(16);
    fill(255,0,0);
    text("STAY BETWEEN THE WALLS!", posX-100, posY-50); 
    
    //velX = 0.5*-velX;
    //velY = 0.5*-velY;
    
    //posX = round(lastPos.x);
    //posY = round(lastPos.y);
    //velX = lastVelX;
    //velY = lastVelY;
  }
  
  //bounding
  if(posX < 0 || posX > width || posY < 0 || posY > height){
    velX = 0;
    velY = 0;
  }
  
  //update
  velX *= acc;
  velY *= acc;
  println("vel x is" + velX);
  posX += velX;
  posY += velY;
  
  fill(255,0,0);
  ellipse(posX, posY, 7,7);
  
  //check for treasure
  if(posX < 45 && posX > 35 && posY <155 && posY > 145){
    
    textSize(16);
    fill(0,255,0);
    text("YOU HAVE FOUND THE TREASURE!", posX + 20, posY+5); 
  }
  
  lastPos = new PVector(posX, posY);
  lastVelX = velX;
  lastVelY = velY;
}

//to test on desktop keyboard control
//void keyPressed(){
//  if(key ==CODED){
//    if(keyCode ==UP){
//      velY = -2;
//    } else if(keyCode ==DOWN){
//      velY = 2;
//    } else if(keyCode ==LEFT){
//      velX = -2;
//    } else if(keyCode ==RIGHT){
//      velX = 2;
//    } else {
//      velX = 0;
//      velY = 0;
//    }
//  }
//}