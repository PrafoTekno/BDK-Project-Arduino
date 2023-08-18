
#include <Servo.h>
Servo myServo;

const int led = 13;

const int trig = 2;
const int echo = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  
  pinMode (led, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);

  myServo.attach (5);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long distance, duration;

  digitalWrite (trig, LOW);
  delayMicroseconds (2);
  digitalWrite (trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  
  duration = pulseIn (echo, HIGH);
  distance = duration/58;
  
  Serial.print (distance);
  Serial.println (" cm");
  delay (200);

  if (distance <= 10) {
    digitalWrite (led, HIGH);
    myServo.write (180);
  }
  else {
    digitalWrite (led, LOW);
    myServo.write (0);
  }
 
  
}
