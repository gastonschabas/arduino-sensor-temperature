#include <LiquidCrystal.h> // Liquid Crystal library https://www.arduino.cc/en/Reference/LiquidCrystal

/**
 * each value passed will be the digital pin used for each connector of the display
 * lcd(rs, rw, enable, d4, d5, d6, d7)
 * - rs: reguster select
 * - rw: read/write
 */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // initialize the display. 16 columns and 2 rows
}

void loop() {
  int reading = analogRead(A0); // read value returned by temperature sensor at analog input A0
  
  float voltage = reading * 5.0;
  voltage /= 1024.0; 
  
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset to degrees ((voltage - 500mV) times 100)
  
  lcd.setCursor(0,0); // set cursor at top left of the display
  lcd.clear(); // clear the display
  lcd.print("degrees: ");
  lcd.print(temperatureC);
  lcd.print("C");
  
  delay(500);
}