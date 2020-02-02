#include <Servo.h>
//#include <SoftwareSerial.h>

Servo servo;

int pin = 9; 
int pos = 0; //position is influenced by sensor

int potpin = A0;
double pot_num = 0;
double calc = 0;

void setup() {

  //initialise motors
  
  servo.attach(pin);

  //read from potentiometer
 Serial.begin(9600);
}

void EMG_loop() { //currently using a potentiometer as a substitute
  pot_num = analogRead(potpin);
  calc = (pot_num/1023.0)*10000;
  Serial.println(calc);
  delay(1000);
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
    
  delay(500);
  
  EMG_loop();
}
