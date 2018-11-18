#include "IRremote.h"

int receiver = 2; // Signal Pin of IR receiver to Arduino Digital Pin 11
int relay = 6;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); // Turn light off
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{
  switch(results.value)
  {
  case 0xFF906F: Serial.println("Turn On");
  digitalWrite(relay, LOW); //Turn on Relay/Turn on lamp
  break;
  case 0xFFA857: Serial.println("Turn Off");
  digitalWrite(relay, HIGH);
  break;
  default: 
    Serial.print("Other button, Hexadecimal value: ");
    Serial.println(results.value, HEX);
  }// End Case
  delay(500); // Do not get immediate repeat
} //END translateIR
