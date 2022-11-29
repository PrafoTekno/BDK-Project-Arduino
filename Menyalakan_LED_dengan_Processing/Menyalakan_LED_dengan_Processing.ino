
const int led = 13;
int dataRead;

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

  if (dataRead == 1) {
    digitalWrite (led, HIGH);
  }
  else {
      digitalWrite (led, LOW);
  }
  
}
