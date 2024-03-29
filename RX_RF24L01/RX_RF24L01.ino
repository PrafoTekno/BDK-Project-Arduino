
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 6); // CE, CSN
int pesan [4];
const byte address[6] = "00013";

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

//const int led = 13;

void setup() {

  pinMode (In1_motorR, OUTPUT);
  pinMode (In2_motorR, OUTPUT);
  pinMode (Enable_motorR, OUTPUT);

  pinMode (In1_motorL, OUTPUT);
  pinMode (In2_motorL, OUTPUT);
  pinMode (Enable_motorL, OUTPUT);
  
  Serial.begin(9600);
  //pinMode (led, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  
}

void loop() {
  
  while (radio.available()) {

    int pb_yellow = pesan[0];
    int pb_red = pesan[1];
    int pos_x = pesan[2];
    int pos_y = pesan[3];
    
    radio.read (pesan, sizeof (pesan));
    
    if (pb_yellow == 1 && pb_red == 0) { // Maju kuning

      if (pos_y >= 0 && pos_y <= 49) {
        speedR = 500;
        speedL = 75;
        Maju_Kiri ();
      }
      else if (pos_y >= 51 && pos_y <= 99) {
        speedR = 75;
        speedL = 500;
        Maju_Kanan ();
      }
      else {
        speedR = 500;
        speedL = 500;
        Maju ();
      }
      
      
    }
    else if (pb_yellow == 0 && pb_red == 1) { // Mundur merah
      
      if (pos_y >= 0 && pos_y <= 49) {
        speedR = 75;
        speedL = 500;
        Mundur_Kiri ();
      }
      else if (pos_y >= 51 && pos_y <= 99) {
        speedR = 500;
        speedL = 75;
        Mundur_Kanan ();
      }
      else {
        speedR = 500;
        speedL = 500;
        Mundur ();    
      }
    
    }
    else if (pos_y >= 0 && pos_y <= 49) {

      if (pb_yellow == 1 && pb_red == 0) {
        speedR = 500;
        speedL = 75;
        Maju_Kiri ();
      }
      else if (pb_yellow == 0 && pb_red == 1) {
        speedR = 75;
        speedL = 500;
        Mundur_Kiri ();
      }
      else {
        speedR = 500;
        speedL = 500;
        Kiri ();  
      }
      
    }
    else if (pos_y >= 51 && pos_y <= 99 ) {
      
      if (pb_yellow == 1 && pb_red == 0) {
        speedR = 75;
        speedL = 500;
        Maju_Kanan ();
      }
      else if (pb_yellow == 0 && pb_red == 1) {
        speedR = 500;
        speedL = 75;
        Mundur_Kanan ();
      }
      else {
        speedR = 500;
        speedL = 500;
        Kiri ();  
      }

    }
    else {
      Stop ();
    }

    Serial.print ("Maju : ");
    Serial.print (pesan[0]);
    Serial.print (" | y : ");
    Serial.print (pesan[3]);
    Serial.print (" | Enable R : ");
    Serial.println (Enable_motorR); 
    delay (100);
   
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
