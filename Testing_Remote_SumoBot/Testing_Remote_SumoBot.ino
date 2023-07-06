
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (7, 8); // CE, CSN
const byte address[6] = "00001";
int pesan[1] = {0};

const int pb = 3;
int status_pb;

void setup() {

  pinMode (pb, INPUT_PULLUP);
  
  radio.begin ();
  radio.openWritingPipe (address);
  radio.setPALevel (RF24_PA_MAX);
  radio.stopListening ();
  
}

void loop() {

  status_pb = digitalRead (pb);
  pesan[0] = status_pb;
  
  radio.write (pesan, 1); 
  //delay (10);
 
}
