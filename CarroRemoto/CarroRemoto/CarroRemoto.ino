
#include <SoftwareSerial.h>
SoftwareSerial blue(3,4);

#include <LiquidCrystal.h>
int RS=7;
int E=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int pincontraste_pwm=6;    
int grado_contraste=130; 
LiquidCrystal lcd(RS,E,d4,d5,d6,d7);  

void setup() {
  lcd.begin(16, 2);
  blue.begin(9600);

}

void loop() {
  analogWrite(pincontraste_pwm,grado_contraste); 
  // see if there's incoming serial data:
  if (blue.available() > 0) {
    // read the oldest byte in the serial buffer:
    int incomingByte = blue.read();
    
     // action depending on the instruction
    // as well as sending a confirmation back to the app
    switch (incomingByte) {
      case 'A':
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Adelante");
      delay(100);
        break; 
        case 'B':
        lcd.clear();
       lcd.setCursor(0,0);
   lcd.print("Atras");
        delay(100);
        break;
      case 'C':
        lcd.clear();
       lcd.print("Izquierda");
        delay(100);
        break;
      case 'D':
        lcd.clear();
       lcd.print("Derecha");
        delay(100);
        break;
      case 'E':
        lcd.clear();
       lcd.print("Triangulo");
        delay(100);
        break;
      case 'F':
         lcd.clear();
        lcd.print("Cruz");
        delay(100);
        break;
      case 'G':
        lcd.clear();
        lcd.print("Cuadro");
        delay(100);
        break;
        case 'H':
        lcd.clear();
        lcd.print("Circulo");
        delay(100);
        break;
      default: 
        // if nothing matches, do nothing
        break;
    }
  }
}

