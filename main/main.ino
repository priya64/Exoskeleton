/***********************************************************************
 * Project: Exoskeleton
 * Date: January 31st 2020
 * 
 * This is the code for the exoskeleton project.
 * It must rotate in both directions to account for a finger unfolding and folding,
 * as well as only do so if the user chooses to by flexing (reading from a muscle sensor).
 * 
 * Author: Andrea Martinez Chung
 *********************************************************************/
#include <Servo.h>

#define servo_pin 11
#define sensor_pin A0

Servo myservo;       //Declare servo object
int pos = 0;         //Variable to store the servo position
int sensor_value;    //Variable to store value at sensor

void setup() {
  myservo.attach(servo_pin);
  for(pos = 0; pos <= 45; pos++){      //rotate servo from 0 degrees to 90 degrees
      myservo.write(pos);
      delay(15);
    }
}

void loop() {
  sensor_value = analogRead(sensor_pin);
  Serial.println(sensor_value);
  
  if(sensor_value > 70 && pos == 45){                //move finger if user flexes
    for(pos = 45; pos <= 90; pos++){      //rotate servo from 0 degrees to 90 degrees
      myservo.write(pos);
      delay(15);
    }
    
    while(sensor_value > 0){           //while the user is still flexing, don't do anything
      sensor_value = analogRead(sensor_pin);
    }
    
    for(pos = 90; pos >=45; pos--){      //rotate servo from 90 degrees to 0 degrees
      myservo.write(pos);
      delay(15);
    }
  } 
}
