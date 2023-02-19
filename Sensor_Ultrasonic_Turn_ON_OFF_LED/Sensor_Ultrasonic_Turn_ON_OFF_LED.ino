
// Ultrasonic sensor
const int trig = 4;
const int echo = 3;

// LED 
const int led = 2;

void setup() {
  
  Serial.begin (9600);

  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  
  pinMode (led, OUTPUT);

}

void loop() {
  
  // Setting ultrasonic sensor

  long duration, distance;
  
  digitalWrite (trig, LOW);
  delayMicroseconds (2);
  digitalWrite (trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);

  duration = pulseIn (echo, HIGH);
  distance = duration/58;  // in cm

  if (distance > 20) {
    digitalWrite (led, LOW);
  }
  else {
    digitalWrite (led, HIGH);
  }

}
