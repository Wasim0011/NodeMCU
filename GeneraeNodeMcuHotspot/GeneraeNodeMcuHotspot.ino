#include<ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP("Robocar", "12345678");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("No of connections");
  Serial.println(WiFi.softAPgetStationNum());
  delay(1000);  

}
