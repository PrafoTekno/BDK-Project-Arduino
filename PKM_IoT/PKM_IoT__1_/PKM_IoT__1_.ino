
#include <ESP8266WiFi.h>
 
const char* ssid = "OPPO RENO";
const char* password = "ayamgoreng";
 
int LED = 16;                 // led connected to D0
WiFiServer server(80);
 
void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
 
  Serial.print("Connecting to Internet ");
  WiFi.begin(ssid, password);   //ngasih microcontroller ssid sama password yg dimasukin
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
 
 /*-------- server started---------*/ 
  server.begin();
  Serial.println("Server started");
 
  /*------printing ip address--------*/ 
  Serial.print("IP Address of network: ");
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP()); //ngasih url sisanya biar rapih
  Serial.println("/");
}
 
void loop() 
{
  WiFiClient client = server.available();  //listen for incoming clients  
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");   
  while(!client.available())
  {
    delay(1);
  }
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  //ngubah di url ada /led=on atau /led=off nya
  {
    digitalWrite(LED, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  
  {
    digitalWrite(LED, LOW);
    value = LOW;
  }
 
/*------------------Creating html page---------------------*/

  client.println("HTTP/1.1 200 OK");    //http selalu mulai dengan rensponse code seperti ini
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("LED is: ");
 
  if(value == HIGH) 
  {
    client.println("ON");
  } 
  else 
  {
    client.print("OFF");
  }
  client.println("<br><br>"); //line break
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
