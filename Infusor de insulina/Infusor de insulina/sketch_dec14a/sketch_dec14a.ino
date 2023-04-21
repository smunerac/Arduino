#include "Time.h" 
#include "Stepper.h"      //Importamos la librería para controlar motores paso a paso
                          //64 es la relacion de la caja reductora  =>  1280   =>> Estos datos nunca se cumplieron en realidad
#define STEPS 20          //Ponemos el número de pasos que necesita para dar una vuelta. 

// Para el funcionamiento y ejecucion del dispositivo
long pas=(10L);   //Definimos el numero de pasos a ejecutar
long pasos=(10L);   //Definimos el numero de pasos a ejecutar
long vel=1000L;         //Definimos las RPM del motor
float bolus=5;
float basal=0.5;

//para el pulsador de inicio de proceso
//const int boton = 7; //Le ponemos nombre al pin del pulsador
long contador=pas;  //Variable para guardar la cuenta de pulsaciones
int estadoAnteriorBoton = 0; //Declaramos e inicializamos la variable
int valorBoton = 0; //Declaramos e inicializamos la variable

// Para el calculo del tiempo de ejecucion
unsigned long tiempo1;
unsigned long tiempo2;
unsigned long tiempo_de_ejecucion;
unsigned long milesimas;

// Ponemos nombre al motor, el número de pasos y los pines de control
Stepper stepper(STEPS, 7, 6, 5, 4); //Stepper nombre motor (número de pasos por vuelta, pins de control)
int v1=0;   //Pulsador derecha
int v2=0;   //Pulsador izquierda
int direccion;  //Variable para indicar la direccón

//Para la pantalla Nokia
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
# define LCD_RST 9 
# define LCD_CE 8 
# define LCD_DC 10 
# define LCD_DIN 11 
# define LCD_CLK 13 
# define LCD_LIGHT 12 

boolean backlight = false;   //Luz de fondo de la pantalla
int contrast=50;            //Nivel de contraste de la pantalla

int menuitem = 1;
int page = 1;

//Funcionamiento de Menu
volatile boolean up = false;
volatile boolean down = false;
volatile boolean middle = false;
// Para los pulsadores de membrana
int downButtonState = 0;
int upButtonState = 0;  
int selectButtonState = 0;          
int lastDownButtonState = 0;
int lastSelectButtonState = 0;
int lastUpButtonState = 0;
//Pantalla Nokia
Adafruit_PCD8544 display = Adafruit_PCD8544( LCD_DC, LCD_CE, LCD_RST);

void setup() {
 Serial.begin(9600);

  pinMode(LCD_LIGHT,OUTPUT);    //Luz de fondo pantalla Nokia
  digitalWrite(LCD_LIGHT,LOW); //Turn Backlight ON
    
  display.begin();              //Inicializar pantalla   
  display.setContrast(contrast); //Set contrast to 50
  display.clearDisplay(); 
  display.display();   
}

void loop() {
  
  drawMenu();
//Lectura de pulsadores
int boton1 = analogRead(0);
int boton2 = analogRead(1);
int boton3 = analogRead(2);
int boton4 = analogRead(3);
//Logica invertida para pulsadores leidos por pines analogos
 if (boton1 > 800 && boton1 < 1024){
  downButtonState=false;}
 else if (boton1 <= 800){
   downButtonState=true;}
 
 if (boton2 > 800 && boton2 < 1024){
  selectButtonState=false;}
 else if (boton2 <= 800){
   selectButtonState=true;}

  if (boton3 > 800 && boton3 < 1024){
    upButtonState=false;}
 else if (boton3 <= 800){
 upButtonState=true;}  

    if (boton4 > 800 && boton4 < 1024){
     valorBoton=HIGH;
     regresar();}
    else if (boton4 <= 800){
     valorBoton=LOW;}
 
 if (bolus<0.1){
  bolus=0.1; }
 if (basal<0.2){
  basal=0.2; }
  
 stepper.setSpeed(vel); //Indicamos la velocidad al motor 

  checkIfDownButtonIsPressed();
  checkIfUpButtonIsPressed();
  checkIfSelectButtonIsPressed();

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


void inyectar_bolus() {

      display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 0);
    display.print("   INYECTANDO      BOLUS");
    display.drawFastHLine(0,15,83,BLACK);
    display.setCursor(2, 20);
    display.print("   Espere      un momento   por favor...");
    display.setTextSize(2);
    display.display();
    int varaux1=(bolus/0.01415);
            stepper.step(varaux1); //Indicamos la dirección al motor    
      } 

void inyectar_basal() {

      display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 0);
    display.print("  INYECTANDO      BASAL");
    display.drawFastHLine(0,15,83,BLACK);
    display.setCursor(2, 20);
    display.print("   Espere      un momento   por favor...");
    display.setTextSize(2);
    display.display();
    int n=basal/0.1415  ;
    int varaux2=60/n  ;
        for (int i=0; i<n; i++){
            stepper.step(10); //Indicamos la dirección al motor    
            delay(varaux2);
          }
      } 

void regresar() {

        display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(4, 0);
    display.print(" REGRESANDO ");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(2, 15);
    display.print("   Espere      un momento   por favor...");
    display.setTextSize(2);
    display.display();
            stepper.step(-100); //Indicamos la dirección al motor    
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
    
   /* if (backlight)     {
      display.print("ON");    }
    else     {
      display.print("OFF");    }
    display.display();   */
    
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

  void resetDefaults()  {
    contrast = 50;
    setContrast();
    backlight = true;
    bolus=5;
    basal=0.5; 
    turnBacklightOn();  }

  void setContrast()  {
    display.setContrast(contrast);
    display.display();  }

  void turnBacklightOn()  {
    digitalWrite(LCD_LIGHT,LOW);  }

  void turnBacklightOff()  {
    digitalWrite(LCD_LIGHT,HIGH);  }



// Hasta ahora no se usa  (solo para tener los comandos anteriores)
void funcionpropia() {

 stepper.step(pasos); //Indicamos la dirección al motor
     //  tiempo1=micros()      ; 
     // Serial.print("tiempo 1= "); //Imprime el valor en el monitor serial 
     // Serial.println(tiempo1); //Imprime el valor en el monitor serial 
        // Lo que sucede cuando el pulsador se presiona, o franco de subida
      pas=abs(pasos);
      if (contador==pas);{
      tiempo2=micros()          ; }
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
  }



// VERIFICAR SI LOS PULSADORES ESTAN PRESIONADOS
//Pulsador "Abajo"
  void checkIfDownButtonIsPressed()  {
    if (downButtonState != lastDownButtonState)   {
    if (downButtonState == 0)     {
      down=true;    }
    delay(50);  }
   lastDownButtonState = downButtonState;  }
//Pulsador "Arriba"
void checkIfUpButtonIsPressed()  {
  if (upButtonState != lastUpButtonState)  {
    if (upButtonState == 0) {
      up=true;    }
    delay(50);  }
   lastUpButtonState = upButtonState;  }
//Pulsador "Centro"
void checkIfSelectButtonIsPressed(){
   if (selectButtonState != lastSelectButtonState)   {
    if (selectButtonState == 0) {
      middle=true;    }
    delay(50);  }
   lastSelectButtonState = selectButtonState;  }



/*if(valorBoton!=estadoAnteriorBoton){ //Si hay un cambio de estado, entramos en el if
//  if(valorBoton==1){
void ejecutar() {
        for (int i=0; i<500; i++){
            stepper.step(-pasos); //Indicamos la dirección al motor    
            delay(800);
          }
      contador++; //Aumentamos en una unidad la cuenta
      tiempo1=micros()      ; 
     // Serial.print("tiempo 1= "); //Imprime el valor en el monitor serial 
     // Serial.println(tiempo1); //Imprime el valor en el monitor serial 
        // Lo que sucede cuando el pulsador se presiona, o franco de subida
      }    
      if(valorBoton==0){
    Lo que sucede cuando el pulsador NO se presiona, o franco de bajada
  //    }
//  }
//estadoAnteriorBoton=valorBoton; //guardamos el estado actual del pulsador para la siguiente iteración
*/


/*      LINKS DE BASTANTE INTERES CON RESPECTO A LA PANTALLA NOKIA

https://blog.bricogeek.com/noticias/arduino/como-hacer-un-menu-para-lcd-con-arduino/
https://www.youtube.com/watch?time_continue=122&v=VtZvf5T98FI
https://github.com/adafruit/Adafruit-GFX-Library                      //Libreria necesaria
https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library   ////Libreria necesaria
http://educ8s.tv/arduino-nokia-5110-menu/
https://www.youtube.com/watch?v=aDwrMeu4k9Y
https://codigofacilito.com/articulos/pantalla-lcd-nokia-5110-con-arduino
http://www.rinkydinkelectronics.com/library.php?id=47
https://www.luisllamas.es/conectar-arduino-a-un-display-lcd-nokia-5110/
https://electronilab.co/tutoriales/tutorial-lcd-grafico-nokia-5110-con-arduino/
https://www.todavianose.com/pantalla-nokia-5110-lcd-arduino/
https://www.web-robotica.com/arduino/como-utilizar-la-pantalla-grafica-nokia-5110-lcd-84x48-con-arduinogenuino
http://kio4.com/arduino/32pantallanokia.htm
https://giltesa.com/2017/07/29/menu-submenus-lcd-arduino-encoder
https://www.forosdeelectronica.com/threads/aporte-construcci%C3%B3n-de-menus-con-submenus.158941/

*/


  