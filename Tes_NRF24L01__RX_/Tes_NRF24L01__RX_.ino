#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  char text[32] = "";
  
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    String transdata = String (text);
    Serial.println(text);
  }
}
