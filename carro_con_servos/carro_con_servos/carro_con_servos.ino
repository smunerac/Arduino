/*
Arduino driver for Android app remote control.
This sketch listens to instructions on the Serial port
then activates motors as required
Then sends back confirmation to the app
*/

#include <Servo.h>

#define derechoParada 72
#define izquierdoParada 73
#define derechoAdelante 10
#define izquierdoAdelante 100
#define derechoAtras 90
#define izquierdoAtras 50


Servo derecho;
Servo izquierdo;

void setup() {
  
  derecho.attach(10);
  izquierdo.attach(11);
  derecho.write(derechoParada);
  izquierdo.write(izquierdoParada);
  Serial.begin(9600); 
}

void loop() {
  
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    int incomingByte = Serial.read();
    
    // action depending on the instruction
    // as well as sending a confirmation back to the app
    switch (incomingByte) {
      case 'A':
        derecho.write(derechoAdelante);
        izquierdo.write(izquierdoAdelante);
        lcd.print("Going forward");
        delay(100);
        break;
      case 'R':
        derecho.write(derechoParada);
        izquierdo.write(izquierdoAdelante);
        delay(100);
        break;
      case 'L':
        derecho.write(derechoAdelante);
        izquierdo.write(izquierdoParada);
        Serial.println("Turning left");
        delay(100);
        break;
      case 'B':
        derecho.write(derechoAtras);
        izquierdo.write(izquierdoAtras);
        Serial.println("Going backwards");
        delay(100);
        break;
      case 'S':
        derecho.write(derechoParada);
        izquierdo.write(izquierdoParada);
        Serial.println("Stopping");
        delay(100);
        break;
      default: 
        // if nothing matches, do nothing
        break;
    }
  }
} 
