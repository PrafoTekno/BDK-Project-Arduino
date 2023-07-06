
#define ch1 A2
#define ch2 A1

double ch1_val, ch2_val;

const int In1_motorR = 3;
const int In2_motorR = 2;
const int Enable_motorR = 10;

int speedR;

const int In1_motorL = 4;
const int In2_motorL = 6;
const int Enable_motorL = 11;

int speedL;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  
  pinMode (ch1, INPUT);
  pinMode (ch2, INPUT);

  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  ch1_val = pulseIn (ch1, HIGH);
  ch2_val = pulseIn (ch2, HIGH);

  Serial.print ("ch2 = ");
  Serial.print (ch1_val);
  Serial.print (" | ch1 = ");
  Serial.println (ch2_val);
  delay (100); 

  if (ch2_val >= 1000 && ch2_val <= 1190) {
    speedR = 500;
    speedL = 500;
    Maju ();
  }
  else if (ch2_val >= 1930 && ch2_val <= 1990) {
    speedR = 500;
    speedL = 500;
    Mundur ();
  }
  else if (ch1_val >= 1855 && ch1_val <= 1990) {
    speedR = 500;
    speedL = 500;
    Kanan ();
  }
  else if (ch1_val >= 995 && ch1_val <= 1127) {
    speedR = 500;
    speedL = 500;
    Kiri ();
  }
  else {
    speedR = 0;
    speedL = 0;
    Stop ();
  }
    
}

void Kanan () {

  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, speedL);
  
}

void Kiri () {
  
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);
 
  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Maju () {
  
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, speedL);
  
}

void Mundur () {
  
  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);
 
  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Stop () {
  
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);
 
  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}
  
