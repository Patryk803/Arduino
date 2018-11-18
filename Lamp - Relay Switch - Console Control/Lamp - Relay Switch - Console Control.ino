int relayPin = 6;
String receivedData = ""; // 
void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Turn your lamp on or off");
  digitalWrite(relayPin, HIGH);
}
void loop() {

if(Serial.available() > 0) { //If arduino received any data
    //If yes, read and save in variable dataReceived
    receivedData = Serial.readStringUntil('\n'); 
    
    if (receivedData == "on") { //Jeśli odebrano słowo "zielona"
      digitalWrite(relayPin, LOW); //Turn on Relay/Turn on lamp
      Serial.println("Lamp is on");
    }
    else if (receivedData == "off") { //Turn off Relay,Turn off lamp
      digitalWrite(relayPin, HIGH);
      Serial.println("Lamp is off");
    }
    else{
      Serial.println("Bad Choice");
      Serial.println("You can choose: on or off");
    }
 }
}
