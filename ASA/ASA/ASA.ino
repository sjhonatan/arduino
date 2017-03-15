/*
Jhonatan da Silva
Last Updated version :
Wed Mar 15 14:49:36 2017
Number of code lines: 
34
*/
int a0 = 0;
int a1 = 1;
int voltage[100];
int current[100];
int j = 0;
int serialRead = 0;
bool send = false;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while(j < 100){
      voltage[j] analogRead(a0);
      current[j] analogRead(a1);
      j++;
  }
  send = true;
  j = 0;
  while(send){
      if (Serial.available() > 0) {
        serialRead = Serial.read();
        if(serialRead == 65){
            for(j = 0; j < 100; j++){
                Serial.println(voltage[j]);
                Serial.println(current[j]);
            }
            send = false;
            send = false;
        }
      }
   }
}
