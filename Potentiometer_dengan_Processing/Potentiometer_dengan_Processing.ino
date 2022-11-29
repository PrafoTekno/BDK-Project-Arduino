
const int blue = 3;
const int pot_pin = A0;

int pot_status;
int brigthness;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

  pinMode (blue, OUTPUT);
  pinMode (pot_pin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  pot_status = analogRead (pot_pin);

  brigthness = map (pot_status, 0,1000,0,255);

  analogWrite (blue, brigthness);
  
}
