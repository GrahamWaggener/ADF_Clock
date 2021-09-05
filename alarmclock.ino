// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS3231.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DS3231 clock;
RTCDateTime dt;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialize deez nuts");
  clock.begin();    

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  pinMode(A6, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  dt = clock.getDateTime();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(6, 0);
  lcd.print(dt.year);
    lcd.setCursor(0, 0);
  lcd.print(dt.month);
    lcd.setCursor(3, 0);
  lcd.print(dt.day);
    lcd.setCursor(0, 1);
  lcd.print(dt.hour);
    lcd.setCursor(3, 1);
  lcd.print(dt.minute);
    lcd.setCursor(6, 1);
  lcd.print(dt.second);
  //Dashes
  lcd.setCursor(5, 0);
  lcd.print("-");
   lcd.setCursor(2, 0);
  lcd.print("-");
   lcd.setCursor(2, 1);
  lcd.print(":");
   lcd.setCursor(5, 1);
  lcd.print(":");

  if((dt.hour==23)&&(dt.minute==59)&&(dt.second==55)){
    analogWrite(A6, 900);
    delay(100);}
    

  buttonState = digitalRead(5);

  if (buttonState == LOW){
    analogWrite(A6, 0); }
  
}
