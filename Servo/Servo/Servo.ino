#include <Servo.h>

Servo Servo1;  // Creacion del objeto Servo1 para controlar 1 servo
 
int InAnaloga = 0;  // Pin Analogo de entrada para variar PWM
int DatoAnalogo;    // Variable para leer el dato del Pin Analogo
 
void setup() 
{ 
  Servo1.attach(9);  // Configura el pin 9 como control del servo
} 
 
void loop() 
{ 
  DatoAnalogo = analogRead(InAnaloga);            // Lee los valores del Pin Analogo (Valores entre 0 y 1023) 
  DatoAnalogo = map(DatoAnalogo, 0, 1023, 0, 179);     // Escala el valor del Pin Analogo (Valores entre 0 y 180) 
  Servo1.write(179);                  // Posiciona el servo deacuerdo al valor escalado 
} 
