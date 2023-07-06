#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  //Serial.begin (9600);
}

void loop() {
  const char text[] = "Hello";
  radio.write(&text, sizeof(text));
  delay(100);
}
