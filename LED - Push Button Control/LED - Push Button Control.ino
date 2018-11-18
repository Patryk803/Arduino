
int LED = 5;
int PushButton = 6;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP); //internal pullup resistor
  digitalWrite(LED, LOW);
}
void loop() {
if(digitalRead(PushButton) == LOW){
  digitalWrite(LED, HIGH);
}
else{
  digitalWrite(LED, LOW);
}
}	
