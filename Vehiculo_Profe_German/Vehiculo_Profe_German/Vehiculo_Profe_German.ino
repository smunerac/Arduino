   /*
HY-SRF05 / 04              SENSOR ULTRASONICO
Connections:
Vcc -> 5 V
Trig -> pin 13 (digital pin)
Echo -> pin 12 (digital pin)
Out ->
GND -> GND

HC-05                     MODULO BLUETHOOTH
CONEXIONES
STATE >>
RX  >> TX ARDUINO (11, PIN DIGITAL)
TX  >> RX ARDUINO (10, PIN DIGITAL)
GND >> GND
5V  >> 5V
EN  >> 
*/
 
int valorPulsador1 = 0;
int valorPulsador2 = 0;

const unsigned int TRIG_PIN1=23;
const unsigned int ECHO_PIN1=22;
const unsigned int TRIG_PIN2=25;
const unsigned int ECHO_PIN2=24;
const unsigned int BAUD_RATE=57600;
int d1;
int d2;

#include <SoftwareSerial.h>
const int pin1motor1=2;
const int pin2motor1=3;
const int pin1motor2=4;
const int pin2motor2=5;
const int pin1motor3=6;
const int pin2motor3=8;
const int pin1motor4=7;
const int pin2motor4=9;
const int pinadelante=34;
const int pinatras=35;

int pwm1;     //Velocidades de los motores
int pwm2;
int comando;
bool b1;
bool b2;
SoftwareSerial blue(10,11);

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);  
  Serial.begin(BAUD_RATE);

  Serial.begin(57600); 
  blue.begin(9600);  
  pinMode(pin1motor1, OUTPUT);
  pinMode(pin2motor1, OUTPUT);
  pinMode(pin1motor2, OUTPUT);  
  pinMode(pin2motor2, OUTPUT); 
  pinMode(pin1motor3, OUTPUT);
  pinMode(pin2motor3, OUTPUT);
  pinMode(pin1motor4, OUTPUT);  
  pinMode(pin2motor4, OUTPUT); 
  pinMode(pinadelante, INPUT);
  pinMode(pinatras, INPUT); 
}

void loop() {
medir_distancia1();
medir_distancia2();

b1= digitalRead(pinadelante);
b2= digitalRead(pinatras);
       
 // see if there's incoming serial data:
  if (blue.available() > 0) {
    // read the oldest byte in the serial buffer:
    int comando = blue.read();
  
    // action depending on the instruction
    // as well as sending a confirmation back to the app
    switch (comando) {
      case 'Br':
        //lcd.print("Going forward");
        Serial.println("A");
        adelante();
        break;
      case 'A':
        Serial.println("B");
       atras();
        break;
      case 'C':
        Serial.println("C");
        if(pwm1<=250){
          pwm1=pwm1+50;}
        if(pwm2>0){
          pwm2=pwm2-50;}
        break;
      case 'D':
        Serial.println("D");
        if(pwm1>0){
          pwm1=pwm1-50;}
        if(pwm2<250){
          pwm2=pwm2+50;}
        break;
      case 'E':
        Serial.println("E");
        pwm1=0;
        pwm2=0;
        break;
      case 'F':
        Serial.println("F");
        pwm1=255;
        pwm2=255;
        break;
      case 'G':
        Serial.println("G");
        if(pwm1<=250){
          pwm1=pwm1+50;}
        if(pwm2<=250){
          pwm2=pwm2+50;}
        if(pwm1>250){
          pwm1=250;}
        if(pwm2>250){
          pwm2=250;}
        break;
      case 'H':
        Serial.println("H");
       if(pwm1>0){
          pwm1=pwm1-50;}
        if(pwm2>0){
          pwm2=pwm2-50;}
        if(pwm1<0){
          pwm1=0;}
        if(pwm2<0){
          pwm2=0;}
        break;
      case 'I':
        Serial.println("I");
        break;
      case 'J':
        Serial.println("J");
        apagar();
        break;
      default: 
        // if nothing matches, do nothing
        break;
    }
  }
 else{

if (((b1==HIGH) && (b2==HIGH)) || ((b1==LOW) && (b2==LOW))) {
  apagar(); }

  // Encendemos o apagamos el pin del LED según convenga
  if ((b1 == HIGH) ) {
   int valor = analogRead(1); 
    pwm1 = map(valor, 0, 1024, 0,255); //(variable a mapear, valores entrada, valores salida)     
    pwm2 = map(valor, 0, 1024, 0,255); //(variable a mapear, valores entrada, valores salida)
         Serial.println(valor);  
      atras();      }

  // Encendemos o apagamos el pin del LED según convenga
  if (b2 == HIGH)  {
   int valor = analogRead(1); 
    pwm1 = map(valor, 0, 1024, 0,255); //(variable a mapear, valores entrada, valores salida)     
    pwm2 = map(valor, 0, 1024, 0,255); //(variable a mapear, valores entrada, valores salida)
       Serial.println(valor);  
      adelante();      }

delay(120);         
}

}  

void adelante(){
    if ((d1<20) || (d2<20)){
    apagar();}
    else {
   //     Serial.println("adelante");
  digitalWrite(pin1motor1, 0);
  digitalWrite(pin2motor1, pwm1);
  digitalWrite(pin1motor2, 0);
  digitalWrite(pin2motor2, pwm2);
  digitalWrite(pin1motor3, 0);  
  digitalWrite(pin2motor3, pwm1);  
  digitalWrite(pin1motor4, 0);
  digitalWrite(pin2motor4, pwm2);   }  }

void atras(){
     if ((d1<20) || (d2<20)){
     apagar();}
     else {
     //   Serial.println(" atras");
  digitalWrite(pin1motor1, pwm1);
  digitalWrite(pin2motor1, 0);
  digitalWrite(pin1motor2, pwm2);
  digitalWrite(pin2motor2, 0);
  digitalWrite(pin1motor3, pwm1);  
  digitalWrite(pin2motor3, 0);  
  digitalWrite(pin1motor4, pwm2);
  digitalWrite(pin2motor4, 0);   }   }

void apagar(){
    //Serial.println(" apagar");
  digitalWrite(pin1motor1, 0);
  digitalWrite(pin2motor1, 0);
  digitalWrite(pin1motor2, 0);
  digitalWrite(pin2motor2, 0);
  digitalWrite(pin1motor3, 0);  
  digitalWrite(pin2motor3, 0);  
  digitalWrite(pin1motor4, 0);
  digitalWrite(pin2motor4, 0);        }
 
void medir_distancia1(){
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  const unsigned long duration1= pulseIn(ECHO_PIN1, HIGH);
  int distance1= duration1/29/2;     
//  if(duration1==0){
//   Serial.println("Warning: no pulse from sensor");
//   } 
//  else{
//      Serial.print("distance to nearest object:");
//      Serial.println(distance1);
//      Serial.println(" cm");
// }
  d1=distance1;
 delay(100);  } 
 
  
void medir_distancia2(){
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  const unsigned long duration2= pulseIn(ECHO_PIN2, HIGH);
 int distance2= duration2/29/2;     
// if(duration2==0){
//   Serial.println("Warning: no pulse from sensor");
//   } 
//  else{
//      Serial.print("distance to nearest object:");
//      Serial.println(distance2);
//     Serial.println(" cm");
//  }
  d2=distance2;
 delay(100);  
 }