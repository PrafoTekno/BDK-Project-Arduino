
#include <Servo.h>
Servo servo_ku;
int rotate;

const int led = 6;

const int pb_pin = 5;
int pb_status = 0;

const int switch_pin = 3;
int switch_status = 0;

const int pot_pin = A2;
int pot_status;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  
  pinMode (led, OUTPUT);
  pinMode (pb_pin, INPUT);
  pinMode (switch_pin, INPUT);
  pinMode (pot_pin, INPUT);

  servo_ku.attach (9);

}

void gerak_servo () {

  for (int r = 0; r < rotate; r++) {
    servo_ku.write (r);
    delay (20);
  }
  for (int r = rotate; r > 0; r--) {
    servo_ku.write (r);
    delay (20);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  pb_status = digitalRead (pb_pin);

   if (pb_status == 1) {
     digitalWrite (led, LOW);
   } else {
     digitalWrite (led, HIGH);
   }

  pot_status = analogRead (pot_pin);
  rotate = map (pot_status,0,1023,0,180);

  switch_status = digitalRead (switch_pin);

    if (switch_status == 1) {
      gerak_servo ();
    } else {
      servo_ku.write (0);
    }

   Serial.println (pot_status);
   delay (200);

}
