#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "d732847773dd45b3a94c8e17e7c26e1a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmis";
char pass[] = "88888888";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);
void sendSensor()
{
  float t = analogRead(A0);
  t=(t*5*100)/1024;
  Blynk.virtualWrite(V6, t);
}
void gasSensor()
{
  int g = analogRead(A1);
  Serial.println(g);
  if(g>100)
  {
    
  Blynk.virtualWrite(7, 1);
  }
  else
  {
    Blynk.virtualWrite(7, 0);
  }
}
BLYNK_WRITE(V1)  // button attached to Virtual Pin 1 in SWITCH mode
{
  int i = param.asInt();
  if(i == 1){
    fullon();  
  }
  else{
    //fulloff();  
  }
}
BLYNK_WRITE(V2)  // button attached to Virtual Pin 2 in SWITCH mode
{
  int i = param.asInt();
  if(i == 0){
    //fullon();  
  }
  else{
    fulloff();  
  }
}
void fullon(){
  
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
}

void fulloff(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
void setup()
{
  // Debug console
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
  sendSensor();
  BLYNK_WRITE(V1);
  BLYNK_WRITE(V2);
  gasSensor();
  
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

