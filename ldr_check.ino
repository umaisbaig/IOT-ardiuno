#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "ardino-99a8a-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QFvX8MNiD14EuL6YRYMGEDy9xarrEluXVgPSZ9vV"
#define WIFI_SSID "HUAWEI-t3DA"
#define WIFI_PASSWORD "GzspWqPh"
const int ldrpin = A0;
const int led = D1;
int threshold =100;
void setup()
{
  Serial.begin(9600);
  pinMode(ldrpin,INPUT);
  pinMode(led,OUTPUT);
  delay(100);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to");
  Serial.print(WIFI_SSID);
  while (WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay (500);
  }
  Serial.println();
  Serial.print("connected to");
  Serial.println (WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}s
void loop()
{
  int rawData = analogRead(ldrpin);
  Serial.println(rawData);
  if (rawData<100)
  {
    digitalWrite(led,HIGH);
    int lightON=rawData;
   Firebase.pushInt("lighton",rawData);
  }
  else
  {
    digitalWrite(led,LOW);
     int lightOFF=rawData;
     Firebase.pushInt("lightoff",rawData);
  }
  delay(100);
}
