/*
Jhonatan da Silva
Last Updated version :
Mon Feb  6 16:20:09 2017
Number of code lines: 
112
*/
/*
  Finite_Robotic_Machine.cpp - Library for flashing Finite_Robotic_Machine code.
  Created by Jhonatan da Silva, November 30, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Finite_Robotic_Machine.h"
#include "Servo.h"
#include "Stepper.h"

Finite_Robotic_Machine::Finite_Robotic_Machine(int init){
	init = 0;
	_state = Init;
	defineMotors();
}
void Finite_Robotic_Machine::Start(){
	switch(_state){
		case Init:
			Serial.println("Robotic arm initializing");
			_state = ReadingSerial;
			delay(500);
			break;
		case ReadingSerial:
			Serial.println("");
			GetSerial();
			_state = StepperASTATE;
			delay(500);
			break;
		case StepperASTATE:
			//Move('A', Angle[0]);
			_state = ServoBSTATE;
			delay(500);
			break;
		case ServoBSTATE:
			Move('B', Angle[1]);
			_state = StepperCSTATE;
			delay(500);
			break;
		case StepperCSTATE:
			//Move('C',Angle[2]);
			_state = ServoDSTATE;
			delay(500);
			break;
		case ServoDSTATE:
			//Move('D', Angle[3]);
			_state = ReadingSerial;
			delay(500);
			break;
	}
}
void Finite_Robotic_Machine::Move(int motor, int angle){
	switch(motor){
		case 65:	//A 
			Serial.println(angle);
			break;
		case 66:	//B
			//int current_position = jointB.read();
			diffAngle = angle - jointB;
		    if(diffAngle > 0){
				//Serial.println("clockwise"); 
				jointB++;
				//jointB.write((jointB.read() +1));
				//Serial.println(jointB.read());
			}
		    if(diffAngle < 0){
				//Serial.println("anticlockwise");
				jointB--;
				//jointB.write((jointB.read() -1));
		    }
			Serial.print("Current angle = ");
			Serial.println(jointB);
			Serial.print("Goal = ");
			Serial.println(Angle[1]);
			break;	
		case 67:	//C
			break;
		case 68:	//D
			break;
		default:
            Serial.println("error");
            break;
    }	
}
void Finite_Robotic_Machine::GetSerial(){
	int val = 0;
	if(Serial.available() > 0) {
        val = Serial.read();
        switch (val) {
        case 65: //letra 'A'
			Angle[0] = Serial.parseInt();
			break;
        case 66: //letra 'B'
            Angle[1] = Serial.parseInt();
			break;
        case 67: //letra 'C'
            Angle[2] = Serial.parseInt();
			break;
        case 68: //letra 'D'
            Angle[3] = Serial.parseInt();
			break;
		}
		Serial.flush(); //para limpar a serial, em caso de lixo
	}
}

void Finite_Robotic_Machine::defineMotors(){
	Stepper jointC(Revolution, 8, 9, 10, 11);
	Stepper jointA(Revolution, 4,5,6,7);
	Servo jointB;
	Servo jointD;
}
