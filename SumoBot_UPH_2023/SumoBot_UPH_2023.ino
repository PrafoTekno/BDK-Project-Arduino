
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (7,8);
const byte address[6] = "00001";
int pesan[1] = {0};

const int led = 13;

void setup() {
  
  Serial.begin(9600);
  pinMode (led, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
}

void loop() {
  
  while (radio.available()) {
    
    radio.read (pesan, 1);
    
    if (pesan[0] == 1) {
      digitalWrite (led, HIGH);
    }
    else {
      digitalWrite (led, LOW);
    }
    delay (10);
  }
  
}
