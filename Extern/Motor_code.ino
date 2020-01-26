#include <Servo.h>

Servo servo;

int pin = 9; 
int pos = 0; //position is influenced by sensor



void setup() {

  //initialise motors
  
  servo.attach(pin);
}

void loop() {
  
  //take in signal from motor
  //write which direction to move in

   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);
    delay(15);                     // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);            // tell servo to go to position in variable 'pos'
    delay(15);
  }
}
