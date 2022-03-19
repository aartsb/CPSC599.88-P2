#include <Stepper.h>
unsigned long time;
int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
int motSpeed = 10;
int dt = 500;
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  
  // initialize the serial port:
  Serial.begin(9600);
  // set the speed at 10 rpm:
  //myStepper.setSpeed(motSpeed);
  
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
   if(time >= 0 || time <=10){
    motSpeed = 0;
    myStepper.setSpeed(motSpeed);
  myStepper.step(stepsPerRevolution/2);
  delay(dt);
  }
  else if(time >= 11 || time <=15){
    motSpeed = 40;
    myStepper.setSpeed(motSpeed);
     myStepper.step(stepsPerRevolution/3);
  delay(dt);
  }
  else if(time >= 15 || time <=20){
    motSpeed = 40;
    myStepper.setSpeed(motSpeed);
     myStepper.step(stepsPerRevolution/4);
  delay(dt);
  }
else if(time >= 20 || time <=30){
  motSpeed = 40;
    myStepper.setSpeed(motSpeed);
  myStepper.step(stepsPerRevolution/5);
  delay(dt);
  
  }
  else if(time >= 30 || time <=35){
    motSpeed = 40;
    myStepper.setSpeed(motSpeed);
    myStepper.step(stepsPerRevolution/6);
  delay(dt);
  }
    else {
    //At this point the laptop screen time has been exceeded by more than 5 minutes
   motSpeed = 60;
  myStepper.setSpeed(motSpeed);
  myStepper.step(stepsPerRevolution);
  delay(5000); 
    }
}
