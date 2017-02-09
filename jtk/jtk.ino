/*
Jhonatan da Silva
Last Updated version :
Wed Feb  8 23:39:02 2017
Number of code lines: 
41
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define disparar 51
#define IdaVolta 53

long tempoTotal;
int distancia;
int serialRead = 0;

float ultrassonic();

void setup(){
  pinMode(disparar,OUTPUT);
  pinMode(IdaVolta,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  digitalWrite(disparar,LOW);
  
}

void loop(){
  if (Serial.available() > 0) {
    serialRead = Serial.read();
    if (serialRead == 85){ // Letra U
      distancia = ultrassonic();
      lcd.clear();
      lcd.print(distancia);     
    }
  }
}

float ultrassonic(){
  digitalWrite(disparar, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparar, LOW);
  tempoTotal = pulseIn(IdaVolta,HIGH);
  distancia = tempoTotal*0.034/2; // velocidade do som = 340m/s 
  return distancia;
}
