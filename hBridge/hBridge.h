#ifndef hBridge_h
#define hBridge_h

#include <Arduino.h>

class hBridge
{
  public:
    hBridge();
    void drive(int speed);
    void pivot(int speed);
    void rightDrive(int speed);
    void leftDrive(int speed);
    void stop();
    void rightStop();
    void leftStop();

	void coast();
	void rightCoast();
    void leftCoast();

	void setPWM_A(int pinNum);
	void setIN1(int pinNum);
	void setIN2(int pinNum);

	void setPWM_B(int pinNum);
	void setIN3(int pinNum);
	void setIN4(int pinNum);

  protected:
	int PWM_A;
	int IN1;
	int IN2;
	int PWM_B;
	int IN3;
	int IN4;
	
  private:
    void leftCW(byte speed);
    void leftCCW(byte speed);
    void rightCW(byte speed);
    void rightCCW(byte speed);
};

#endif hBridge_h
