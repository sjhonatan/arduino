/*
  Finite_Robotic_Machine.h - Library for flashing FSM code.
  Created by Jhonatan da Silva, November 27, 2016.
  Released into the public domain.
*/
#ifndef Finite_Robotic_Machine_h
#define Finite_Robotic_Machine_h

#include "Arduino.h"
#include "Servo.h"
#include "Stepper.h"

class Finite_Robotic_Machine
{
  public:
    Finite_Robotic_Machine(int init);
	int angle;
	int current;
	void Start();
  private:
	#define steps_pdegree 5.68
	#define Init         		   0 
    #define ReadingSerial          1
    #define StepperASTATE   	   2
    #define ServoBSTATE    		   3
    #define StepperCSTATE    	   4
    #define ServoDSTATE            5
	#define Idle			       6
	int Revolution = 500;
	int jointB = 0;
	int diffAngle;
	int Angle[4] = {0,0,0,0};
	int _state;
	int j = 0;
	
	void Move(int motor, int angle);
	void GetSerial();
	void defineMotors();
	
};
#endif