// LIBRERIAS REQUERIDAS
#include <U8g2lib.h>  // U8g2 Library for Oled https://github.com/olikraus/u8g2
#include "Time.h" 
#include "Stepper.h" 
#include <Wire.h>
#include <SoftwareSerial.h>

//DEFINICIONES BASICAS 
int loop_pass=1;  // Variable used to display text or the bitmap
// U8g2 Library Full Frame Buffer mode used in this tutorial
U8G2_SSD1327_MIDAS_128X128_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 7, /* dc=*/ 9, /* reset=*/ 8);    //DIN=51,CLK=52
#define STEPS 20          //Definimos el número de pasos que requiere el motor paso a paso para un giro.
SoftwareSerial blue(10,11);       // (RX, TX) en Arduino 
Stepper stepper(STEPS, /*Marron*/ 28, /*Negro*/29,/*Blanco*/ 30, /*Rojo*/31); //Stepper nombre motor (número de pasos por vuelta, pins de control)

//DEFINICION DE PINES Y CONSTANTES UTILIZADAS
//int pwm1=0;     //Velocidad del motor
int comando;
const int pulsador_1 = 22; // Entrada digital para el pulsador
const int pulsador_2 = 24; // Entrada digital para el pulsador
const int pulsador_3 = 15; // Entrada digital para el pulsador  
const int pulsador_4 = 17; // Entrada digital para el pulsador  
const int pulsador_5 = 18; // Entrada digital para el pulsador final de carrera inicial
const int pulsador_6 = 19; // Entrada digital para el pulsador final de carrera final
const int tiempoAntirrebote = 10; // tiempo en ms para evitar el rebote
//Para el funcionamiento de pulsadores con su correccion por antirrebote
int cuenta = 0;
int estadoBoton_1=0;
int estadoBotonAnterior_1=0;
int estadoBoton_2=0;
int estadoBotonAnterior_2=0; 
int estadoBoton_3=0;
int estadoBotonAnterior_3=0;
int estadoBoton_4=0;
int estadoBotonAnterior_4=0; 
int estadoBoton_5=0;
int estadoBotonAnterior_5=0;
int estadoBoton_6=0;
int estadoBotonAnterior_6=0; 
// Para el calculo del tiempo de ejecucion
unsigned long tiempo1;
unsigned long tiempo2;
unsigned long tiempo_de_ejecucion;
unsigned long milesimas;


long vel=2500L;             //Definimos la velocidad del motor paso a paso [RPM]
int resolucionZ=20;         //[20 Pasos >> 0.1 UI]
float bolus_UI=1.5;
float basal_UI=0;
float bolus_pasos=(-(bolus_UI*200));        //[Pasos a inyectar por el motor]
float basal_pasos=-((basal_UI*200));         //(-0.001/Rel_pasos_insulina); //(3/Rel_pasos_insulina);      //[UI-U100]
//Relacion de reduccion de la caja (2091425/4212=496.539648623) aprox 500 Rev eje del motor segun fabricante
float Rel_Red=(2091425/4212);   //Motor chino tipo U
//Negativo inyecta
//Positivo retrocede

//Para el Menu
int menuitem = 1;
int page = 1; 

//POR ORDENAR Y DISMINUIR///////////////////////////////////////////////////////////////////////

// Para el funcionamiento y ejecucion del dispositivo
long pas=(2200L);   //Definimos el numero de pasos a ejecutar
//long oe=(-((bolus_UI*Rel_pasos_insulina))),L;
long pasos=(2000L);   //Definimos el numero de pasos a ejecutar

long w=(4212/2091425);
long varaux5=(pasos);  //*w*5);
long contador=pas;  //Variable para guardar la cuenta de pulsaciones

// Ponemos nombre al motor, el número de pasos y los pines de control
int direccion;  //Variable para indicar la direccón
////////////////////////////////////////////////////////////////////////////////////////////



void setup() {
Serial.begin(19200);        //Velocidad de transmicion con el monitor serial
blue.begin(9600);           //Velocidad de transmicion con el modulo Bluetooth
pinMode(pulsador_1, INPUT); // PIN digital del pulsador como entrada
pinMode(pulsador_2, INPUT); // PIN digital del pulsador como entrada
pinMode(pulsador_3, INPUT); // PIN digital del pulsador como entrada
pinMode(pulsador_4, INPUT); // PIN digital del pulsador como entrada
pinMode(pulsador_5, INPUT); // PIN digital del final de carrera como entrada
pinMode(pulsador_6, INPUT); // PIN digital del final de carrera como entrada
//Pines usados para alimentacion y control de componentes
pinMode(13, OUTPUT);
pinMode(20, OUTPUT);
pinMode(47, OUTPUT);
//Pantalla Oled 1.5
u8g2.begin();                 //  Start U8g2 library
u8g2.setContrast(200);        //  Brightness setting from 0 to 255
u8g2.clearBuffer(); 
//Motor paso a paso
stepper.setSpeed(vel);        //Indicamos la velocidad al motor
}

void loop() {
  
drawMenu();  
  
//Para control de componentes
digitalWrite(13,HIGH);        //Modulo Bluetooth
digitalWrite(20,HIGH);        //Pantalla
digitalWrite(47,HIGH);        //Pulsadores
//LECTURA DE PULSADORES
estadoBoton_1 = digitalRead(pulsador_1);
estadoBoton_2 = digitalRead(pulsador_2); 
estadoBoton_3 = digitalRead(pulsador_3);
estadoBoton_4 = digitalRead(pulsador_4);
estadoBoton_5 = digitalRead(pulsador_5);
estadoBoton_6 = digitalRead(pulsador_6);
leer_botones();
//CONTROL DE VARIABLES
if (bolus_UI<0.1){
  bolus_UI=0.1; }
if (basal_UI<0.1){
  basal_UI=0.1; }


 // Verificamos la disponibilidad del bluethott
  if (blue.available() > 0) {
    // Leemos el dato.
    int comando = blue.read();
  
    switch (comando) {
      case 'A':           //Izquierda
    u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "primero" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);
 
      u8g2.clearBuffer();  //Borrar pantalla
        Serial.println("A");   
//        inyectar_bolus();
        break;
      case 'B':           //Arriba
    u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "segundo" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);

      u8g2.clearBuffer();  //Borrar pantalla
        Serial.println("B");  
//        inyectar_basal();
        break;
      case 'C':           //Derecha
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "tercero" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);

      u8g2.clearBuffer();  //Borrar pantalla
        Serial.println("C");  
//        adelante();
        break;
      case 'D':           //Abajo
    u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "cuarto" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);
      if (basal_UI<0.1){
      basal_UI=0.1; }
      u8g2.clearBuffer();  //Borrar pantalla
        Serial.println("D");  
//        atras();
        break;
      case 'E':           //Select
        Serial.println("E"); 
//        apagar();
        break;
      case 'F':           //Start
        Serial.println("F"); 
//        regresar();
        break;
      case 'G':           //Cuadro "Izquierda"
        Serial.println("G");
        
        break;
      case 'H':           //Triangulo "Arriba"
        Serial.println("H");

        break;
      case 'I':          //Cruz "Derecha"
        Serial.println("I");  
 
        break;
      case 'J':         //Circulo "Abajo"
        Serial.println("J");

        break;
      default: 
        // if nothing matches, do nothing
        break;
    }
  }
 else{

delay(120);         
}

}  








 if (up && page == 1 ) {
    up = false;
    menuitem++;
    if (menuitem==0)    {
      menuitem=4;    }   
    if (menuitem==5) {
      menuitem=1;    }      }    
  if (up && page == 2 ) {
    up = false;
    bolus=bolus-0.05;
    setContrast();  }
   if (up && page == 3 ) {
    up = false;
    basal=basal-0.1;
    setContrast();  }   
    

  if (down && page == 1) {
    down = false;
    menuitem--;
    if (menuitem==5)     {
      menuitem=1;    }   
    if (menuitem==0)    {
      menuitem=4;    }    }
  if (down && page == 2 ) {
    down = false;
    bolus=bolus+0.05;   }
  if (down && page == 3 ) {
    down = false;
    basal=basal+0.1;
    setContrast();  }


  if (middle) {
    middle = false;

   if (page == 1 && menuitem==1) {
      page=2;     }
   else if (page == 2) {
    page=1;}

    if (page == 1 && menuitem==2)     {
    page=3;    }
    else if (page==3){
      page=1;}

   if (page == 1 && menuitem ==3)    {
     inyectar_bolus();
      resetDefaults();    }

   if (page == 1 && menuitem ==4)    {
     inyectar_basal();
      resetDefaults();    }
   
   }
   
  }










  void drawMenu()  {
    
  if (page==1)   {    
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 0);
    display.print("INFUS.INSULINA");
//    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 10);
   
    if (menuitem==1)     { 
      display.setTextColor(WHITE, BLACK);    }
    else     {
      display.setTextColor(BLACK, WHITE);    }
    display.print(">Conf. Bolus");
    display.setCursor(0, 20);
   
    if (menuitem==2)     {
      display.setTextColor(WHITE, BLACK);    }
    else     {
      display.setTextColor(BLACK, WHITE);    }    
    display.print(">Conf. Basal");
    

    if (menuitem==3)     { 
      display.setTextColor(WHITE, BLACK);    }
    else     {
      display.setTextColor(BLACK, WHITE);    }  
    display.setCursor(0, 30);
    display.print(">Inyec. Bolus<");

    if (menuitem==4)     { 
      display.setTextColor(WHITE, BLACK);    }
    else     {
      display.setTextColor(BLACK, WHITE);    }  
    display.setCursor(0, 40);
    display.print(">Inyec. Basal<");
    
    display.display();
  }
    
 
   if (page==2)   {
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(4, 0);
    display.print("UI A APLICAR ");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(2, 15);
    display.print("UI tipo U100");
    display.setTextSize(2);
    display.setCursor(5, 25);
    display.print(bolus);
    display.setTextSize(2);
    display.display();
  }

    else if (page==3)   {
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(2, 0);
    display.print("BASAL");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(5, 15);
    display.print("UI / min");
    display.setTextSize(2);
    display.setCursor(5, 25);
    display.print(basal);
    display.setTextSize(2);
    display.display();
  }
  
  }


























void aumentar_bolus() {
      bolus_UI=bolus_UI+resolucionZ;
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "UNO" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);
      u8g2.clearBuffer();  //Borrar pantalla
      Serial.println(bolus_UI);                 }

void disminuir_bolus() {
      bolus_UI=bolus_UI-resolucionZ;
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "DOS" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
      if (bolus_UI<0.1){
      bolus_UI=0.1; }
         stepper.step(1000);
      u8g2.clearBuffer();  //Borrar pantalla
      Serial.println(bolus_UI);                 }

void aumentar_basal() {
      basal_UI=basal_UI+resolucionZ;
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "TRES" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);
      u8g2.clearBuffer();  //Borrar pantalla
      Serial.println(basal_UI);                 }

void disminuir_basal() {
      basal_UI=basal_UI-resolucionZ;
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "CUATRO" );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      delay(500);
         stepper.step(1000);
      if (basal_UI<0.1){
      basal_UI=0.1; }
      u8g2.clearBuffer();  //Borrar pantalla
      Serial.println(basal_UI);                 }

void inyectar_bolus() {
      u8g2.clearBuffer();  //Borrar pantalla
//      display.setTextColor(BLACK, WHITE);
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 11 , "INYECTANDO BOLUS" );  //  establece la posición y el texto para mostrar
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
//      u8g2 . drawStr ( 0 , 20 , "INYECTANDO BOLUS" );  //  establece la posición y el texto para mostrar
//      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 30 , "Espere un momento por favor..." );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
       int varaux1=(bolus_UI/0.01415);
stepper.step(bolus_pasos); //Indicamos la dirección al motor    
      } 

void inyectar_basal() {
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
//      u8g2 . drawStr ( 0 , 11 , "INYECTANDO BASAL" );  //  establece la posición y el texto para mostrar
//      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "INYECTANDO BASAL" );  //  establece la posición y el texto para mostrar
//      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 30 , "Espere un momento por favor..." );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
 //      int n=basal/w  ;
  //     int varaux2=60/n  ;
//  for (long i=1; i<100; i++){
      tiempo1=micros()          ; 
      stepper.step((basal_pasos)); //Indicamos la dirección al motor  
      tiempo2=micros()          ;   
      tiempo_de_ejecucion=(tiempo2-tiempo1)/1000000;
      Serial.print("Tiempo"); //Imprime el valor en el monitor serial 
      Serial.print(tiempo_de_ejecucion); //Imprime el valor en el monitor serial 
      Serial.println("  segundos"); //Imprime el valor en el monitor serial 
      milesimas=((tiempo2-tiempo1)%1000000)/1000;
      Serial.print(milesimas); //Imprime el valor en el monitor serial 
      Serial.println("  milesimas"); //Imprime el valor en el monitor serial 
    //  delay(2000);                  
      exit;     
             }  

void regresar() {
      u8g2.clearBuffer();  //Borrar pantalla
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 20 , "REGRESANDO" );  //  establece la posición y el texto para mostrar
      u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
      u8g2 . drawStr ( 0 , 30 , "Espere un momento por favor..." );  //  establece la posición y el texto para mostrar
      u8g2.sendBuffer();   // Update Oled display
      stepper.step(1000); //Indicamos la dirección al motor
      u8g2.clearBuffer();  //Borrar pantalla
      } 

void apagar_motor(){
  u8g2.clearBuffer();  //Borrar pantalla
  u8g2 . setFont (u8g2_font_fub11_tr);  // Elija la fuente a usar
  digitalWrite(28, 0);
  digitalWrite(29, 0);
  digitalWrite(30, 0);
  digitalWrite(31, 0);
  u8g2 . drawStr ( 0 , 20 , "Motor apagado" );  //  establece la posición y el texto para mostrar
  u8g2.sendBuffer();   // Update Oled display
  Serial.println("Motor Apagado");
  delay(500);
  u8g2.clearBuffer();  //Borrar pantalla
}





// Hasta ahora no se usa  (solo para tener los comandos anteriores)
void funcionpropia() {
    stepper.step(pasos); //Indicamos la dirección al motor
     //  tiempo1=micros()      ; 
     // Serial.print("tiempo 1= "); //Imprime el valor en el monitor serial 
     // Serial.println(tiempo1); //Imprime el valor en el monitor serial 
        // Lo que sucede cuando el pulsador se presiona, o franco de subida
      pas=abs(pasos);
      if (contador==pas);{
      tiempo2=micros()          ; 
      Serial.print("tiempo 2= "); //Imprime el valor en el monitor serial 
      Serial.println(tiempo2); //Imprime el valor en el monitor serial
      tiempo_de_ejecucion=(tiempo2-tiempo1)/1000000;
      Serial.print("Tiempo"); //Imprime el valor en el monitor serial 
      Serial.print(tiempo_de_ejecucion); //Imprime el valor en el monitor serial 
      Serial.println("  segundos"); //Imprime el valor en el monitor serial 
      milesimas=((tiempo2-tiempo1)%1000000)/1000;
      Serial.print(milesimas); //Imprime el valor en el monitor serial 
      Serial.println("  milesimas"); //Imprime el valor en el monitor serial 
       pasos=abs(pasos);  
  }   }

  
  void leer_botones(){
    if(estadoBoton_1 != estadoBotonAnterior_1){
      if(antirrebote1(pulsador_1)){
      disminuir_bolus();
        }
    }  
    estadoBotonAnterior_1 = estadoBoton_1;
    
    if(estadoBoton_2 != estadoBotonAnterior_2){
      if(antirrebote2(pulsador_2)){
      aumentar_bolus();
      }
    }  
    estadoBotonAnterior_2 = estadoBoton_2;

if(estadoBoton_3 != estadoBotonAnterior_3){
      if(antirrebote3(pulsador_3)){
      disminuir_basal();
      }
    }  
    estadoBotonAnterior_3 = estadoBoton_3;
    
    if(estadoBoton_4 != estadoBotonAnterior_4){
      if(antirrebote4(pulsador_4)){
      aumentar_basal();
      }
    }  
    estadoBotonAnterior_4 = estadoBoton_4;


// Los pulsadores 5 y 6 seran los finales de carrera en la inyeccion
 if(estadoBoton_5 != estadoBotonAnterior_5){
      if(antirrebote5(pulsador_5)){
      apagar_motor();
      }
    }  
    estadoBotonAnterior_5 = estadoBoton_5;
    
    if(estadoBoton_6 != estadoBotonAnterior_6){
      if(antirrebote6(pulsador_6)){
      apagar_motor();
      }
    }  
    estadoBotonAnterior_6 = estadoBoton_6;
 
 
}  
  
  
  
  
  
  
  
 // Función que evita el rebote del pulsador 1
  boolean antirrebote1(int pulsador_1){
    int contador = 0;
    boolean estado_1;
    boolean estadoAnterior_1;   
    do {
      estado_1 = digitalRead(pulsador_1);
      if(estado_1 != estadoAnterior_1) {
        contador = 0;
        estadoAnterior_1 = estado_1;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_1;
  }

  // Función que evita el rebote del pulsador 2
  boolean antirrebote2(int pulsador_2){
    int contador = 0;
    boolean estado_2;
    boolean estadoAnterior_2;   
    do {
      estado_2 = digitalRead(pulsador_2);
      if(estado_2 != estadoAnterior_2) {
        contador = 0;
        estadoAnterior_2 = estado_2;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_2;
  }
    
  // Función que evita el rebote del pulsador 3
  boolean antirrebote3(int pulsador_3){
    int contador = 0;
    boolean estado_3;
    boolean estadoAnterior_3;   
    do {
      estado_3 = digitalRead(pulsador_3);
      if(estado_3 != estadoAnterior_3) {
        contador = 0;
        estadoAnterior_3 = estado_3;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_3;
  }

  // Función que evita el rebote del pulsador 4
  boolean antirrebote4(int pulsador_4){
    int contador = 0;
    boolean estado_4;
    boolean estadoAnterior_4;   
    do {
      estado_4 = digitalRead(pulsador_4);
      if(estado_4 != estadoAnterior_4) {
        contador = 0;
        estadoAnterior_4 = estado_4;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_4;
  }

  // Función que evita el rebote del pulsador 5
  boolean antirrebote5(int pulsador_5){
    int contador = 0;
    boolean estado_5;
    boolean estadoAnterior_5;   
    do {
      estado_5 = digitalRead(pulsador_5);
      if(estado_5 != estadoAnterior_5) {
        contador = 0;
        estadoAnterior_5 = estado_5;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_5;
  }

  // Función que evita el rebote del pulsador 6
  boolean antirrebote6(int pulsador_6){
    int contador = 0;
    boolean estado_6;
    boolean estadoAnterior_6;   
    do {
      estado_6 = digitalRead(pulsador_6);
      if(estado_6 != estadoAnterior_6) {
        contador = 0;
        estadoAnterior_6 = estado_6;}
      else {
        contador = contador+ 1;  }
      delay(1);
    } while(contador < tiempoAntirrebote);   
    return estado_6;
  }