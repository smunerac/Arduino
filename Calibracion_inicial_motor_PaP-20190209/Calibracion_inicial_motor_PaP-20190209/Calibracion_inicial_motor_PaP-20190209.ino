//para el pulsador contador
const int boton = 7; //Le ponemos nombre al pin del pulsador
int contador = 0;  //Variable para guardar la cuenta de pulsaciones
int estadoAnteriorBoton = 0; //Declaramos e inicializamos la variable
int valorBoton = 0; //Declaramos e inicializamos la variable

long pasos=(49000L);  // definimos el numero de pasos a ejecutar
long vel=2200L;     // definimos las RPM del motor
//float mm=1.5;
//long double avance;

/*
  www.diymakers.es
  by A.García
  Mover motores paso a paso con Arduino
  Tutorial en: http://diymakers.es/mover-motores-paso-paso-con-arduino/
*/
 
#include "Stepper.h" //Importamos la librería para controlar motores paso a paso
 //64 es la relacion de la caja reductora  =>  1280
#define STEPS 20 //Ponemos el número de pasos que necesita para dar una vuelta. 200 en nuestro caso
                  // en este caso lo asumimos por ahora
                  
// Ponemos nombre al motor, el número de pasos y los pins de control
Stepper stepper(STEPS, 8, 9, 10, 11); //Stepper nombre motor (número de pasos por vuelta, pins de control)
int v1=0;  //Pulsador derecha
int v2=0;   //Pulsador izquierda
int direccion;  //Variable para indicar la direccón
 
void setup() {
 // pinMode(derecha,INPUT);
 // pinMode(izquierda,INPUT);
   Serial.begin(9600);   //Inicia comunicación serie
  pinMode(boton,INPUT);     //Configura el pin 2 como una entrada, pulsador
}

 
void loop() {
 // avance= (  (pasos*mm)/(0.7)  )   ;
 v1=analogRead(2); //Lectura pulsador 1
 v2=analogRead(3); //Lectura pulsador 2
 stepper.setSpeed(vel); //Indicamos la velocidad al motor 

  //para el funcionamiento

// pot = map(v0, 0, 1023, 10, 150); //Establecemos la velocidad entre 30 y 150 rpm
 
  if(v1>400)     {
    pasos=pasos;
    // direccion=-20;  //el motor gira a la izquierda
  }
 
  if(v2>400)   {
    pasos=pasos;
  }

  if((v1<400) && (v2<400))  {
    stepper.setSpeed(0); //Indicamos la velocidad al motor
  }


  if((v1>400) && (v2>400))  {
    stepper.setSpeed(0); //Indicamos la velocidad al motor
  }

 
// para el pulsador con antirrebote
valorBoton=digitalRead(boton); //Leemos el estado del pulsador
delay(100);
if(valorBoton!=estadoAnteriorBoton){ //Si hay un cambio de estado, entramos en el if

  if(valorBoton==1){
    contador++; //Aumentamos en una unidad la cuenta
  // Serial.println(contador); //Imprime el valor por consola
    //stepper.setSpeed(vel); //Indicamos la velocidad al motor
    stepper.step(pasos); //Indicamos la dirección al motor
 /* stepper.step(pasos);
    stepper.step(pasos);
    stepper.step(pasos);
    stepper.step(pasos);    
    stepper.step(pasos);
    stepper.step(pasos);
    stepper.step(pasos);
    stepper.step(pasos);
    stepper.step(pasos);   */
   // digitalWrite(led,HIGH); //Encendemos el led
  }
if(valorBoton==0){
   // digitalWrite(led,LOW); //Apagamos el led
  }
}
estadoAnteriorBoton=valorBoton; //guardamos el estado actual del pulsador para la siguiente iteración



  
}
