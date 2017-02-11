#define EN1 5  //DECLARANDO O ENABLE 1
#define EN2 6  //DECLARANDO O ENABLE 2
#define IN1 4  //DECLARANDO O MOTOR DIREITO DA FRENTE
#define IN2 7  //DECLARANDO O MOTOR DIREITO DE TRAS
#define IN3 8  //DECLARANDO O MOTOR ESQUERDO DA FRENTE
#define IN4 12 //DECLARANDO O MOTOR ESQUERDO DE TRAS
#define SE1 A5 //DECLARANDO O SENSOR ESQUERDO DO MEIO
#define SD1 A4 //DECLARANDO O SENSOR DIREITO DO MEIO
#define SE2 A3 //DECLARANDO O SENSOR ESQUERDO DA BORDA
#define SD2 A2 //DECLARANDO O SENSOR DIREITO DA BORDA

int V = 0;
int x = 0;
int i = 0;
int comando = 0;

void setup() {
  //DECLARANDO SE SÃO ENTRADAS OU SAIDA 
  pinMode (EN1, OUTPUT);
  pinMode (EN2, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);  
  Serial.begin (9600);
  Serial.println ("Bem vindo ao programa de teste do robô do PI da primeira fase!");
  Serial.println ("Digite uma velocidade para o robô: ");
  Serial.println ("1 para 0% ");
  Serial.println ("2 para 25% ");
  Serial.println ("3 para 50% ");
  Serial.println ("4 para 100% ");
  
  while (comando == 0){
    comando = Serial.read();
       if (comando == '1')
          V = 0;
      else if (comando == '2')
          V = 64;     
      else if (comando == '3')
          V = 127;
      else if (comando == '4')
          V = 255;     
     else 
          comando = 0;
 } 
 
   Serial.println (comando);

    analogWrite (EN1, V);
    analogWrite (EN2, V);
  
//  analogWrite (EN1, 255);
//  analogWrite (EN2, 255);
  
}
void loop() { 


    
      Serial.println ("Andando para frente: ");
      digitalWrite (IN1, HIGH); digitalWrite (IN2, LOW);
      digitalWrite (IN3, HIGH); digitalWrite (IN4,LOW);
      delay (4000);
      digitalWrite (IN1, LOW); digitalWrite (IN2, LOW);
      digitalWrite (IN3, LOW); digitalWrite (IN4,LOW);    
      delay (1000);
      Serial.println ("Andando para Tras: ");      
      digitalWrite (IN1, LOW); digitalWrite (IN2, HIGH);
      digitalWrite (IN3, LOW); digitalWrite (IN4,HIGH);
      delay (4000);
      digitalWrite (IN1, LOW); digitalWrite (IN2, LOW);
      digitalWrite (IN3, LOW); digitalWrite (IN4,LOW);    
      delay (1000);
      Serial.println ("Andando para esquerda: ");
      digitalWrite (IN1, LOW); digitalWrite (IN2, HIGH);
      digitalWrite (IN3, HIGH); digitalWrite (IN4,LOW);
      delay (4000);   
      digitalWrite (IN1, LOW); digitalWrite (IN2, LOW);
      digitalWrite (IN3, LOW); digitalWrite (IN4,LOW);    
      delay (1000);
      Serial.println ("Andando para direita: ");        
      digitalWrite (IN1, HIGH); digitalWrite (IN2, LOW);
      digitalWrite (IN3, LOW); digitalWrite (IN4,HIGH);
      delay (4000); 
      digitalWrite (IN1, LOW); digitalWrite (IN2, LOW);
      digitalWrite (IN3, LOW); digitalWrite (IN4,LOW);  
      delay (1000);
      //Fazer 5 leituras dos sensores, Aproveitar para colocar na linha branca e preta uma a cada leitura
      for (i = 0; i <= 5; i += 1){
       Serial.print ("Sensor esquerdo 1: ");  
      Serial.println (analogRead(SE1));
      Serial.print ("Sensor direito 1: "); 
      Serial.println (analogRead(SD1));
      Serial.print ("Sensor esquerdo 2: "); 
      Serial.println (analogRead(SE2));
      Serial.print ("Sensor direito 2: "); 
      Serial.println (analogRead(SD2));
      Serial.println (" ");
      delay (3000);
    }
}
