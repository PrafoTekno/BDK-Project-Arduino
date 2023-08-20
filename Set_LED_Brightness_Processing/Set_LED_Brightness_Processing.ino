
const int led = 6;
int dataRead;
int brightness;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  pinMode (led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available () > 0) {
    dataRead = Serial.read ();
  }

  brightness = map (dataRead, 40, 260, 0, 255);
  analogWrite (led, brightness);
  
}
