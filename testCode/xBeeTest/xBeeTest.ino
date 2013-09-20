/*
 Based on the Physical Pixel code by
 
 creaded 30 Aug 2011
 by Tom Igoe and Scott Fitzgerald
 modified May 25, 2013
 by Sophia Castellarin
 
*/
 
int ledPin = 13;    // output pin that has the LED
int EN = 11;       // output pin that enables the h bridge 
int go_fwd = 10;   // output pin that sends current make the motor go forward
int go_bck = 9;    // output pin that sends current to make the motor go backwards

int incomingByte;      // a variable to read incoming serial data into


//CONVENIENCE FUNCTIONS!!
//-----------------------------------------------------------------------------------------//
// Enables the h-bridge so that you can make the motor move
void initGo(){
  digitalWrite(EN, HIGH);
}

// Un-enables the h-bridge so that the motor no longer get any current
void initStop(){
  digitalWrite(EN, LOW);
  digitalWrite(go_fwd, LOW);
  digitalWrite(go_bck, LOW);
}

// Makes the motor go forward
void goForward(){
    digitalWrite(go_fwd, HIGH);
    digitalWrite(go_bck, LOW);
}

// Makes the motor go backwards
void goBackwards(){
    digitalWrite(go_bck, HIGH);
    digitalWrite(go_fwd, LOW);
}
//-----------------------------------------------------------------------------------------//


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT); 
  pinMode(EN, OUTPUT);
  pinMode(go_fwd, OUTPUT);
  pinMode(go_bck, OUTPUT);

}

void loop() {
  //initStop();
  
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
   
   // Controls the LED
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
    
    // Controls the motor
    if (incomingByte == 'w') {
      initGo();
      goForward(); 
    }
    if (incomingByte == 's') {
      initGo();
      goBackwards();; 
    }
    if (incomingByte == 'q'){
      initStop();
    }
    
    
  }
}
