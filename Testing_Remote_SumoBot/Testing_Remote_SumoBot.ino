
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (7, 8); // CE, CSN
const byte address[6] = "00001";
int pesan[1] = {0};
int pesan1[1] = {0};

const int led = 3;
int brightness;

void setup() {
  
  Serial.begin(9600);
  pinMode (led, OUTPUT);
  //pinMode (led1, OUTPUT);

  //delay (100);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
}

void loop() {
  
  while (radio.available()) {
    
    radio.read (pesan, 1);
    //radio.read (pesan1, 1);
    
    brightness = map (pesan[0],0,255,0,255);
    analogWrite (led, brightness);
    
    Serial.println (pesan[0]);
    //Serial.print (" | ");
    //Serial.println (pesan1[0]);
    //delay (10);
    
  }
}
