int LED = 5;
int PushButton = 6;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP);
  digitalWrite(LED, LOW);
}
void loop() {
if(digitalRead(PushButton) == LOW){
  digitalWrite(LED, HIGH);
delay(10000);
digitalWrite(LED, LOW);
}
}	
