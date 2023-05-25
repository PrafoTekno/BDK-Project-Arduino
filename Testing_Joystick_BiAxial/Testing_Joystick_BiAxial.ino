
const int sumbu_x = A2;
const int sumbu_y = A1;
const int joystick_pin = 2;

int x_value = 0, y_value = 0, joystick_value = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  pinMode (joystick_pin, INPUT_PULLUP);
  pinMode (sumbu_x, INPUT);
  pinMode (sumbu_y, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  x_value = analogRead (sumbu_x);
  y_value = analogRead (sumbu_y);
  joystick_value = digitalRead (joystick_pin);

  Serial.print ("Nilai x = ");
  Serial.print (x_value);
  Serial.print (" | Nilai y = ");
  Serial.print (y_value);
  Serial.print (" | Nilai switch = ");
  Serial.println (joystick_value);

  //delay (600);
  
}
