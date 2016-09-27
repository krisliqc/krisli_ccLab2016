/* source: http://www.electroschematics.com/9809/arduino-8-bit-binary-led/ */
int button = 2;      // pin to connect the button
int presses = 0;    // variable to store number of presses
long time = 0;      // used for debounce

////this makes sure that the button press do not get misread multiple times if it is being held down
////100ms = 0.1s
long debounce = 100;  // how many ms to "debounce" 

const byte numPins = 8; // how many leds
int state;        // used for HIGH or LOW
                  // pins to connect leds
byte pins[] = {5, 6, 7, 8, 9, 10, 11, 12};
////the smallest digit is connected to 5, so pins[1] is the smallest digit

void setup()
{
  /* we setup all led pins as OUTPUT */
  for(int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(button, INPUT);
  /* use pin 2 which has interrupt 0 on Arduino UNO */
  ////??what's interrupt 0
  attachInterrupt(0, count, LOW);
}
 
void loop()
{
  /* convert presses to binary and store it as a string */
  String binNumber = String(presses, BIN);
  /* get the length of the string */
  int binLength = binNumber.length(); ////this is the position index of the LEDs,(from right to left)
  if(presses <= 8) {  // if we have less or equal to 255 presses  ////as much as the 8 LEDs can represent
                // here is the scary code
    for(int i = 0, x = 1; i < binLength; i++, x+=2) { 
      if(binNumber[i] == '0') state = LOW;
      if(binNumber[i] == '1') state = HIGH;
      digitalWrite(pins[i] + binLength - x, state);
    } 
  } else {
    // make all lEDS blink twice and reset the count back to 0
    for(int i = 0; i < binLength; i++){
      digitalWrite(pins[i], HIGH);}
    delay(1000);
    for(int i = 0; i < binLength; i++){
      digitalWrite(pins[i], LOW);}
    delay(1000);
    for(int i = 0; i < binLength; i++){
      digitalWrite(pins[i], HIGH);}
    delay(1000);
    for(int i = 0; i < binLength; i++){
      digitalWrite(pins[i], LOW);}
    delay(1000);

    presses = 0;
      
  }
  //series.print(presses);
} 
/* function to count the presses */
void count() { 
  // we debounce the button and increase the presses
  if(millis() - time > debounce)  presses++;
  time = millis();
}
