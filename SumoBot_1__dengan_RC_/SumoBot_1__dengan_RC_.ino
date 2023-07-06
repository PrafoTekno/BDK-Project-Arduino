
// Remote
#define ch1 A1
#define ch2 A0

double ch1_val, ch2_val;
double ch1_nilai, ch2_nilai;

// R = A
// L = B

const int In1_motorR = 3;
const int In2_motorR = 4;
const int Enable_motorR = 9;

int speedR;

const int In1_motorL = 8;
const int In2_motorL = 2;
const int Enable_motorL = 10;

int speedL;

void setup() {
  // put your setup code here, to run once:

  pinMode (ch1, INPUT);
  pinMode (ch2, INPUT);
  
  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  ch1_val = pulseIn (ch1, HIGH);
  ch2_val = pulseIn (ch2, HIGH);

  ch1_nilai = map (ch1_val, 0, 2030, 0, 200);
  ch2_nilai = map (ch2_val, 0, 2030, 0, 200);

  Serial.print ("ch1 : ");
  Serial.print (ch1_nilai);
  Serial.print (" | ch2 : ");
  Serial.println (ch2_nilai);
  delay (100);
  
  if (ch1_nilai >= 167 && ch1_nilai <= 200) {
    
    speedR = 500;
    speedL = 500;
    Kanan ();
    
  }
  else if (ch1_nilai <= 130 && ch1_nilai >= 95) {
    
    speedR = 500;
    speedL = 500;
    Kiri ();
    
  }
  else if (ch2_nilai <= 150 && ch2_nilai >= 142) {
     
     speedR = 500;
     speedL = 500;
     Maju ();
    
  }
  else if (ch2_nilai <= 195 && ch2_nilai >= 180) {
      
      speedR = 500;
      speedL = 500;
      Mundur ();
    
  }
  else {
    Stop ();
  }
  
}

void Mundur () {

  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, speedL);
  
}

void Maju_Kanan () {
  
  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Maju_Kiri () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Mundur_Kanan () {

  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, speedL);
  
}

void Mundur_Kiri () {

  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
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

void Maju () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Kanan () {
 
  digitalWrite (In1_motorR, HIGH);
  digitalWrite (In2_motorR, LOW);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, HIGH);
  digitalWrite (In2_motorL, LOW);
  analogWrite (Enable_motorL, speedL);
  
}

void Kiri () {

  digitalWrite (In1_motorR, LOW);
  digitalWrite (In2_motorR, HIGH);
  analogWrite (Enable_motorR, speedR);

  digitalWrite (In1_motorL, LOW);
  digitalWrite (In2_motorL, HIGH);
  analogWrite (Enable_motorL, speedL);
  
}
