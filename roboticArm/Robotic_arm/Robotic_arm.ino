/*
Jhonatan da Silva
Cassiano Bonin
Last Updated version :
Tue Jan 31 18:04:30 2017
Number of code lines: 
131
*/
#include <Stepper.h>
#include <Servo.h>
#define steps_pdegree 5.68
const int SPR = 500; 

Stepper jointC(SPR, 8, 9, 10, 11);
Stepper jointA(SPR, 4,5,6,7);
Servo jointB;
Servo jointD;

int val = 0;
int j = 0;
int newAngle4axis = 0;                             // newAngle4axis Armazena o angulo de movimento do motores que será mandado pelo MATLAB.int current_angle_A = 0;               // Armazena as posições atuais dos motores.
int currentAngle_C = 0;
int currentAngle_A = 0;


void StepperC(int angle);   // Funções usadas para mover os motores
void StepperA(int angle);
void ServoB(int angle, int current_position);
void ServoD(int angle, int current_position);
void __init__();

void setup() {
  Serial.begin(9600);
  jointB.attach(2);
  jointD.attach(3);
  jointC.setSpeed(50);
  jointA.setSpeed(50);
  jointD.write(10);
}
void loop() {
    //__init__(); 
    if(Serial.available() > 0) {
        val = Serial.read();
        newAngle4axis = Serial.parseInt();
        switch (val) {
        case 65: //letra 'A'
            Serial.print("Motor A, angle = ");
            Serial.println(newAngle4axis); 
            StepperA(newAngle4axis);
            break;
        case 66: //letra 'B'
            Serial.print("Motor B, angle = ");
            Serial.println(newAngle4axis);
            ServoB(newAngle4axis, jointB.read());
            break;
        case 67: //letra 'C'
            Serial.print("Motor C, angle = ");
            Serial.println(newAngle4axis);
            StepperC(newAngle4axis);
            break;
        case 68: //letra 'D'
            Serial.print("Motor D, angle = ");
            Serial.println(newAngle4axis);
            ServoD(newAngle4axis, jointD.read());
            break;
        default:
            Serial.println("error");
            break;
        }
        Serial.flush(); //para limpar a serial, em caso de lixo
    
    }
}
void StepperA(int angle){
  int angleDiff = angle - currentAngle_A;
  int n_steps = steps_pdegree*angleDiff;
  jointA.step(-n_steps);
  currentAngle_A = angle; 
}
void StepperC(int angle) {
    int angleDiff = angle - currentAngle_C;
    int n_steps = steps_pdegree*angleDiff;
    Serial.println(n_steps);
    jointC.step(-n_steps);
    currentAngle_C = angle; 
}
void ServoD(int angle, int current_position){
   int diffAngle = angle - current_position;
   if(diffAngle > 0){
      Serial.println("clockwise"); 
      for(j = current_position; j <= angle; j++){
          Serial.println(j);
          jointD.write(j);
          delay(20);
      }
   }
   else{
      Serial.println("anticlockwise");
      for(j = current_position; j >= angle; j--){
          Serial.println(j);
          jointD.write(j);
          delay(20);
      }
   }
}

void ServoB(int angle, int current_position){
   int diffAngle = angle - current_position;
   if(diffAngle > 0){
      Serial.println("clockwise"); 
      for(j = current_position; j <= angle; j++){
          Serial.println(j);
          jointB.write(j);
          delay(20);
      }
   }
   else{
      Serial.println("anticlockwise");
      for(j = current_position; j >= angle; j--){
          Serial.println(j);
          jointB.write(j);
          delay(20);
      }
   }
}

void __init__(){
    StepperA(0);
    StepperC(0);
    ServoB(0);
    ServoD(0);
    StepperA(30);
    StepperC(30);
    ServoB(30);
    ServoD(30);
    
}


