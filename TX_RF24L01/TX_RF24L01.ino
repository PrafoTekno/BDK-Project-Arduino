
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int pesan[1] = {0};
int pesan1[1] = {0};

const int button_maju = 3;
int status_button_maju = 0;

const int button_mundur = 6;
int status_button_mundur = 0;

const int x_pos = A2;
int x_pos_val;
const int y_pos = A1;
int y_pos_val;

void setup() {
  
  pinMode (button_maju, INPUT);
  pinMode (button_mundur, INPUT);
  
  pinMode (x_pos, INPUT);
  pinMode (y_pos, INPUT);
  Serial.begin (9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  
}

void loop() {
  
  //const char text[] = "halo";
  status_button_maju = digitalRead (button_maju); 
  status_button_mundur = digitalRead (button_mundur);
  
  x_pos_val = analogRead (x_pos);
  y_pos_val = analogRead (y_pos);
  Serial.print (x_pos_val);
  Serial.print (" | ");
  Serial.println (y_pos_val);
  //delay (1000);
  
  /*
  if (status_button_maju == 1) {
    digitalWrite (led, HIGH);
  }
  if (status_button_mundur == 1) {
    digitalWrite (led, LOW);
  }
  */
  
  pesan[0] = x_pos_val + y_pos_val;
  //pesan1[0] = status_button_mundur;
  
  radio.write (pesan, 1);
  //radio.write (pesan1, 1);

  //Serial.println (pesan[0]);
  //delay (10);
  
}
