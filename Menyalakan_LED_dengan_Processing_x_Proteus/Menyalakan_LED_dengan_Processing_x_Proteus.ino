
const int led = 13;
const int blue = 2;

int dataRead;

void setup () {

  Serial.begin (9600);

  pinMode (led, OUTPUT);
  pinMode (blue, OUTPUT);
  
}

void loop () {

  digitalWrite (blue, HIGH);
  
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
