//initiating the values: 3 LEDS of red, yellow and green
//two buttons
  
  int r = 12;
  int y = 11;
  int g = 10;

  int buttonR = 2;
  int buttonG = 4;

  int buttonStateR = 0;
  int buttonStateG = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(buttonR, INPUT);
  pinMode(buttonG, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //two buttons, buttonR turns on the red light and buttonG turns on the green light
  buttonStateR = digitalRead(buttonR);
  buttonStateG = digitalRead(buttonG);

  //start with a green light
  digitalWrite(g, HIGH);
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  
  //when buttonR pressed, the yellow light blinks twice and then the red light comes on
  if(buttonStateR ==HIGH){
      digitalWrite(g, LOW);
      digitalWrite(y, HIGH);
      delay(500);
      digitalWrite(y, LOW);
      delay(500);
      digitalWrite(y, HIGH);
      delay(500);
      digitalWrite(y, LOW);
      delay(500);
      digitalWrite(r, HIGH);
  } else {
//    digitalWrite(y, LOW);
  }

  //when buttonG pressed, the green light turns immediately on and the other two are off
  if(buttonStateG ==HIGH){
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      digitalWrite(g, HIGH);
  } else {
//    digitalWrite(y, LOW);
  }
  
}
