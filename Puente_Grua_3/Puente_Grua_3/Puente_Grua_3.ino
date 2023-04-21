//Para la pantalla
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27
#include <SoftwareSerial.h>
LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
#include "Print.h" 
float Peso;         //Variable de Lectura del sensor.
int peso=0;
int s0=0;
int s1=0;
int s3=0;
int s6=0;
int s4=0;
int s5=0;
int AnalogPin = 0;               //Pin Sensor de peso
const int pin1motorcarro=5;     //Pin 1 Motor Carro Superior
const int pin2motorcarro=6;     //Pin 2 Motor Carro Superior
const int pin1motorgrua=10;       //Pin 1 Motor Grua
const int pin2motorgrua=11;       //Pin 2 Motor Grua
const int pinFC1=2;              //Pin señal FC 2 
const int pinFC3=3;              //Pin señal FC 3
const int pinFC6=4;              //Pin señal FC 7
const int pinFC4=7;              //Pin señal FC 8
const int pinFC5=8;              //Pin señal FC 5
const int pinboton=9;              //Pin señal FC 5

int pwm1=240;                    //Velocidad Motor Carro superior
int pwm2=160;                    //Velocidad Motor Grua
//Variables para lectura de señales de finales de carrera
int estadoAnteriorFC1 = 0; //Declaramos e inicializamos la variable
int valorFC1 = 0; //Declaramos e inicializamos la variable
int estadoAnteriorFC3 = 0; //Declaramos e inicializamos la variable
int valorFC3 = 0; //Declaramos e inicializamos la variable
int estadoAnteriorFC6 = 0; //Declaramos e inicializamos la variable
int valorFC6 = 0; //Declaramos e inicializamos la variable
int estadoAnteriorFC4 = 0; //Declaramos e inicializamos la variable
int valorFC4 = 0; //Declaramos e inicializamos la variable
int estadoAnteriorFC5 = 0; //Declaramos e inicializamos la variable
int valorFC5 = 0; //Declaramos e inicializamos la variable
int estadoAnteriorboton = 0; //Declaramos e inicializamos la variable
int valorboton = 0; //Declaramos e inicializamos la variable

void setup() {
  //Configuracion de Pantalla
  lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);

//Serial.begin(9600);   //Inicia comunicación serie-PC
pinMode(pin1motorcarro,OUTPUT);
pinMode(pin2motorcarro,OUTPUT);
pinMode(pin1motorgrua, OUTPUT);
pinMode(pin2motorgrua, OUTPUT);
pinMode(pinFC1, INPUT);
pinMode(pinFC3, INPUT);
pinMode(pinFC6, INPUT);
pinMode(pinFC4, INPUT);
pinMode(pinFC5, INPUT);
pinMode(pinboton, INPUT);
}

void loop() {

Peso = analogRead(AnalogPin); // La Resistencia es igual a la lectura del sensor (Analog 0)
//Para imprimir en pantalla de PC
//Serial.print("Peso = ");
//Serial.println(Peso);
  //Mostrar el Peso en pantalla LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Peso=");
    lcd.setCursor(6,0);
    lcd.print(Peso);
       delay(50);   
           
if(Peso<150 && Peso>0){
      lcd.setCursor(0,1);
      lcd.print("Peso 1");  
      peso=1;     }
if(Peso>=150 && Peso<240){
      lcd.setCursor(0,1);
      lcd.print("Peso 2");   
      peso=2;     }
if(Peso>=240){
      lcd.setCursor(0,1);
      lcd.print("Peso 3");   
      peso=3;     }



valorFC1=digitalRead(pinFC1); //Leemos el estado del final de carrera
delay(50);
if(valorFC1!=estadoAnteriorFC1){ //Si hay un cambio de estado, entramos en el if
  if(valorFC1==HIGH){
s1=1;
  }
if(valorFC1==LOW){
s1=0;
}
}
estadoAnteriorFC1=valorFC1; //guardamos el estado actual del final de carrera

valorFC3=digitalRead(pinFC3); //Leemos el estado del final de carrera
delay(50);
if(valorFC3!=estadoAnteriorFC3){ //Si hay un cambio de estado, entramos en el if
  if(valorFC3==HIGH){
s3=1;
  }
if(valorFC3==LOW){
s3=0;
}
}
estadoAnteriorFC3=valorFC3; //guardamos el estado actual del final de carrera

valorFC4=digitalRead(pinFC4); //Leemos el estado del final de carrera
delay(50);
if(valorFC4!=estadoAnteriorFC4){ //Si hay un cambio de estado, entramos en el if
  if(valorFC4==HIGH){
s4=1;
  }
if(valorFC4==LOW){
s4=0; 
}
}
estadoAnteriorFC4=valorFC4; //guardamos el estado actual del final de carrera


valorFC6=digitalRead(pinFC6); //Leemos el estado del final de carrera
delay(50);
if(valorFC6!=estadoAnteriorFC6){ //Si hay un cambio de estado, entramos en el if
  if(valorFC6==HIGH){
s6=1;
  }
if(valorFC6==LOW){
s6=0; 
}
}
estadoAnteriorFC6=valorFC6; //guardamos el estado actual del final de carrera


valorFC5=digitalRead(pinFC5); //Leemos el estado del final de carrera
delay(50);
if(valorFC5!=estadoAnteriorFC5){ //Si hay un cambio de estado, entramos en el if
  if(valorFC5==HIGH){
s5=1;
apagar();
  }
if(valorFC5==LOW){
s5=0;
}
}
estadoAnteriorFC5=valorFC5; //guardamos el estado actual del final de carrera

valorboton=digitalRead(pinboton); //Leemos el estado del final de carrera
delay(50);
if(valorboton!=estadoAnteriorboton){ //Si hay un cambio de estado, entramos en el if
  if(valorboton==HIGH){
s0=0;
encender();
delay(20);
  }
if(valorboton==LOW){
s0=0;
}
}
estadoAnteriorboton=valorboton; //guardamos el estado actual del final de carrera











/*
if (peso==1 && s1==1 && s6==1){
    analogWrite(pin1motorgrua,pwm1); //Encendemos subida
    analogWrite(pin2motorgrua,0);    //Encendemos subida
    if (s3==1){
    analogWrite(pin1motorgrua,0);     //apagamos subida
    analogWrite(pin2motorgrua,0);     //apagamos subida  
    analogWrite(pin1motorcarro,pwm2); //encendemos derecha
    analogWrite(pin2motorcarro,0);    //encendemos derecha
    if (s4==1 && pin1motorcarro==pwm2){
    analogWrite(pin1motorcarro,0);    //apagamos derecha
    analogWrite(pin2motorcarro,0);    //apagamos derecha  
    analogWrite(pin1motorgrua,0);     //Encendemos bajada
    analogWrite(pin2motorgrua,pwm1);  //Encendemos bajada   
    if(s1==1 && pin2motorgrua==pwm1){
    analogWrite(pin1motorgrua,0);    //apagamos bajada
    analogWrite(pin2motorgrua,0);    //apagamos bajada 
    delay(10);     
    analogWrite(pin1motorgrua,pwm1); //Encendemos subida
    analogWrite(pin2motorgrua,0);    //Encendemos subida
    if(s3==1 && pin1motorgrua==pwm1){
    analogWrite(pin1motorgrua,0);     //apagamos subida
    analogWrite(pin2motorgrua,0);     //apagamos subida
    analogWrite(pin1motorcarro,0); //encendemos izquierda
    analogWrite(pin2motorcarro,pwm2);    //encendemos izquierda        
    if(s6==1 && pin2motorcarro==pwm2){
    analogWrite(pin1motorcarro,0);    //apagamos izquierda
    analogWrite(pin2motorcarro,0);    //apagamos izquierda
    analogWrite(pin1motorgrua,0);     //encendemos bajada
    analogWrite(pin2motorgrua,pwm1);     //encendemos bajada
    if(s1==1 && pin2motorgrua==pwm1){
    analogWrite(pin1motorgrua,0);       //apagamos bajada
    analogWrite(pin2motorgrua,pwm1);     //apagamos bajada      
    }}}}}}
    
}




   // analogWrite(pin1motorgrua,0); //apagamos bajada
   // analogWrite(pin2motorgrua,0);    //apagamos bajada 
   // delay(10);  
    analogWrite(pin1motorgrua,pwm1); //Encendemos subida
    analogWrite(pin2motorgrua,0);    //Encendemos subida
   // analogWrite(pin1motorcarro,pwm2); //Encendemos derecha
   //analogWrite(pin2motorcarro,0);    //Encendemos derecha


    analogWrite(pin1motorgrua,0);    //apagamos subida
    analogWrite(pin2motorgrua,0);    //apagamos subida
    delay(10);
    analogWrite(pin1motorcarro,pwm1); //encendemos derecha
    analogWrite(pin2motorcarro,0); //encendemos derecha

    analogWrite(pin1motorcarro,0); //apagamos derecha
    analogWrite(pin2motorcarro,0); //apagamos derecha
    delay(10);
    analogWrite(pin1motorgrua,0); //Encendemos bajada
    analogWrite(pin2motorgrua,pwm1);    //Encendemos bajada
    
    analogWrite(pin1motorcarro,0);       //Encendemos izquierda
    analogWrite(pin2motorcarro,pwm1);    //Encendemos izquierda
    analogWrite(pin1motorgrua,0); //Apagamos 
    analogWrite(pin2motorgrua,0); //Apagamos
      lcd.setCursor(8,1);
      lcd.print("Paro       ");
    analogWrite(pin1motorgrua,0);       //Encendemos bajada
    analogWrite(pin2motorgrua,pwm2);    //Encendemos bajada

*/

}
void encender(){
    analogWrite(pin1motorcarro,200); //encendemos derecha
    analogWrite(pin2motorcarro,0);    //encendemos derecha
    delay(2000);
}

void apagar(){
      analogWrite(pin1motorcarro,0);     //apagamos subida
    analogWrite(pin2motorcarro,0);     //apagamos subida
}





