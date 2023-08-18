
// Remote
#define ch1 A0
#define ch2 A1

double ch1_val, ch2_val;
double ch1_nilai, ch2_nilai;

int ForwardEnLeft = 3;//L EN LEFT MOTOR
int ReverseEnLeft = 4;//R EN LEFT MOTOR
int ForwardEnRight = 1;//L EN RIGHT MOTOR
int ReverseEnRight = 2;//R EN RIGHT MOTOR

int ForwardPWMLeft = 9;//LPWM LEFT MOTOR
int ReversePWMLeft = 10;//RPWM LEFT MOTOR
int ForwardPWMRight = 5;//L PWM RIGHT MOTOR
int ReversePWMRight = 6;//RPWM RIGHT MOTOR

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

  pinMode (ch1, INPUT);
  pinMode (ch2, INPUT);
  
  pinMode(ForwardEnLeft, OUTPUT);
  pinMode(ReverseEnLeft, OUTPUT);
  pinMode(ForwardEnRight, OUTPUT);
  pinMode(ReverseEnRight, OUTPUT);
  
  pinMode(ForwardPWMLeft, OUTPUT);
  pinMode(ReversePWMLeft, OUTPUT);
  pinMode(ForwardPWMRight, OUTPUT);
  pinMode(ReversePWMRight, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  ch1_val = pulseIn (ch1, HIGH);
  ch2_val = pulseIn (ch2, HIGH);

  Serial.print ("ch1 : ");
  Serial.print (ch1_val);
  Serial.print (" | ch2 : ");
  Serial.println (ch2_val);
  delay (100);

  if (ch1_val >= 1000 && ch1_val <= 1190) {
    Kanan ();
  }
  else if (ch1_val >= 1923 && ch1_val <= 2025) {
    Kiri ();
  }
  else if (ch2_val >= 999 && ch2_val <= 1090) {
    Mundur ();
  }
  else if (ch2_val >= 1870 && ch2_val <= 2005) {
    Maju ();
  }
  else {
    Stop ();
  }
  
}

void Maju () {
  analogWrite (ForwardEnLeft, 255);
  analogWrite (ReverseEnLeft, 255);
  digitalWrite (ForwardPWMLeft, HIGH);
  digitalWrite (ReversePWMLeft, LOW);

  analogWrite (ForwardEnRight, 255);
  analogWrite (ReverseEnRight, 255);
  digitalWrite (ForwardPWMRight, HIGH);
  digitalWrite (ReversePWMRight, LOW);
}

void Mundur () {
  analogWrite (ForwardEnLeft, 255);
  analogWrite (ReverseEnLeft, 255);
  digitalWrite (ForwardPWMLeft, LOW);
  digitalWrite (ReversePWMLeft, HIGH);

  analogWrite (ForwardEnRight, 255);
  analogWrite (ReverseEnRight, 255);
  digitalWrite (ForwardPWMRight, LOW);
  digitalWrite (ReversePWMRight, HIGH);
}

void Kanan () {
  analogWrite (ForwardEnLeft, 255);
  analogWrite (ReverseEnLeft, 255);
  digitalWrite (ForwardPWMLeft, HIGH);
  digitalWrite (ReversePWMLeft, LOW);

  analogWrite (ForwardEnRight, 255);
  analogWrite (ReverseEnRight, 255);
  digitalWrite (ForwardPWMRight, LOW);
  digitalWrite (ReversePWMRight, HIGH);
}

void Kiri () {
  analogWrite (ForwardEnLeft, 255);
  analogWrite (ReverseEnLeft, 255);
  digitalWrite (ForwardPWMLeft, LOW);
  digitalWrite (ReversePWMLeft, HIGH);

  analogWrite (ForwardEnRight, 255);
  analogWrite (ReverseEnRight, 255);
  digitalWrite (ForwardPWMRight, HIGH);
  digitalWrite (ReversePWMRight, LOW);
}

void Stop () {
  analogWrite (ForwardEnLeft, 0);
  analogWrite (ReverseEnLeft, 0);
  digitalWrite (ForwardPWMLeft, LOW);
  digitalWrite (ReversePWMLeft, LOW);

  analogWrite (ForwardEnRight, 0);
  analogWrite (ReverseEnRight, 0);
  digitalWrite (ForwardPWMRight, LOW);
  digitalWrite (ReversePWMRight, LOW);
}
