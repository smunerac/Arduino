#include <Servo.h>              //Desabilita el PWM de los pines 9 y 10 en arduino UNO
Servo servo1;                   // crea los objetos para controlar los servomotores
Servo servo2;                   // crea los objetos para controlar los servomotores
const int pin_servo1=2;         //Pin de conexion de servo 1
const int pin_servo2=3;         //Pin de conexion de servo 2
const int valor_min_servo1=700;
const int valor_max_servo1=2600;
const int valor_min_servo2=700;
const int valor_max_servo2=2600;  
  
  
  
  const int pulsadorIncremento = 8; // Pin digital para el pulsador de incremento
  const int pulsadorDecremento = 9; // Pin digital para el pulsador de decremento
  const int tiempoAntirrebote = 10; // Variable para almacenar el tiempo antirrebote
int Digit0;
int Digit1;
  // Variables necesarias para los cálculos internos
  int cuenta = 0;
  int estadoPulsadorIncremento;
  int estadoPulsadorAnteriorIncremento;
  int estadoPulsadorDecremento;
  int estadoPulsadorAnteriorDecremento;
 
  // Función antirrebote
  boolean antirrebote(int pin)  {
    int contador = 0;
    boolean estado;
    boolean estadoAnterior;
       do    {
      estado = digitalRead(pin);
      if(estado != estadoAnterior)   {
        contador = 0;
        estadoAnterior = estado;
      }
      else   {
        contador = contador+ 1;
      }
      delay(1);
    } while(contador < tiempoAntirrebote);
      return estado;
  }
 
   // Función del display: Se reciben 7 variables y se asignan a cada una de las salidas
  void display1 (int a, int b, int c, int d, int e, int f, int g)
  {
    digitalWrite (22,a);  
    digitalWrite (23,b);  
    digitalWrite (24,c);
    digitalWrite (25,d);
    digitalWrite (26,e);
    digitalWrite (27,f);
    digitalWrite (28,g);
  }

  void display2 (int a1, int b1, int c1, int d1, int e1, int f1, int g1)
  {
    digitalWrite (29,a1);  
    digitalWrite (30,b1);  
    digitalWrite (31,c1);
    digitalWrite (32,d1);
    digitalWrite (33,e1);
    digitalWrite (34,f1);
    digitalWrite (35,g1);
  }  
 
  // Función que actualiza el número que aparece en el display de 7 segmentos                
  void actualizarNumero1() {
    switch(Digit1){
      case 0:
        display1 (0,0,0,0,0,0,1); // Número "0"
        break;
      case 1:
        display1 (1,0,0,1,1,1,1); // Número "1"
        break;
      case 2:
        display1 (0,0,1,0,0,1,0); // Número "2"
        break;
      case 3:
        display1 (0,0,0,0,1,1,0); // Número "3"
        break;
      case 4:
        display1 (1,0,0,1,1,0,0); // Número "4"
        break;
      case 5:
        display1 (0,1,0,0,1,0,0); // Número "5"
        break;
      case 6:
        display1 (0,1,0,0,0,0,0); // Número "6"
        break;
      case 7:
        display1 (0,0,0,1,1,1,1); // Número "7"
        break;
      case 8:
        display1 (0,0,0,0,0,0,0); // Número "8"
        break;
      case 9:
        display1 (0,0,0,1,1,0,0); // Número "9"
        break;
    }
  }


/*
void CalculaDigitos( int cuenta)   {
int Digit0 = cuenta %10 ;
int Digit1 = (cuenta % 100) / 10 ;}
*/


 void actualizarNumero2() {
    switch(Digit0){
      case 0:
        display2 (0,0,0,0,0,0,1); // Número "0"
        break;
      case 1:
        display2 (1,0,0,1,1,1,1); // Número "1"
        break;
      case 2:
        display2 (0,0,1,0,0,1,0); // Número "2"
        break;
      case 3:
        display2 (0,0,0,0,1,1,0); // Número "3"
        break;
      case 4:
        display2 (1,0,0,1,1,0,0); // Número "4"
        break;
      case 5:
        display2 (0,1,0,0,1,0,0); // Número "5"
        break;
      case 6:
        display2 (0,1,0,0,0,0,0); // Número "6"
        break;
      case 7:
        display2 (0,0,0,1,1,1,1); // Número "7"
        break;
      case 8:
        display2 (0,0,0,0,0,0,0); // Número "8"
        break;
      case 9:
        display2 (0,0,0,1,1,0,0); // Número "9"
        break;
    }
  }




   
 
  void setup()
  {
pinMode(pin_servo1,OUTPUT);  //declarar el pin como salida
pinMode(pin_servo2,OUTPUT);  //declarar el pin como salida
servo1.attach(pin_servo1, valor_min_servo1, valor_max_servo1); 
servo2.attach(pin_servo2, valor_min_servo2, valor_max_servo2);
servo1.write(90);
servo2.write(90);
    // Asignación de los pines digitales para el display de 7 segmentos como salidas
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(35, OUTPUT); 
    // Asignación de los pines digitales para los pulsadores como entradas
    pinMode(pulsadorIncremento, INPUT);
    pinMode(pulsadorDecremento, INPUT);
  }
 
 
  void loop()  {  
Digit0 = cuenta %10 ;
Digit1 = (cuenta % 100) / 10 ;

      
    // Leemos el estado del pulsador de incremento
    estadoPulsadorIncremento = digitalRead(pulsadorIncremento);    
    // Si hay un cambio en el estado del pulsador de incremento
    if(estadoPulsadorIncremento != estadoPulsadorAnteriorIncremento)
    {
      // y si se ha eliminado ya el rebote del pulsador de incremento
      if(antirrebote(pulsadorIncremento))
      {
        // Se incrementa la cuenta en una unidad
        cuenta++;
        servo1.write(160);
        delay(80);
        servo1.write(90);
        // Si la cuenta es mayor que 99, permanece en 99.
        if(cuenta > 99) {
          cuenta = 99;   }
          
        if ( (cuenta==1) ){
        servo2.write(160);
        delay(100);
        servo2.write(90);}    
      }
    }
    // Actualizamos el estado anterior del pulsador de incremento    
    estadoPulsadorAnteriorIncremento = estadoPulsadorIncremento;
 
    // Leemos el estado del pulsador de decremento
    estadoPulsadorDecremento = digitalRead(pulsadorDecremento);
     // Si hay un cambio en el estado del pulsador de decremento
    if(estadoPulsadorDecremento != estadoPulsadorAnteriorDecremento)
    {
      // y si se ha eliminado ya el rebote del pulsador de decremento
      if(antirrebote(pulsadorDecremento))
      {
        // Se decrementa la cuenta en una unidad
        cuenta--;
        servo1.write(20);
        delay(80);
        servo1.write(90);
        // Si la cuenta es menor que 0, permanece en 0.
           if(cuenta < 0) {
          cuenta = 0; }
          if (cuenta==0){
        servo2.write(30);
        delay(100);
        servo2.write(90);    }
      }
    }
    // Actualizamos el estado anterior del pulsador de decremento      
    estadoPulsadorAnteriorDecremento = estadoPulsadorDecremento;
   
    // Actualizamos el número que aparece en el display de 7 segmentos  
//      CalculaDigitos;
    actualizarNumero1();
    actualizarNumero2();
  }
