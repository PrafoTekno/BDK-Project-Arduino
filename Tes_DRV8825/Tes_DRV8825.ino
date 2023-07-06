// Define pin connections & motor's steps per revolution
const int dirPin1 = 2;
const int stepPin1 = 4;

const int dirPin2 = 3;
const int stepPin2 = 5;

const int stepsPerRevolution = 200;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

  pinMode (stepPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  
}
void loop()
{
  /*
  digitalWrite (dirPin1, HIGH);
  digitalWrite(stepPin1, HIGH);
  
  digitalWrite (dirPin2, HIGH);
  digitalWrite(stepPin2, HIGH);
  */
  
 // Set motor direction clockwise
  digitalWrite(dirPin1, HIGH);
  
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); // Wait a second
  
  // Set motor direction counterclockwise
  digitalWrite(dirPin1, LOW);

  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(1000);
  }
  delay(1000); // Wait a second 
  
}
