
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (7, 8); // CE, CSN
const byte address[6] = "00001";
int pesan[1] = {0};
int pesan1[1] = {0};

const int led = 2;
const int led1 = 9;

#define In1 3
#define In2 4
#define In3 5
#define In4 6

void setup() {
  
  Serial.begin(9600);
  pinMode (led, OUTPUT);
  pinMode (led1, OUTPUT);

  pinMode (In1, OUTPUT);
  pinMode (In2, OUTPUT);
  pinMode (In3, OUTPUT);
  pinMode (In4, OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
}

void loop() {
  
  while (radio.available()) {
    radio.read (pesan, 1);
    radio.read (pesan1, 1);
    
    if (pesan[0] == 1) {
      
      digitalWrite (led, HIGH);
      digitalWrite (led1, LOW);
      
      digitalWrite (In1, LOW);
      digitalWrite (In2, HIGH);
      digitalWrite (In3, LOW);
      digitalWrite (In4, HIGH);
      
    }
    else {
      digitalWrite (led, LOW);
      digitalWrite (led1, LOW);
      
      digitalWrite (In1, LOW);
      digitalWrite (In2, LOW);
      digitalWrite (In3, LOW);
      digitalWrite (In4, LOW);
      
    }
    
    if (pesan1[0] == 1) {
      
      digitalWrite (led1, HIGH);
      digitalWrite (led, LOW);
      
      digitalWrite (In1, HIGH);
      digitalWrite (In2, LOW);
      digitalWrite (In3, HIGH);
      digitalWrite (In4, LOW);
      
    }
    else {
      
      digitalWrite (led1, LOW);
      digitalWrite (led, LOW);

      digitalWrite (In1, LOW);
      digitalWrite (In2, LOW);
      digitalWrite (In3, LOW);
      digitalWrite (In4, LOW);
      
    }
    delay (10);
    
  }
}
