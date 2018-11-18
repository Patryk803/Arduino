int readValue = 0; //Variable to store output from ADC
void setup() {
  pinMode(2, OUTPUT); //LED output
}
void loop() {
  readValue = analogRead(A5);//Reading the value from ADC
  digitalWrite(2, HIGH);//Turn on LED
  delay(readValue);//Delay depending on the value from ADC
  digitalWrite(2, LOW);//Turn off LED
  delay(readValue);//Delay depending on the value from ADC
}
