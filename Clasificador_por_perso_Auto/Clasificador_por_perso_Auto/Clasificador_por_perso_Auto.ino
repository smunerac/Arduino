/*

*/

//Pin de lectura del pesaje
int pinpesado=A1;

//Pines de control de las cintas transportadoras
const int pinmotorcinta0=2;
const int pinmotorcinta1=3;
const int pinmotorcinta2=4;
const int pinmotorcinta3=5;

//Pines de control de cilindros
const int pin1motorcilindroa=6;
const int pin2motorcilindroa=7;

const int pin1motorcilindrob=8;
const int pin2motorcilindrob=9;

const int pin1motorcilindroc=10;
const int pin2motorcilindroc=11;

//Pines de lectura de finales de carrera de cilindros
const int pinfcicilindroa=22;
const int pinfcfcilindroa=23;

const int pinfcicilindrob=24;
const int pinfcfcilindrob=25;

const int pinfcicilindroc=26;
const int pinfcfcilindroc=27;

//Pines de lectura de finales de carrera de las cintas transportadoras
const int pinfcicinta0=28;
const int pinfcfcinta0=29;

const int pinfcicinta1=30;
const int pinfcfcinta1=31;

const int pinfcicinta2=32;
const int pinfcfcinta2=33;

const int pinfcicinta3=34;
const int pinfcfcinta3=35;


void setup() {
  
//Pines de control de cintas como salidas
  pinMode(pinmotorcinta0, OUTPUT);
  pinMode(pinmotorcinta1, OUTPUT);
  pinMode(pinmotorcinta2, OUTPUT); 
  pinMode(pinmotorcinta3, OUTPUT);
  
//Pines de motores de cilindros como salidas
  pinMode(pin1motorcilindroa, OUTPUT);  
  pinMode(pin2motorcilindroa, OUTPUT); 
  
  pinMode(pin1motorcilindrob, OUTPUT);  
  pinMode(pin2motorcilindrob, OUTPUT);

  pinMode(pin1motorcilindroc, OUTPUT);  
  pinMode(pin2motorcilindroc, OUTPUT);
  
//Pines de finales de carrera de cilindros como entradas  
  pinMode(pinfcicilindroa, INPUT);  
  pinMode(pinfcfcilindroa, INPUT);
  
  pinMode(pinfcicilindrob, INPUT);  
  pinMode(pinfcfcilindrob, INPUT);
  
  pinMode(pinfcicilindroc, INPUT);  
  pinMode(pinfcfcilindroc, INPUT);
  
//Pines de finales de carrera de cintas transportadoras como entradas  
  pinMode(pinfcicinta0, INPUT);  
  pinMode(pinfcfcinta0, INPUT);
  
  pinMode(pinfcicinta1, INPUT);  
  pinMode(pinfcfcinta1, INPUT);  
  
  pinMode(pinfcicinta2, INPUT);  
  pinMode(pinfcfcinta2, INPUT);  
  
  pinMode(pinfcicinta3, INPUT);  
  pinMode(pinfcfcinta3, INPUT); 

}

void loop() {
//Leemos el pin de pesaje  
Peso = analogRead(pinpesado);

//Leemos el estado de los finales de carrera de los cilindros
estadofcicilindroa = digitalRead(pinfcicilindroa);
estadofcicilindroa = digitalRead(pinfcfcilindroa);

estadofcicilindrob = digitalRead(pinfcicilindrob);
estadofcicilindrob = digitalRead(pinfcfcilindrob);

estadofcicilindroc = digitalRead(pinfcicilindroc);
estadofcicilindroc = digitalRead(pinfcfcilindroc);

//Leemos el estado de los finales de carrera de las cintas transportadoras
estadofcicinta0 = digitalRead(pinfcicinta0);
estadofcicinta0 = digitalRead(pinfcicinta0);

estadofcicinta1 = digitalRead(pinfcicinta1);
estadofcicinta1 = digitalRead(pinfcicinta1);

estadofcicinta2 = digitalRead(pinfcicinta2);
estadofcicinta2 = digitalRead(pinfcicinta2);

estadofcicinta3 = digitalRead(pinfcicinta3);
estadofcicinta3 = digitalRead(pinfcicinta3);



 
}



//Funciones de control de los cilindros
void extraercilindroa(){
digitalWrite(pin1motorcilindroa,HIGH); 
digitalWrite(pin2motorcilindroa,LOW);}

void retraercilindroa(){
digitalWrite(pin1motorcilindroa,LOW); 
digitalWrite(pin2motorcilindroa,HIGH);}

void apagarcilindroa(){
digitalWrite(pin1motorcilindroa,LOW); 
digitalWrite(pin2motorcilindroa,LOW);}

void extraercilindrob(){
digitalWrite(pin1motorcilindrob,HIGH); 
digitalWrite(pin2motorcilindrob,LOW);}

void retraercilindrob(){
digitalWrite(pin1motorcilindrob,LOW); 
digitalWrite(pin2motorcilindrob,HIGH);}

void apagarcilindrob(){
digitalWrite(pin1motorcilindrob,LOW); 
digitalWrite(pin2motorcilindrob,LOW);}

void extraercilindroc(){
digitalWrite(pin1motorcilindroc,HIGH); 
digitalWrite(pin2motorcilindroc,LOW);}

void retraercilindroc(){
digitalWrite(pin1motorcilindroc,LOW); 
digitalWrite(pin2motorcilindroc,HIGH);}

void apagarcilindroc(){
digitalWrite(pin1motorcilindroa,LOW); 
digitalWrite(pin2motorcilindroa,LOW);}

//Funciones de control de las cintas transportadoras
void encendercinta0(){
digitalWrite(pinmotorcinta0,HIGH);} 

void apagarcinta0(){
digitalWrite(pinmotorcinta0,LOW);} 

void encendercinta1(){
digitalWrite(pinmotorcinta1,HIGH);} 

void apagarcinta1(){
digitalWrite(pinmotorcinta1,LOW);} 

void encendercinta2(){
digitalWrite(pinmotorcinta2,HIGH);} 

void apagarcinta2(){
digitalWrite(pinmotorcinta2,LOW);} 

void encendercinta3(){
digitalWrite(pinmotorcinta3,HIGH);} 

void apagarcinta3(){
digitalWrite(pinmotorcinta3,LOW);} 






















