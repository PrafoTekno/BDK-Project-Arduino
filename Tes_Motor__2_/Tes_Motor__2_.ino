
// R = A
// L = B

const int In1_motorR = 3;
const int In2_motorR = 4;
const int Enable_motorR = 9;

const int In1_motorL = 8;
const int In2_motorL = 2;
const int Enable_motorL = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);
  
}

void Mundur () {

  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 255);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, 255);
  
}

void Stop () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 0);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 0);
  
}

void Maju () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, 255);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 255);
  
}

void Kanan () {
 
  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 250);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 250);
  
}

void Kiri () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, 250);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, 250);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  Maju ();
  delay (2000);
  Stop ();
  delay (2000);
  Mundur ();
  delay (2000);
  Stop ();
  delay (2000);
  Kanan ();
  delay (2000);
  Stop ();
  delay (2000);
  Kiri ();
  delay (2000);
  Stop ();
  delay (2000);
  
}
