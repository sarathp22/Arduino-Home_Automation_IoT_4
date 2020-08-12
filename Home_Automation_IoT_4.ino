char a;
int timeout=1000;
String response="";
int i,flag=0;
char DataIn[3];

void setup() 
{
 Serial.begin(115200);
 delay(5000);
 pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 digitalWrite(13,LOW);
 digitalWrite(12,LOW);
 digitalWrite(11,LOW);
 digitalWrite(10,LOW);
 Serial.println("AT");
 Serial.println("0D0A");
 delay(500);
 Serial.println("ATE0");
 Serial.println("0D0A");
 delay(500);
 Serial.println("AT+GMR");
 Serial.println("0D0A");
 delay(500);
 Serial.println("AT+CWMODE=2");
 Serial.println("0D0A");
 delay(500);
 Serial.println("AT+CIFSR");
 long int time = millis();
  while( (time+timeout) > millis()) // ESP8266 will wait for some time for the data to receive
  {

 while(Serial.available()>0)      
    {
      char c = Serial.read();      
      response+=c;                  
    }
  }
    Serial.println(response);                      
 Serial.println("0D0A");
 delay(500);
 Serial.println("AT+CIPMUX=1");
 Serial.println("0D0A");
 delay(500);
 Serial.println("AT+CIPSERVER=1,80");
 Serial.println("0D0A");
 delay(500);
  
 delay(5000);
 Serial.println("AT+CIPSEND=0,21");
 Serial.println("0D0A");
 delay(500);
 Serial.println("WELCOME: WiFi Connect");
}

void loop() 
{
 delay(100);
 if(Serial.available())
 { 
  a=Serial.read();
  if (a=='$')
  {
   for(i=0; i<3;)
   {
    if(Serial.available())
    {
     DataIn[i]=Serial.read();
     i++;
     if(i==3)
     {
      flag=1;
     }
    }
   }
  }
 }
  
 if(flag==1)
 {
  DataIn[3]='\0';
  if(strcmp(DataIn,"ON1")==0)
  {
   digitalWrite(13,HIGH);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"OF1")==0)
  {
   digitalWrite(13,LOW);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"ON2")==0)
  {
   digitalWrite(12,HIGH);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"OF2")==0)
  {
   digitalWrite(12,LOW);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"ON3")==0)
  {
   digitalWrite(11,HIGH);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"OF3")==0)
  {
   digitalWrite(11,LOW);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"ON4")==0)
  {
   digitalWrite(10,HIGH);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"OF4")==0)
  {
   digitalWrite(10,LOW);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"ON5")==0)
  {
   digitalWrite(13,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(11,HIGH);
   digitalWrite(10,HIGH);
   delay(500);
   flag=0;
  }
  if(strcmp(DataIn,"OF5")==0)
  {
   digitalWrite(13,LOW);
   digitalWrite(12,LOW);
   digitalWrite(11,LOW);
   digitalWrite(10,LOW);
   delay(500);
   flag=0;
  }
 }    
}
