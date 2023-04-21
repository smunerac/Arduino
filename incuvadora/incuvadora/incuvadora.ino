#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27

#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22  //  (5v,out,   ,GND)

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);



void setup() {
  dht.begin();
  
  lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
}

void loop() {
 int h = dht.readHumidity();// Lee la humedad
int t= dht.readTemperature();//Lee la temperatura
   
   lcd.setCursor(0,0);
   lcd .write("Hum.Rel ");
   lcd.setCursor(8,0);
   lcd .print(h);
   lcd.setCursor(11,0);
  // lcd .write("%");
   lcd.setCursor(0,1);
   lcd.write("Temp ");
   lcd.setCursor(5,1);
   lcd .print(t);
   lcd.setCursor(7,1);
 lcd.write(" C ");


}
