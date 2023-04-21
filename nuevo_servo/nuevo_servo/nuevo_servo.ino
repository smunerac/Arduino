#include <Servo.h>
Servo servoRotCont; // crea los objetos para controlar los servomotores

void setup() {

  servoRotCont.attach(11); }
void loop(){
  servoRotCont.write(0);//clockwise
  delay(4000);
  servoRotCont.write(90); //stop (el valor 90 depende del motor.
  //Es conveniente probar valores por encima o por debajo
  //de 90 hasta comprobar que se para el servomotor.
  delay(2000);
  servoRotCont.write(180);//counter-clockwise
  delay(4000);
  servoRotCont.write(90); //stop
  delay(2000);
}