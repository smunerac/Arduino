/ * Este código funciona con MLX90614 ( GY906 ) y la pantalla LCD ic
 
* Mide la temperatura ambiente y de los objetos en grados Celsius y la muestra en la pantalla
 
* Visite www.surtrtech.com para obtener más detalles
 
* /
 
#include <LiquidCrystal_I2C.h> #include <Wire.h> #include <Adafruit_MLX90614.h> #define I2C_ADDR 0x27 // Dirección I2C, debe usar el código para escanear la dirección primero (0x27) aquí #define BACKLIGHT_PIN 3 // Declarando Pines LCD #define En_pin 2 #define Rw_pin 1 #define Rs_pin 0 #define D4_pin 4 #define D5_pin 5 #define D6_pin 6 #define D7_pin 7 LiquidCrystal_I2C lcd















( I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin ) ; 
Adafruit_MLX90614 mlx  = Adafruit_MLX90614 () ; 
configuración vacía () {   mlx.begin () ;   lcd.begin ( 16 , 2 ) ;   lcd.setBacklightPin ( BACKLIGHT_PIN, POSITIVO ) ;   lcd.setBacklight ( ALTO ) ; // Iluminación de fondo
   lcd.home () ; } void loop () { lcd.setCursor ( 0 , 0

 
  







 
) ; 
lcd.print ( "Ambiente" ) ; 
lcd.print ( mlx.readAmbientTempC ()) ; 
lcd.print ( "C" ) ; 
lcd.setCursor ( 0 , 1 ) ; lcd.print ( "Destino" ) ; lcd.print ( mlx.readObjectTempC ()) ; lcd.print ( "C" ) ; retraso ( 1000 ) ; }
 







