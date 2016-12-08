#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
char inbyte;    
int LED = 13;   
 
void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
  lcd.write("App RunningText");
 
}
 
void loop()
{
  if (Serial.available()) {
    delay(100);
 
    inbyte = Serial.read();
    if( inbyte == '1' ) function1();
 
    if (inbyte == '*')
    {
      lcd.clear();
      while (Serial.available() > 0)
      {
        lcd.write(Serial.read());
      }
    }
  }
}
 
void function1()
{
  lcd.clear();
  lcd.write("Testing 1");
}
 
