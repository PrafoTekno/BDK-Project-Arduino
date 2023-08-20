
const int led = 6;
int blink_num;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  pinMode (led, OUTPUT);

  Serial.println ("Come make me blink\n");
    
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite (led, LOW);
  
  Serial.print ("\nHow many blinks you want? ");
  while (Serial.available () == 0);
  blink_num = Serial.parseInt ();
  Serial.println (blink_num); 
  
  for (int i = 0; i < blink_num; i++) {
    
    Serial.print ("blink_num = ");
    Serial.println (i+1);
    
    digitalWrite (led, HIGH);
    delay (300);
    digitalWrite (led, LOW);
    delay (300);
    
  }
  
}
