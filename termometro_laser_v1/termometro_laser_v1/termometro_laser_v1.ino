https://www.prometec.net/midiendo-temperatura-sin-contacto/

Para el programa vamos a empezar con un par de includes, para el I2C y el sensor:

#include <Wire.h>
#include <Adafruit_MLX90614.h>
Después creamos una instancia de un objeto por cada sensor:

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Y ya podemos ir hasta el setup()

void setup()
{
   Serial.begin(9600);
   mlx.begin();
}
Donde incializamos el objeto con la segunda línea. Y en el loop utilizamos las dos instrucciones básicas de este sensor para leer la temperatura ambiente, y la del objeto al que apuntamos:

void loop() 
  {
     Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());  
     Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
     Serial.println();  
     delay(1000);
  }
Y eso es todo. Resulta frustrantemente sencillo. Si ejecutáis el programa obtendréis medidas variables en la puerta serie según adonde vayáis apuntando el sensor:
