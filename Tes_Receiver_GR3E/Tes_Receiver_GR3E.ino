
const int ch1_pin = A0;
const int ch2_pin = A1;

double ch1_val;
double ch2_val;

const int In1_motorR = 3;
const int In2_motorR = 4;
const int Enable_motorR = 9;

const int In1_motorL = 6;
const int In2_motorL = 2;
const int Enable_motorL = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode (ch1_pin, INPUT);
  pinMode (ch2_pin, INPUT);

  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);

  Serial.begin (9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  ch1_val = pulseIn (ch1_pin, HIGH);
  ch2_val = pulseIn (ch2_pin, HIGH);
  
  Serial.print ("Ch1 : ");
  Serial.print (ch1_val);
  Serial.print (" | Ch2 : ");
  Serial.println (ch2_val);
  delay (100);
  
}
