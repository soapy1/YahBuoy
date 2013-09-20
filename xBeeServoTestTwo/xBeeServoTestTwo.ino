#include <Servo.h>

Servo serOne;      // Creates a servo object
Servo serTwo;
// Servo lift;

int ledPin = 13;    // output pin that has the LED

int valOne = 90;            // Holds the value for the servo
int valTwo = 90;

// int valLift = 0;

int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT); 
  serOne.attach(9);
  serTwo.attach(10);
  //lift.attach(11);
}

void reset(){
  valOne = 90;
  valTwo = 90;
}

void loop() {
  serOne.write(valOne);
  serTwo.write(valTwo);
  
  //lift.write(valLift);

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
    // Basic forwad/backward commands
    if (incomingByte == 'w') {    // Motor 1 and 2 forward - robot forward
      reset();
      valOne = 120;
      valTwo = 60;
    } 
    
    if (incomingByte == 's') {    // Motor 1 and 2 backward - robot backwards
      reset();
      valOne = 60;
      valTwo = 120;
    }
    
    // TODO: fix the rest of these
    // More complex functions
    if (incomingByte == 'a'){    // Still turn 
      reset();
      valOne = 120;
      valTwo = 120;
    }
    
    if (incomingByte == 'd'){    // Still turn the other way
      reset();
      valOne = 60;
      valTwo = 60;
    }
    if (incomingByte == 'p'){    // Stops both motors
      reset();
    }

  }
}
