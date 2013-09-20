
int LED = 7;      // input pin for the LED
int BCK = 6;      // input pin that says when to go backwards
int FWD = 5;      // input pin that says when to go forwards

int led = 13;     // output pin that has the LED

int EN = 11;        // output pin that enables the h bridge 
int go_fwd = 10;   // output pin that sends current make the motor go forward
int go_bck = 9;    // output pin that sends current to make the motor go backwards

//CONVENIENCE FUNCTIONS!!
//-----------------------------------------------------------------------------------------//
// Enables the h-bridge so that you can make the motor move
void initGo(){
  digitalWrite(EN, HIGH);
}

// Un-enables the h-bridge so that the motor no longer get any current
void initStop(){
  digitalWrite(EN, LOW);
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
 
  pinMode(led, OUTPUT);  
  pinMode(EN, OUTPUT);
  pinMode(go_fwd, OUTPUT);
  pinMode(go_bck, OUTPUT);
  pinMode(LED, INPUT);
  pinMode(BCK, INPUT);
  pinMode(FWD, INPUT);  
}


// the loop routine runs over and over again forever:
void loop() {
    
  // Responds to input from LED pin
  if (digitalRead(LED) == HIGH){
    digitalWrite(led, HIGH);   
  } else{
    digitalWrite(led, LOW);
  }
  
  if (digitalRead(FWD) == HIGH){
    initGo();
    goForward();
  }else if (digitalRead(BCK) == HIGH){
    initGo();
    goBackwards();
  }else{
    initStop();
  }
 
  
}
