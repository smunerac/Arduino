#include "LedControlMS.h"
#define MAX 1       // Cuantas matrices se usarán
#include <Keypad.h>
 
const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { A0, A1, A2, A3 };
const byte columnPins[columsCount] = { A4, A5, 1, 2 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);




LedControl led=LedControl(8,10,9, MAX);  // Creamos una instancia de LedControl

void setup()   {
  
      for (int x=0; x< MAX ; x++)
        {
           led.shutdown(x,false);    // Activar las matrices
           led.setIntensity(x,8);    // Se ajusta el brillo de los LED´s como se desee (0-15)
           led.clearDisplay(x);      // Se borra todo
        }
   }

void loop()   {
  char key = keypad.getKey();
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
        
  switch (key) {
  case "1":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "2":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "3":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "4":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "5":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "6":
         led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "7":
         led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "8":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "9":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "0":
         led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "#":
         led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "*":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "A":
        led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "B":
          led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "#C":
          led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break;
  
  case "D":
          led.writeString(0,key);  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
  break; 
    
  default:
    // statements
    break;
}
        
   }
