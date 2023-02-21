
// Ultrasonic Sensor
#define trig_pin 8
#define echo_pin 9
long duration, distance;

// LED
const int red = 3;
const int led = 13;

// Bipolar Stepper Motor
const int dir_pin = 2;
const int step_pin = 6;
int step_per_rotasi = 0;

// Switch
#define switch_pin 5
int switch_status = 0;

// Machine Learning 
float kecepatan_target = 0;
const float konstanta = 50.0;
float nilai_sembarang = 0.2;
float error = 0; 

float kecepatan_update (float c, float m) {
  
  float hasil;
  hasil = c * m;
  return hasil;

}

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

  pinMode (trig_pin, OUTPUT);
  pinMode (echo_pin, INPUT);

  pinMode (red, OUTPUT);
  pinMode (led, OUTPUT);

  pinMode (dir_pin, OUTPUT);
  pinMode (step_pin, OUTPUT);

  pinMode (switch_pin, INPUT);

}

void Jarak () {

 digitalWrite (trig_pin, LOW);
 delayMicroseconds (2);
 digitalWrite (trig_pin, HIGH);
 delayMicroseconds (10);
 digitalWrite (trig_pin, LOW);

 duration = pulseIn (echo_pin, HIGH);
 distance = duration/58;
 //delay (200);

 if (distance <= 50) {
   digitalWrite (red, HIGH);
 } else {
   digitalWrite (red, LOW);
 }

}

void Pengereman () {

  kecepatan_target = distance * 1.3;
  error = kecepatan_target - kecepatan_update (konstanta, nilai_sembarang);

  while (true) {

    if (error <= 0) {
      
      break;
    
    }

    else {

      nilai_sembarang = nilai_sembarang + 0.01;

    }

  }

}

void Gerak_Motor () {

  switch_status = digitalRead (switch_pin);

  if (switch_status != 1) {
      step_per_rotasi = 200;
    } else {
      step_per_rotasi = 0;
    }

  digitalWrite (dir_pin, HIGH); // Muter searah jarum jam
  Pengereman ();

  for (int s = 0; s < step_per_rotasi; s++) {

    digitalWrite (step_pin, HIGH);
    delayMicroseconds (kecepatan_update (konstanta, nilai_sembarang)); //Mengatur kecepatan putaran roda
    digitalWrite (step_pin, LOW);
    delayMicroseconds (kecepatan_update (konstanta, nilai_sembarang));

  }

  Serial.println (kecepatan_update (konstanta, nilai_sembarang));

}

void loop() {
  // put your main code here, to run repeatedly:

  Jarak ();
  Gerak_Motor ();

}
