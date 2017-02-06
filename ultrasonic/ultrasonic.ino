#define disparar 4
#define IdaVolta 5

long tempoTotal;
int distancia;

void setup(){
  pinMode(disparar,OUTPUT);
  pinMode(IdaVolta,INPUT);
  Serial.begin(9600);
  
  digitalWrite(disparar,LOW);
  
}

void loop(){
  digitalWrite(disparar, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparar, LOW);
  
  tempoTotal = pulseIn(IdaVolta,HIGH);
  distancia = tempoTotal*0.034/2; // velocidade do som = 340m/s 
   
  Serial.println(distancia);
}
