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

int pwm1=190;                    //Velocidad Motor Carro superior
int pwm2=255;                    //Velocidad Motor Grua
int pwm3=160;                    //Velocidad Motor Grua

void setup() {
  //Configuracion de Pantalla
  lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
    lcd.setCursor(0,0);
    lcd.print("Bienvenidos puente");
    lcd.setCursor(0,1);
    lcd.print("grua. Press/start/");
    delay(50);

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
s1 = digitalRead(pinFC1);  //Leemos el estado del final de carrera
s3 = digitalRead(pinFC3);  //Leemos el estado del final de carrera
s4 = digitalRead(pinFC4);  //Leemos el estado del final de carrera
s5 = digitalRead(pinFC5);  //Leemos el estado del final de carrera
s6 = digitalRead(pinFC6);  //Leemos el estado del final de carrera
s0 = digitalRead(pinboton);  //Leemos el estado del final de carrera

Peso = analogRead(AnalogPin); // La Resistencia es igual a la lectura del sensor (Analog 0)
    lcd.setCursor(10,1);
    //lcd.print("Peso=");
    //lcd.setCursor(8,0);
    lcd.print(Peso);
       delay(50);  







if(s0==HIGH){
pesar();


switch (peso) {
    case 1:
      subir();
      while(s4==LOW){
        derecha();
        s4 = digitalRead(pinFC4); } //Leemos el estado del final de carrera
       parar_carro();
       bajar();
       delay(1500);
       subir();
       izquierda();
       bajar(); 
       parar_grua();   
       lcd.clear();
       lcd.setCursor(2,1);
       lcd.print("Press  /start/");
    delay(50);
      break;

    case 2:
      subir();
      while(s4==LOW){
        derecha(); 
         s4 = digitalRead(pinFC4); } //Leemos el estado del final de carrera
       parar_carro();
       bajar();
       delay(1500);
       subir();
       while(s5==LOW){
        derecha(); 
         s5 = digitalRead(pinFC5); } //Leemos el estado del final de carrera
        parar_carro();
         bajar();
       delay(1500);
       subir();
       izquierda();
       bajar();   
       parar_grua();
       lcd.clear();
       lcd.setCursor(2,1);
       lcd.print("Press  /start/");
    delay(50);
      break;
    
    case 3:
      subir();
      while(s5==LOW){
        derecha(); 
         s5 = digitalRead(pinFC5); } //Leemos el estado del final de carrera
       parar_carro();
       bajar();
       delay(1500);
       subir();
       izquierda();
       bajar();
       parar_grua(); 
       lcd.clear();
       lcd.setCursor(2,1);
       lcd.print("Press  /start/");
    delay(50);
      break;  
    
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }



}
}



void derecha(){
    analogWrite(pin1motorcarro,pwm1); //encendemos derecha
    analogWrite(pin2motorcarro,0); 
          lcd.setCursor(0,1);
      lcd.print("Derecha          ");  
    }  //encendemos derecha
      

void izquierda(){
  s6 = digitalRead(pinFC6);  //Leemos el estado del final de carrera
    while(s6==LOW){
    analogWrite(pin1motorcarro,0);     //apagamos subida
    analogWrite(pin2motorcarro,pwm1);  
          lcd.setCursor(0,1);
      lcd.print("Izquierda           ");  
    s6 = digitalRead(pinFC6);  //Leemos el estado del final de carrera
    }   //apagamos subida  

    analogWrite(pin1motorcarro,0);     //apagamos subida
    analogWrite(pin2motorcarro,0);   }  //apagamos subida 
  

void subir(){
  s3 = digitalRead(pinFC3);  //Leemos el estado del final de carrera
    while(s3==LOW){
    analogWrite(pin1motorgrua,pwm2);       //Encendemos Subida
    analogWrite(pin2motorgrua,0);//Encendemos Subida
          lcd.setCursor(0,1);
      lcd.print("Subiendo       ");  
      s3 = digitalRead(pinFC3);  }        //Leemos el estado del final de carrera

    analogWrite(pin1motorgrua,0);       //Apagamos Subida
    analogWrite(pin2motorgrua,0); }     //Apagamos Subida  
   
void bajar(){
  s1 = digitalRead(pinFC1);  //Leemos el estado del final de carrera 
  while(s1==LOW){
    analogWrite(pin1motorgrua,0);       //Encendemos bajada
    analogWrite(pin2motorgrua,pwm3);    //Encendemos bajada 
      lcd.setCursor(0,1);
      lcd.print("Bajando        ");    
     s1 = digitalRead(pinFC1);}  //Leemos el estado del final de carrera 
     
    analogWrite(pin1motorgrua,0);       //Encendemos bajada
    analogWrite(pin2motorgrua,0);}      //Encendemos bajada 
          

void parar_carro(){
    analogWrite(pin1motorcarro,0); //apagamos derecha
    analogWrite(pin2motorcarro,0);} //apagamos derecha         



void parar_grua(){
    analogWrite(pin1motorgrua,0); //apagamos derecha
    analogWrite(pin2motorgrua,0);
    peso=0;   } //apagamos derecha   


void pesar(){
Peso = analogRead(AnalogPin); // La Resistencia es igual a la lectura del sensor (Analog 0)
  //Mostrar el Peso en pantalla LCD
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Peso=");
    lcd.setCursor(8,0);
    lcd.print(Peso);
       delay(50);   

if(Peso<110 && Peso>70){
      lcd.setCursor(0,0);
      lcd.print("Peso 1");  
      peso=1;   }
if(Peso>=110 && Peso<135){
      lcd.setCursor(0,0);
      lcd.print("Peso 2");   
      peso=2;     }
if(Peso>=135){
      lcd.setCursor(0,0);
      lcd.print("Peso 3");   
      peso=3;     }

}


