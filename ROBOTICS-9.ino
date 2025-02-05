#include <LiquidCrystal.h>



const int rs=12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led_pin_7 = 7;
int LDR_Pin_A0;
void setup( ) {

  lcd.begin(16, 2);


  lcd.setCursor(0, 0);
  lcd.print("AUTOMATED LIGHT");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("GROUP 9 PROJECT");
  delay(500);
  lcd.clear();

  serial.begin(9600);
  
  pinMode(led_Pin_7, OUTPUT);
}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);

  if (a < 220) {
    lcd.setCursor(0, 1);
    lcd.print("LOW LIGHT");
    digitalWrite(led_pin_7, HIGH);
    delay(500);
  }  else {
    lcd.setCursor(0, 1);
    lcd.print("HIGH LIGHT");
    digitalWrite(led_Pin_7, LOW);
    delay(500);
  }
}