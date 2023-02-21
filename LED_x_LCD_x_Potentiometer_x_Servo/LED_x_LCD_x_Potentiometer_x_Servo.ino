
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16,2);

const int red = 3;
int brightness = 0;

const int pot_pin = A3;
int pot_status = 0;

#include <Servo.h>
Servo myServo;
int rotate;

void setup() {
  // put your setup code here, to run once:

  lcd.init ();
  lcd.clear ();
  lcd.backlight ();

  pinMode (red, OUTPUT);
  pinMode (pot_pin, INPUT);
  myServo.attach (5);

}

void loop() {
  // put your main code here, to run repeatedly:

  pot_status = analogRead (pot_pin);

  brightness = map (pot_status, 0, 1023, 0, 255);
  rotate = map (pot_status, 0, 1023, 0, 180);

  analogWrite (red, brightness);
  myServo.write (rotate);
  delay (20);

  lcd.setCursor (3,0);
  lcd.print ("Pengukuran");

  lcd.setCursor (0,1);
  lcd.print ("Status POT: ");
  lcd.print (pot_status);

}
