int a0 = 0;
int a1 = 1;
int voltage = 0;
int current = 0;
int serialRead = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  voltage = analogRead(a0);
  current = analogRead(a1);
  if (Serial.available() > 0) {
    serialRead = Serial.read();
    if(serialRead == 65){
       Serial.println(voltage);
       Serial.println(current);
    }
  }
}
