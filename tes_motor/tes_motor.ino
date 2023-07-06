
int dataRead;

const int In1_motorR = 3;
const int In2_motorR = 2;
const int Enable_motorR = 10;

const int In1_motorL = 4;
const int In2_motorL = 6;
const int Enable_motorL = 11;

const int led_red = 2;
const int led_yellow = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

  pinMode (led_red, OUTPUT);
  pinMode (led_yellow, OUTPUT);
  
  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);
  
}

void Maju () {
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, 500);
 
  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 500);
}

void Mundur () {
  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 500);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, 500);
}

void Kanan () {
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, 500);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, 500);
}

void Kiri () {
   digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 500);
 
  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 500);
}

void Stop () {
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, 0);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available () > 0) {
    dataRead = Serial.read ();
  }

  if (dataRead == 1) {
    Maju ();
    digitalWrite (led_red, HIGH);
  }
  if (dataRead == 2) {
    Mundur ();
    digitalWrite (led_red, LOW);
  }
  if (dataRead == 3) {
    Kanan ();
    digitalWrite (led_yellow, HIGH);
  }
  if (dataRead == 4) {
    Kiri ();
    digitalWrite (led_yellow, LOW);
  }
  
} 
