#define trigger 9
#define echo 10
#define motor 4

long tempoTotal = 0;
int distancia;

float ultrassonic();
void controlarMotor();

void setup() {
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(motor,OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(trigger,LOW);
  digitalWrite(motor,LOW);
}

void loop() {
  distancia = ultrassonic();
  controlarMotor();
  Serial.println(distancia);       // print as an ASCII-encoded decima
  delay(10);
}

float ultrassonic(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tempoTotal = pulseIn(echo,HIGH);
  distancia = tempoTotal*0.034/2; // velocidade do som = 340m/s 
  return distancia;   
}

void controlarMotor(){
  digitalWrite(motor,HIGH);
}
