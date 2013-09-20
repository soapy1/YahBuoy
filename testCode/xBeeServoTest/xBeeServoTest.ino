#include <Servo.h>

Servo serOne;      // Creates a servo object
Servo serTwo;

int ledPin = 13;    // output pin that has the LED

int valOne = 90;            // Holds the value for the servo
int valTwo = 90;

int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT); 
  serOne.attach(9);
  serTwo.attach(10);
}

void loop() {
  serOne.write(valOne);
  serTwo.write(valTwo);

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
      valOne ++;
    } 
    if (incomingByte == 's') {
      valOne --;
    }
    if (incomingByte == 'e') {
      valTwo ++;
    } 
    if (incomingByte == 'd') {
      valTwo --;
    }

  }
}

