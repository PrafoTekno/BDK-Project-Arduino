

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin (9600);
    
}

void loop() {
  // put your main code here, to run repeatedly:

  int x_value = analogRead (A0);
  int y_value = analogRead (A1);

  String x = "x value : ";
  String y = " | y value : ";

  Serial.print (x + x_value);
  Serial.println (y + y_value);
  delay (100);
  
}
