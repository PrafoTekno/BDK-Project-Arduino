
const int blue = 3;
int dataRead = 0;
float kecerahan = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  pinMode (blue, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available () > 0) {
    dataRead = Serial.read ();
  }

  kecerahan = map (dataRead,40,360,0,255);
  analogWrite (blue, kecerahan);
  
}
