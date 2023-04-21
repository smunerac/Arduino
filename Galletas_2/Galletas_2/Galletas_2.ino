//ENTRADAS
int pin_SN_C=12;          //Entrada sensor de nivel materia prima C
int pin_SN_T=11;          //Entrada sensor de nivel Tanque
int pin_S_T=10;           //Entrada sensor de Temperatura
int pin_boton_C1 = 9 ;    //Entrada Pulsador C1
int pin_boton_C2 = 8 ;    //Entrada Pulsador C2
int pin_boton_C3 = 7 ;    //Entrada Pulsador C3
//SALIDAS
int pin_motor_C = 6 ;                  //Salida a Motor materia prima C
int pin_Agitador = 5 ;                 //Salida a Motor Agitador
int pin_Bomba = 4 ;                    //Salida a Motor Bomba
int pin_Refrigeracion = 3 ;            //Salida a Refrigeracion
//VARIABLES PARA TIEMPOS DEL MOVIMIENTO
int t1=2000;
int t2=2500;
int t3=3000;
//VARIABLES PARA LECTURA DE BOTONES
int boton_C1=0;
int estado_boton_C1 = 0;
int estadoant_boton_C1 = 0;
int boton_C2=0;
int estado_boton_C2 = 0;
int estadoant_boton_C2 = 0;
int boton_C3=0;
int estado_boton_C3 = 0;
int estadoant_boton_C3 = 0;
//VARIABLES PARA LECTURA DE SENSORES
int SN_C=0;
int estado_SN_C = 0;
int estadoant_SN_C = 0;
int SN_T=0;
int estado_SN_T = 0;
int estadoant_SN_T = 0;
int S_T=0;
int estado_S_T = 0;
int estadoant_S_T = 0;

void setup() {
//ENTRADAS
pinMode(pin_boton_C1,INPUT);
pinMode(pin_boton_C2,INPUT);
pinMode(pin_boton_C3,INPUT);
pinMode(pin_SN_C,INPUT);
pinMode(pin_SN_T,INPUT);
pinMode(pin_S_T,INPUT);
//SALIDAS
pinMode(pin_motor_C, OUTPUT);
pinMode(pin_Agitador,OUTPUT);
pinMode(pin_Bomba,   OUTPUT);
pinMode(pin_Refrigeracion, OUTPUT);
}

void loop() {
//LEEMOS LOS PULSADORES  
estado_boton_C1 = digitalRead(pin_boton_C1);
delay(50);
if (estado_boton_C1!=estadoant_boton_C1) {    //Si el boton C1 cambia de estado !
  if (estado_boton_C1==1){                
delay(t3);
  }
  else {}  
}
estadoant_boton_C1=estado_boton_C1; 

estado_boton_C2 = digitalRead(pin_boton_C2);
delay(50);
if (estado_boton_C2!=estadoant_boton_C2) {    //Si el boton C2 cambia de estado !
  if (estado_boton_C2==1){                    
delay(t3);
  }
  else{}   
}
estadoant_boton_C2=estado_boton_C2; 

estado_boton_C3 = digitalRead(pin_boton_C3);
delay(50);
if (estado_boton_C3!=estadoant_boton_C3) {    //Si el boton C3 cambia de estado !
  if (estado_boton_C3==1){                
delay(t3);
}  
  else {}  
  }
estadoant_boton_C3=estado_boton_C3; 

//LEEMOS LOS SENSORES 

estado_SN_T = digitalRead(pin_SN_T);
delay(50);
if (estado_SN_T!=estadoant_SN_T) {    //Si el sensor de nivel A cambia de estado !
  if (estado_SN_T==1){                  
delay(t1);
  }
  else {}  
}
estadoant_SN_T=estado_SN_T;

estado_S_T = digitalRead(pin_S_T);
delay(50);
if (estado_S_T!=estadoant_S_T) {    //Si el sensor de nivel A cambia de estado !
  if (estado_S_T==1){                  
delay(t1);
  }
  else {}  
}
estadoant_S_T=estado_S_T;

//CONDICIONALES DE OPERACION DE ACUERDO A LAS POSIBLES COMBINACIONES SELECCIONADAS

if ((estado_SN_C==HIGH && estado_boton_C1==HIGH) && (estado_boton_C2==LOW && estado_boton_C3==LOW)){
digitalWrite(pin_motor_C, HIGH);
delay(t1);
digitalWrite(pin_motor_C, LOW);
}

if ((estado_SN_C==HIGH && estado_boton_C1==LOW) && (estado_boton_C2==HIGH && estado_boton_C3==LOW)){
digitalWrite(pin_motor_C, HIGH);
delay(t2);
digitalWrite(pin_motor_C, LOW);
}

if ((estado_SN_C==HIGH && estado_boton_C1==LOW) && (estado_boton_C2==LOW && estado_boton_C3==HIGH)){
digitalWrite(pin_motor_C, HIGH);
delay(t3);
digitalWrite(pin_motor_C, LOW);
}

//CONDICIONALES DE OPERACION PARA EL SISTEMA DE AGITACION, REFRIGERACION Y BOMBA

if(estado_SN_T==HIGH && pin_motor_C==LOW){    //Si tenemos nivel en el tanque y el motor C ha terminado de dispensar
digitalWrite(pin_Agitador,HIGH);              //Encendemos el sistema de Agitacion
delay(4000);
digitalWrite(pin_Agitador,LOW);               //Apagamos el sistema de Agitacion
}

if ((estado_SN_T==HIGH && estado_S_T==HIGH) && pin_Agitador==LOW ){   //Si tenemos nivel en el tanque, señal de Temperatura y hemos terminado de agitar
digitalWrite(pin_Refrigeracion, HIGH);        //Encendemos el sistema de Refrigeracion
delay(2000);
digitalWrite(pin_Refrigeracion, LOW);         //Apagamos el sistema de refrigeracion
}

if (estado_SN_T==HIGH && estado_S_T==LOW){
digitalWrite(pin_Bomba, HIGH);      //Encendemos el sistema de Bomba
delay(1000);
digitalWrite(pin_Bomba, LOW);       //Apagamos el sistema de bomba
}


}


  

