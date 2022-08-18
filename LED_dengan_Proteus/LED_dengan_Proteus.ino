
const int red = 3;
const int green = 4;
const int blue = 5;

void setup () {

  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
  
}

void loop () {

  digitalWrite (red, HIGH);
  delay (2000);
  digitalWrite (green, HIGH);
  delay (1000);
  digitalWrite (blue, HIGH);
  delay (2000);

  digitalWrite (red, LOW);
  digitalWrite (green, LOW);
  digitalWrite (blue, LOW);

  delay (3000);
  
}
