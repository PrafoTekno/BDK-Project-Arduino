
const int led = 3;
int brightness;

int read_val;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin (9600);
  pinMode (led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly
  
  if (Serial.available () > 0) {
    read_val = Serial.read ();
  }
  
  brightness = map (read_val,40,360,0,255);
  analogWrite (led, brightness);
  
}
