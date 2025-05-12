#include<ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("OPPO A76", "12345678");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("--");
    delay(400);
  }
  Serial.println();
  Serial.print("NodeMCU is successfully connedted!");
  Serial.println("WiFi.localIP");

}

void loop() {
  // put your main code here, to run repeatedly:

}
