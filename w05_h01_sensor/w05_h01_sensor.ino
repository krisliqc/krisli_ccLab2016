// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at http://www.ardublog.com
// Wiki: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04/wiki/Plug-&-Play

#include <Ultrasonic.h>

Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)
int distance;


//setting all LED outputs
int g1 = 13;
int g2 = 12;
int y1 = 11;
int y2 = 10;
int r1 = 9;
int r2 = 8;


void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode

  // setting all initial values to LOW
  digitalWrite(g1, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(y1, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(y2, LOW);
}

void loop()
{
//  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  delay(100);

  distance = ultrasonic.Ranging(CM);
  Serial.println(distance);

  //using if/else statements to seperate all intervals
  //then define each LED's state within each interval
  //there must be a cleaner way to do this... 

  if(distance > 40){
     digitalWrite(g1, HIGH);
     digitalWrite(g2, LOW);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
  } else {
     if (distance > 34){
     digitalWrite(g1, HIGH);
     digitalWrite(g2, HIGH);
    digitalWrite(y1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r1, LOW);
     digitalWrite(r2, LOW);
     }
     else {
        if (distance > 28) {
        digitalWrite(g1, HIGH);
        digitalWrite(g2, HIGH);
        digitalWrite(y1, HIGH);
        digitalWrite(y2, LOW);
        digitalWrite(r1, LOW);
       digitalWrite(r2, LOW);
        } else {
          if (distance > 22) {
            digitalWrite(g1, HIGH);
            digitalWrite(g2, HIGH);
            digitalWrite(y1, HIGH);
            digitalWrite(y2, HIGH);
              digitalWrite(r1, LOW);
                   digitalWrite(r2, LOW);
          } else {
            if (distance > 10) {
              digitalWrite(g1, HIGH);
              digitalWrite(g2, HIGH);
              digitalWrite(y1, HIGH);
              digitalWrite(y2, HIGH);
              digitalWrite(r1, HIGH);
               digitalWrite(r2, LOW);
              } else {
                 if (distance > 0) {
                   digitalWrite(g1, HIGH);
                   digitalWrite(g2, HIGH);
                   digitalWrite(y1, HIGH);
                   digitalWrite(y2, HIGH);
                   digitalWrite(r1, HIGH);
                   digitalWrite(r2, HIGH);
                   } 
                }
              }
          }
      }
  }
}


//code reference: http://arduino.sundh.com

//#define echoPin 11 // Echo Pin
//#define trigPin 12 // Trigger Pin
// 
//long duration, distance; // Duration used to calculate distance 
//
//void setup() {
// Serial.begin (9600);
// pinMode(trigPin, OUTPUT);
// pinMode(echoPin, INPUT);
//}
// 
//void loop() {
// digitalWrite(trigPin, LOW);
// delayMicroseconds(2);
// 
// digitalWrite(trigPin, HIGH);
// delayMicroseconds(10);
// 
// digitalWrite(trigPin, LOW);
// duration = pulseIn(echoPin, HIGH);
// 
// //Calculate the distance (in cm) based on the speed of sound.
// distance = duration/58.2;
// 
// Serial.println(distance);
// 
// delay(50);
//}
