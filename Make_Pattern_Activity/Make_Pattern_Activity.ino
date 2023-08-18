
// Open Processing with the same file name

#include <Servo.h>
Servo myServo;
int rotate;

const int led_green = 7;
const int led_yellow = 13;

int dataRead;

const int MAX = 10;

int green_on = 0, yellow_on = 0, n = -1, total_action = 0;
int n_action [MAX];
int delay_yellow = 0, delay_green = 0, delay_servo = 0;

int rotate_status;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  
  pinMode (led_green, OUTPUT);
  pinMode (led_yellow, OUTPUT);
  
  myServo.attach (3);
  myServo.write (0);
  
}

void Play () {

  for (int i = 0; i < total_action; i++) {

    if (n_action[i] == 1) {
      
        for (int j = 0; j < yellow_on; j++) {
           digitalWrite (led_yellow, HIGH);
           delay (delay_yellow*50);
           digitalWrite (led_yellow, LOW);
           delay (delay_yellow*50);
        }
        
    }

    else if (n_action[i] == 2) {
      
        for (int j = 0; j < green_on; j++) {
           digitalWrite (led_green, HIGH);
           delay (delay_green*50);
           digitalWrite (led_green, LOW);
           delay (delay_green*50);
        }
        
    }
    
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

   int status_action = 0;
   
   if (Serial.available () > 0) {
    dataRead = Serial.read ();
   }

   if (dataRead == 1) {
    
    digitalWrite (led_yellow, HIGH);
    
    status_action = 1;
    delay_yellow ++;
    
    
   }
   else if (dataRead == 2) {
    
    digitalWrite (led_green, HIGH);

    status_action = 2;
    delay_green ++;
    
   }
   else if (dataRead >= 3) {
    
    rotate = map (dataRead, 80, 235, 0, 180);
    myServo.write (rotate);
    rotate_status = rotate;
    
    //delay_servo ++;
    status_action = 3;
    
   }
   else {
    digitalWrite (led_yellow, LOW);
    digitalWrite (led_green, LOW);
   }

   if (dataRead == 0) {

      if (status_action == 1) {
        total_action += 1;
        n += 1;
        yellow_on += 1;
        n_action [n] = 1;
      }

      else if (status_action == 2) {
        total_action += 1;
        n += 1;
        green_on += 1;
        n_action [n] = 2;
      }

      else if (status_action == 3) {
        total_action += 1;
        n += 1;
        n_action [n] = 3;
      }
    
   }

   Serial.write (status_action);
   
   if (dataRead == 3) {
     myServo.write (0);
     Play ();

     delay_yellow = 0; 
     delay_green = 0; 
     delay_servo = 0;

     n = -1;
   }
   
}
