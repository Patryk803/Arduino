#include <LiquidCrystal_I2C.h>
int LedRed = 10;
int LedOrange = 9;
int LedGreen = 8;
int PushButton = 7;
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight
  pinMode(LedRed, OUTPUT); //Dioda czerwona
  pinMode(LedOrange, OUTPUT); //Dioda zólta
  pinMode(LedGreen, OUTPUT); //Dioda zielona
  pinMode(PushButton, INPUT_PULLUP); //Przycisk
  digitalWrite(LedRed, HIGH); //Wylaczenie diod
  lcd.setCursor(3, 0); // set the cursor to column 3, line 0
  lcd.print("Red Light");  // Print a message to the LCD
  digitalWrite(LedOrange, LOW);
  digitalWrite(LedGreen, LOW);
}
void loop() {
 while (digitalRead(7) == LOW) { //Przycisk musi zostac wcisniety
 digitalWrite(LedRed, HIGH); 
 delay(5000);
 digitalWrite(LedOrange, HIGH); //Czerwona wlacz
 lcd.clear();
 lcd.print("Almost Green");
 lcd.setCursor(4, 1);
 lcd.print("Light");
 delay(5000);
 digitalWrite(LedRed, LOW);
 digitalWrite(LedOrange, LOW);
 lcd.clear();
 digitalWrite(LedGreen, HIGH);
 lcd.print("Green Light");  // Print a message to the LCD
 delay(5000);
 digitalWrite(LedGreen, LOW);
 digitalWrite(LedRed, HIGH);
 lcd.clear();
 lcd.setCursor(4, 0);
 lcd.print("Red Light");
 }
}
