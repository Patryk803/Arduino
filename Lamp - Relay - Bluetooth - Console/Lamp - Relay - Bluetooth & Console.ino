#define Relay 7
int state = 0;

void setup() {
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }

  if (state == '0'){
    digitalWrite(Relay, HIGH); // Turn light on
    Serial.println("Light: OFF");
    state = 0;
  }
  else if (state == '1'){
    digitalWrite(Relay, LOW);
    Serial.println("Ligh: ON");
    state = 0;
  }

}
