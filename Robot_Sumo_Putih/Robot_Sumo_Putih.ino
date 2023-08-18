#define pin1 A0  //Channel 2
#define pin2 A1  //Channel 1
#define pin3 A2  //CH 3

int pwm_value1, pwm_value2, pwm_value3, PWM1, PWM2, ratio;

//PINS: n  
/* Arduino pins (ForwardPWMLeft & ReversePWMLeft MUST be in pins with ~)
 * IF: Kanan/Kiri terbalik
 * THEN: Tukar pin kedua motor driver;
 * IF: Depan/Belakang terbalik
 * THEN: Tukar pin forwardPWM & reversePWM SESUAI DENGAN KEBUTUHAN
 */
int ForwardEnLeft = 3;//L EN LEFT MOTOR
int ReverseEnLeft = 4;//R EN LEFT MOTOR
int ForwardEnRight = 1;//L EN RIGHT MOTOR
int ReverseEnRight = 2;//R EN RIGHT MOTOR

int ForwardPWMLeft = 9;//LPWM LEFT MOTOR
int ReversePWMLeft = 10;//RPWM LEFT MOTOR
int ForwardPWMRight = 5;//L PWM RIGHT MOTOR
int ReversePWMRight = 6;//RPWM RIGHT MOTOR

//CONTROL SYSTEMS:
/* Based on the PWM reading input of both channels
 * meantime is found by average of normal position
 * maxtime and mintime must be equally spaced from the mean
 * ALWAYS USE THE SMALLER RANGE FOR DETERMINING MAXTIME AND MINTIME
 * noise is determined from trial and error, 
 * as well as intuition
 */

//Noise threshhold (use intuition)
int noise = 38;

//Calibration for channel 2
int maxtimeA = 1973;
int mintimeA = 834;
int meantimeA = 1406;

//Calibration for channel 1
int maxtimeB = 2075;
int mintimeB = 959;
int meantimeB = 1515;

//Calibration for channel 3
int meantimeC = 989;
int adjustedmax = 1968;

//Max & Min speeds (from 0 - 255)
int initialmax;
int maxPWM = 255;
int minPWM = 80;

//Hybrid proportions
int propmax = 6;
int propmin = 1;

void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);

  pinMode(ForwardEnLeft, OUTPUT);
  pinMode(ReverseEnLeft, OUTPUT);
  pinMode(ForwardEnRight, OUTPUT);
  pinMode(ReverseEnRight, OUTPUT);
  
  pinMode(ForwardPWMLeft, OUTPUT);
  pinMode(ReversePWMLeft, OUTPUT);
  pinMode(ForwardPWMRight, OUTPUT);
  pinMode(ReversePWMRight, OUTPUT);

  digitalWrite(ForwardEnLeft,HIGH);
  digitalWrite(ReverseEnLeft,HIGH);
  digitalWrite(ForwardEnRight,HIGH);
  digitalWrite(ReverseEnRight,HIGH);
  
  Serial.begin(115200);
  PWM1 = 0;
  PWM2 = 0;
  initialmax = maxPWM;
}
 
void loop() {

  
Serial.print(pulseIn(pin1,255));//CHANNEL 2
Serial.print(" ");
Serial.println(pulseIn(pin2,255));//CHANNEL 1


  pwm_value1=constrain(pulseIn(pin1,255),mintimeA,maxtimeA);
  pwm_value2=constrain(pulseIn(pin2,255),mintimeB,maxtimeB);
  //pwm_value3=pulseIn(pin3,255);

  //Serial.println(pwm_value1);

  if (pwm_value2 < (meantimeB+noise) && pwm_value2 > (meantimeB-noise))
  { //Kanan Kiri diam
    if (pwm_value1 < (meantimeA+noise) && pwm_value1 > (meantimeA-noise))
    {//Depan Belakang diam
      analogWrite(ForwardPWMLeft, 0);
      analogWrite(ReversePWMLeft, 0);
      analogWrite(ForwardPWMRight, 0);
      analogWrite(ReversePWMRight, 0);
    }
    else if (pwm_value1 <= (meantimeA-noise))
    {//Depan
      PWM1=map(pwm_value1,(meantimeA-noise),mintimeA,minPWM,maxPWM);
      PWM2 = PWM1;
      analogWrite(ForwardPWMLeft,PWM1);
      analogWrite(ReversePWMLeft,0);
      analogWrite(ForwardPWMRight,PWM2);
      analogWrite(ReversePWMRight,0);
    }
    else if (pwm_value1 >= (meantimeA+noise))
    {//Belakang
      PWM1=map(pwm_value1,(meantimeA+noise),maxtimeA,minPWM,maxPWM);
      PWM2 = PWM1;
      analogWrite(ForwardPWMLeft,0);
      analogWrite(ReversePWMLeft,PWM1);
      analogWrite(ForwardPWMRight,0);
      analogWrite(ReversePWMRight,PWM2);
    }
  }
  else if (pwm_value2 <= (meantimeB-noise))
  {//Kiri
    if (pwm_value1 < (meantimeA+noise) && pwm_value1 > (meantimeA-noise))
    {//Depan Belakang diam
      PWM2=map(pwm_value2,(meantimeB-noise),mintimeB,minPWM,maxPWM);
      PWM1 = PWM2;
      analogWrite(ForwardPWMLeft,PWM1);
      analogWrite(ReversePWMLeft,0);
      analogWrite(ForwardPWMRight,0);
      analogWrite(ReversePWMRight,PWM2);
    }
    else if (pwm_value1 <= (meantimeA-noise))
    {//Depan
      PWM1=map(pwm_value1,(meantimeA-noise),mintimeA,minPWM,maxPWM);
      ratio=map(pwm_value2,(meantimeB-noise),mintimeB,propmin,propmax);
      PWM2 = PWM1/ratio;
      analogWrite(ForwardPWMLeft,PWM1);
      analogWrite(ReversePWMLeft,0);
      analogWrite(ForwardPWMRight,PWM2);
      analogWrite(ReversePWMRight,0);
    }
    else if (pwm_value1 >= (meantimeA+noise))
    {//Belakang
      PWM1=map(pwm_value1,(meantimeA+noise),maxtimeA,minPWM,maxPWM);
      ratio=map(pwm_value2,(meantimeB-noise),mintimeB,propmin,propmax);
      PWM2 = PWM1/ratio;
      analogWrite(ForwardPWMLeft,0);
      analogWrite(ReversePWMLeft,PWM1);
      analogWrite(ForwardPWMRight,0);
      analogWrite(ReversePWMRight,PWM2);
    }
  }
  else if (pwm_value2 >= (meantimeB+noise))
  {//Kanan
    if (pwm_value1 < (meantimeA+noise) && pwm_value1 > (meantimeA-noise))
    {//Depan Belakang diam
      PWM2=map(pwm_value2,(meantimeB+noise),maxtimeB,minPWM,maxPWM);
      PWM1 = PWM2;
      analogWrite(ForwardPWMLeft,0);
      analogWrite(ReversePWMLeft,PWM1);
      analogWrite(ForwardPWMRight,PWM2);
      analogWrite(ReversePWMRight,0);
    }
    else if (pwm_value1 <= (meantimeA-noise))
    {//Depan
      PWM2=map(pwm_value1,(meantimeA-noise),mintimeA,minPWM,maxPWM);
      ratio=map(pwm_value2,(meantimeB+noise),maxtimeB,propmin,propmax);
      PWM1 = PWM2/ratio;
      analogWrite(ForwardPWMLeft,PWM1);
      analogWrite(ReversePWMLeft,0);
      analogWrite(ForwardPWMRight,PWM2);
      analogWrite(ReversePWMRight,0);
    }
    else if (pwm_value1 >= (meantimeA+noise))
    {//Belakang
      PWM2=map(pwm_value1,(meantimeA+noise),maxtimeA,minPWM,maxPWM);
      ratio=map(pwm_value2,(meantimeB+noise),maxtimeB,propmin,propmax);
      PWM1 = PWM2/ratio;
      analogWrite(ForwardPWMLeft,0);
      analogWrite(ReversePWMLeft,PWM1);
      analogWrite(ForwardPWMRight,0);
      analogWrite(ReversePWMRight,PWM2);
    }
  }
}
