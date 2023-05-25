
const int led = 2;

void setup() {
  // put your setup code here, to run once:
 pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (led, LOW);
  delay (200);
  digitalWrite (led, HIGH);
  delay (800);
}
