#include "LedControlMS.h"
#define MAX 1       // Cuantas matrices se usarán

LedControl led=LedControl(8,10,9, MAX);  // Creamos una instancia de LedControl

void setup()
   {
      for (int x=0; x< MAX ; x++)
        {
           led.shutdown(x,false);    // Activar las matrices
           led.setIntensity(x,8);    // Se ajusta el brillo de los LED´s como se desee (0-15)
           led.clearDisplay(x);      // Se borra todo
        }
   }

void loop()
   {
        led.writeString(0," HeTPro ");  //texto que se mostrara en la matriz 
        delay(1000);  //se espera 1 segundo
   }