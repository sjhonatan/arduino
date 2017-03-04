/*
Jhonatan da Silva
Last Updated version :
Sun Feb  5 08:50:33 2017
Number of code lines: 
20
*/
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int serialRead = 0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}
 
void loop()
{
  if (Serial.available() > 0) {
                serialRead = Serial.read();
                lcd.clear();
                lcd.print(serialRead);     
    }
}


