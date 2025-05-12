const int soundSensorPin = D0;  // Sound sensor digital pin
const int led = D6;   // LED pin
const int Relay=D5;
bool ledStatus=false;       //initially OFF

int clapCount = 0;              // Number of claps detected
bool clapDetected = false;      // Flag to indicate clap detection
unsigned long clapStartTime=0;
const unsigned long clapTimeout=1000; //clap interval

void setup()  //runs only once
{
  pinMode(soundSensorPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(Relay, OUTPUT); //use NC pin of Relay
  // Serial.begin(9600);   //serial communication
}

void loop() 
{
  int sensorValue = digitalRead(soundSensorPin);  // Read sound sensor value

  // Check for clap
  if (sensorValue == HIGH && !clapDetected) 
  {
    clapCount++;
    clapDetected = true;
    clapStartTime=millis();
    // Serial.print("Clap detected! Count: ");
    // Serial.println(clapCount);
  }
  else if (sensorValue == LOW) 
  {
    clapDetected = false;
  }
 if (clapCount > 0 && (millis() - clapStartTime) >= clapTimeout)  //clap reset condition
 {
    clapCount = 0;
    // Serial.println("Clap count reset.");

  
  if (clapCount%2==0) // Check claps
  {
    if(ledStatus==false)
    {
      ledStatus=true;
      digitalWrite(led, HIGH);
      digitalWrite(Relay, LOW); //Relay is off
    }
    else if(ledStatus==true)
    {
      ledStatus=false;
      digitalWrite(led, LOW);
      digitalWrite(Relay, HIGH);  //Relay is on
    }
    clapCount = 0;  // Reset clap count
  }
  }
}
