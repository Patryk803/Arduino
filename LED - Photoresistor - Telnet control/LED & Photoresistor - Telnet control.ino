
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
IPAddress ip(192, 168, 0, 177);
IPAddress myDns(192,168,0, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not you got a message from the client yet
int ledPin = 2;
String commandString; //Temporary store any command that ethernet client is sending to the server

void setup() {
  pinMode(ledPin, OUTPUT); // set the output
    Ethernet.begin(mac, ip, myDns, gateway, subnet); // initialize the Ethernet device not using DHCP:
    server.begin(); // start listening for clients
  Serial.begin(9600); // Open serial communications and wait for port to open:
  // this check is only needed on the Leonardo:
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
Serial.print("Chat server address:");
Serial.println(Ethernet.localIP());
}

void loop(){
  
  EthernetClient client = server.available(); // wait for a new client

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      client.flush(); //clear out the input buffer
      commandString =""; //clear the commandString variable

      server.println("---> Please type your command and hit Return...");
      alreadyConnected = true;
    }
    while (client.available()){
      char newChar = client.read(); //read the bytes incoming from the client;

    if (newChar == 0x0D){ // IF a 0xOD is recevied - a carriage return. 
    server.print("Received this command: ");
    server.println(commandString);
    processCommand(commandString);
    } else{
      Serial.println(newChar);
      commandString += newChar;
    }
    }
  }
}


void processCommand(String command){
  server.print("Processing command ");
  server.println(command);

  if (command.indexOf("photo") > -1){
    Serial.println("Photo command received");
    server.print("Reading from photoresistor: ");
    server.println(analogRead(A0));
    commandString = "";
    return;
  }
  if (command.indexOf("ledon") > -1){
    Serial.println("LED On command received");
    digitalWrite(ledPin, HIGH);
    server.println("LED was turned on");
    commandString ="";
    return;
  }
  if (command.indexOf("ledoff") > -1){
    Serial.println("LED off command received");
    digitalWrite(ledPin, LOW);
    server.println("LED was turned off");
    commandString="";
    return;
  }
  commandString="";
  instructions();
}

void instructions(){
  server.println("I don't understand");
  server.println("Please use on of these commands:");
  server.println("* ledon, to turn on the lamp");
  server.println("* ledoff, to turn off the lamp");
}
