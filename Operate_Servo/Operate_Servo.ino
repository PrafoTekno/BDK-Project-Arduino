
#include <Servo.h>
Servo myServo;
int rotate = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  myServo.attach (3);
  Serial.println ("Mengatur Sudut Servo\n");

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print ("\nBerapa derajat ? ");
  while (Serial.available () == 0);
  rotate = Serial.parseInt ();

  myServo.write (rotate);

}
