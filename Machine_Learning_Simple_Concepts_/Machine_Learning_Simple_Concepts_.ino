
const float km_saat_ini = 100;

const float miles_sebenarnya = 65.4;

float angka_sembarang = 0.35;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println ("Convert km to miles");

}

float miles (float km, float m) {
  return km * m;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float error;
  int a = 1;

  while (a == 1) {

      error = miles_sebenarnya - miles (km_saat_ini, angka_sembarang);

      if (error <= 0) {
      
        a = 0;
      
      } else {
        
        angka_sembarang = angka_sembarang + 0.001;

        Serial.print ("Error = ");
        Serial.println (error);
      
      }
  
  }

  Serial.print (km_saat_ini);
  Serial.print (" km = ");
  Serial.print (miles (km_saat_ini, angka_sembarang));
  Serial.println (" miles");

}
