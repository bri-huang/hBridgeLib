#include "hBridge.h"
#include <Arduino.h>

hBridge::hBridge()
{
// set default pin numbers for the hBridge connections to the Arduino
// you can also change any of these within the setup() of your 
// arduino code using the .setPWM_A, .setIN1, .setIN2... methods
//
  PWM_A = 6;  // Enable A
  IN1 = 7;
  IN2 = 8;

  PWM_B = 11;  // Enable B
  IN3 = 12;
  IN4 = 13;
  
  pinMode(PWM_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(PWM_B, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void hBridge::setPWM_A(int pinNum)
{
	PWM_A = pinNum;
}

void hBridge::setIN1(int pinNum)
{
	IN1 = pinNum;
}

void hBridge::setIN2(int pinNum)
{
	IN2 = pinNum;
}

void hBridge::setPWM_B(int pinNum)
{
	PWM_B = pinNum;
}

void hBridge::setIN3(int pinNum)
{
	IN3 = pinNum;
}

void hBridge::setIN4(int pinNum)
{
	IN4 = pinNum;
}


void hBridge::stop()
{
  leftStop();
  rightStop(); 
}

void hBridge::drive(int speed)
{
  if (speed > 0)
  {
    leftCCW((byte)(abs(speed)));
    rightCW((byte)(abs(speed)));
  }
  else
  {
    leftCW((byte)(abs(speed)));
    rightCCW((byte)(abs(speed)));
  }
}

void hBridge::pivot(int speed)
{
  if (speed > 0)
  {
    leftCCW((byte)(abs(speed)));
    rightCCW((byte)(abs(speed)));
  }
  else
  {
    leftCW((byte)(abs(speed)));
    rightCW((byte)(abs(speed)));
  }
}

void hBridge::rightDrive(int speed)
{
  if (speed > 0)
  {
    rightCW((byte)(abs(speed)));
  }
  else
  {
    rightCCW((byte)(abs(speed)));
  }
}

void hBridge::leftDrive(int speed)
{
  if (speed > 0)
  {
    leftCW((byte)(abs(speed)));
  }
  else
  {
    leftCCW((byte)(abs(speed)));
  }
}

void hBridge::leftStop()
{
  analogWrite(PWM_B, 5);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  }

void hBridge::coast()
{
  rightCoast();
  leftCoast();
}

void hBridge::rightStop()
{
  analogWrite(PWM_A, 5);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void hBridge::rightCoast()
{
  analogWrite(PWM_A, 0);
}

void hBridge::leftCoast()
{
  analogWrite(PWM_A, 0);
}





/******************************************************************************
Private functions for hBridge
******************************************************************************/

void hBridge::leftCW(byte spd)
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(PWM_B, spd);

}

void hBridge::leftCCW(byte spd)
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(PWM_B, spd);
}

void hBridge::rightCW(byte spd)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(PWM_A, spd);
}

void hBridge::rightCCW(byte spd)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(PWM_A, spd);
}
