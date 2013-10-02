#include "hBridge.h"

hBridge motors;

void setup() 
{
/*
  The default pins in the library are setup as follows. 
  Here is code that you can un-comment and use if you wish
  to use a different pin-out for your H-Bridge.
*/

//  motors.setPWM_A(6);  // Right-hand side
//  motors.setIN1(7);
//  motors.setIN2(8);
//
//  motors.setPWM_B(11); // Left-hand side
//  motors.setIN3(12);
//  motors.setIN4(13);
}

void loop() {
// put your main code here, to run repeatedly: 
  motors.drive(100); // positive will drive the robot forward (Right-CW, Left-CCW)
  delay(2000);
  motors.stop();     // this will enable a hardstop on the H-Bridge
  delay(1000);

  motors.drive(-200); // negative will drive the robot reverse (Right-CCW, Left-CW)
  delay(2000);
  motors.coast();     // this will allow the motors to simply coast to a stop
  delay(1000);

  motors.pivot(200); // positive should spin CW, negative will pivot CCW
  delay(2000);
  motors.coast();     // this will allow the motors to simply coast to a stop
  delay(1000);

  motors.leftDrive(-255); // this is another way to drive straight and "tune"
  motors.rightDrive(255); // the right side vs. the left side motors
  delay(2000);
  motors.stop();
  delay(2000);
}
