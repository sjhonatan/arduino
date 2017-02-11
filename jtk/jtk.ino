/*
Jhonatan da Silva
Last Updated version :
Sat Feb 11 14:35:30 2017
Number of code lines: 
79
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
        lcd.clear();
        lcd.print(serialRead);
        switch(serialRead){

            case 85:
                distancia = ultrassonic();
                break;

            case 76:
                lcd.clear();
                lcd.print(?);
                break;
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


/*
 Start of the development of the class carrinho 

*/
class Carrinho{
    public:
        carrinho(int EN1,int EN2,int IN1,int IN2,int IN3,int IN4);
        void velocidade(int v);
        void f():
        void t();
        void e();
        void d();
};
Carrinho::f(){
    digitalWrite(IN1,HIGH); digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}
Carrinho::t(){
    digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}
Carrinho::e(){
    digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}
Carrinho::d(){
    digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
}
