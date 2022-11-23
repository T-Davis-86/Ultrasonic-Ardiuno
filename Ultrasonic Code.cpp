#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int x = 1;
const int distT = 3;
const int distE = 2;
float Dist;
long Dur;
float distD;
float avgD;
LiquidCrystal_I2C lcd(0x20,16,2);

int Display()
{
  lcd.setCursor(0,0);
  lcd.print("<---Distance--->");
  lcd.setCursor(11,1);
  lcd.print("IN");
  lcd.setCursor(3,1);   
  lcd.print(avgD);
  delay(1000);  
}

void setup()
{
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  pinMode(distT, OUTPUT);  
  pinMode(distE, INPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int x = 1; x < 1000; x++);
  {
  digitalWrite(distT, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(distT, LOW);  
  Dur = pulseIn(distE, HIGH);
  Dist = Dur*0.01355/2; 
  distD = distD + Dist;
  } 
  avgD = distD / x;
  //Serial.println(Davg);
  Display();
  distD = 0;
}
 