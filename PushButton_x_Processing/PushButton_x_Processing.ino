
const int red = 2;
const int pb_red = 6;
int status_pb_red = 0;

const int yellow = 3;
const int pb_yellow = 5;
int status_pb_yellow = 0;

int dataWrite = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  
  pinMode (red, OUTPUT);
  pinMode (pb_red, INPUT);
  
  pinMode (yellow, OUTPUT);
  pinMode (pb_yellow, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  status_pb_red = digitalRead (pb_red);
  status_pb_yellow = digitalRead (pb_yellow);
  
  if (status_pb_red == 1) {
    Serial.write (1);
    digitalWrite (red, HIGH);
    delay (300);
  }
  else if (status_pb_yellow == 1) {
    Serial.write (2);
    digitalWrite (yellow, HIGH);
    delay (300);
  }
  else {
    Serial.write (0);
    digitalWrite (yellow, LOW);
    digitalWrite (red, LOW);
    delay (300);
  }
  
}
