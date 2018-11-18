int relayPin = 6;
int buzzer = 3;
int motion = 2;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH); // Turn off Buzzer
  pinMode(motion, INPUT);
  digitalWrite(motion, LOW);
  Serial.begin(9600);
}
void loop() {

if(digitalRead(motion) == HIGH){
  digitalWrite(buzzer, LOW);
  digitalWrite(relayPin, LOW);
  Serial.println("!ALARM!");
  delay(100);
  digitalWrite(buzzer, HIGH);
  digitalWrite(relayPin, HIGH);
}
}
