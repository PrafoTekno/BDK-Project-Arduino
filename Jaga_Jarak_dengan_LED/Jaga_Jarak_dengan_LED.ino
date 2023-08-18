
//LED
const int led = 2;

//Ultrasonic
const int trig_pin = 4;
const int echo_pin = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

  pinMode (led, OUTPUT);

  pinMode (trig_pin, OUTPUT);
  pinMode (echo_pin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  long durasi, jarak;

  digitalWrite (trig_pin, LOW);
  delayMicroseconds (2);
  digitalWrite (trig_pin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig_pin, LOW);

  durasi = pulseIn (echo_pin, HIGH);
  jarak = durasi/58;

  // Kondisi sensor

  if (jarak < 15) {
    digitalWrite (led, HIGH);
  }
  else {
    digitalWrite (led, LOW);
  }

  // Untuk membaca sensor

  Serial.print ("Jarak : ");
  Serial.print (jarak);
  Serial.println (" cm");
  delay (100);
}
