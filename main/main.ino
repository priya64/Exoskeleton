/***********************************************************************
 * Project: Exoskeleton
 * Date: January 31st 2020
 * 
 * This is the code for the exoskeleton project.
 * It must rotate in both directions to account for a finger unfolding and folding,
 * as well as only do so if the user chooses to (reading from sensor).
 * 
 * Author: Andrea Martinez Chung
 *********************************************************************/
#include <Servo.h>

#define servo_pin 13

Servo myservo       //Declare servo object
int pos = 0;        //Variable to store the servo position

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
