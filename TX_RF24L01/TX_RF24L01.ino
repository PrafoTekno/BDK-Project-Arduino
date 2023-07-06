
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (7, 8); // CE, CSN

const byte address[6] = "00013";
int pesan[4];

const int button_maju = 3;
int status_button_maju = 0;

const int button_mundur = 6;
int status_button_mundur = 0;

const int led = 4;
const int led1 = 2;

#define x_pos A0
#define y_pos A1
//#define sw_joystick A2

int x_pos_val;
int y_pos_val;
//int status_sw_joystick;

void setup() {

  pinMode (button_maju, INPUT_PULLUP);
  pinMode (button_mundur, INPUT_PULLUP);

  //pinMode (sw_joystick, INPUT_PULLUP);

  pinMode (led, OUTPUT);
  pinMode (led1, OUTPUT);

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

  x_pos_val = map (analogRead (x_pos), 0, 1023, 0, 100);
  y_pos_val = map (analogRead (y_pos), 0, 1023, 0, 100);
  //status_sw_joystick = digitalRead (sw_joystick);

  pesan[0] = status_button_maju;
  pesan[1] = status_button_mundur;
  pesan[2] = x_pos_val;
  pesan[3] = y_pos_val;

  if (pesan[0] == 1 || pesan[3] >= 0 && pesan[3] <= 49) { //Tombol kuning
    digitalWrite (led1, HIGH);
  }
  else {
    digitalWrite (led1, LOW);
  }

  if (pesan[1] == 1 || pesan[3] >= 51 && pesan[3] <= 99) { //Tombol merah
    digitalWrite (led, HIGH);
  }
  else {
    digitalWrite (led, LOW);
  }
  
  Serial.print ("x : ");
  Serial.print (pesan[2]);
  Serial.print (" | y : ");
  Serial.println (pesan[3]);
  
  //Serial.print (" | sw : ");
  //Serial.println (status_sw_joystick);

  //delay (100);

  radio.write (pesan, sizeof(pesan));

}
