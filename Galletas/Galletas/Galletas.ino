//ENTRADAS
int pin_SN_C=13;            //Entrada Sensor de nivel producto C
int pin_boton_C1 = 12 ;     //Entrada boton C1
int pin_boton_C2 = 11 ;     //Entrada boton C2
int pin_boton_C3 = 10 ;     //Entrada boton C3
//SALIDAS
int pin_motor_C = 9 ;                 //Salida a Motor C
int pin_Agitador = 8 ;                 //Salida a Motor Agitador
int pin_Bomba = 7 ;                   //Salida a Motor Bomba
int pin_Refrigeracion = 6 ;           //Salida a Refrigeracion
//VARIABLES PARA VELOCIDAD DE PWM'S
int v3=200;
//VARIABLES PARA TIEMPOS DEL MOVIMIENTO
int t3=2500;
//VARIABLES PARA LECTURA DE BOTONES
//int boton_A1=0;
//int estado_boton_A1 = 0;
//int estadoant_boton_A1 = 0;
//int boton_A2=0;
//int estado_boton_A2 = 0;
//int estadoant_boton_A2 = 0;
//int boton_A3=0;
//int estado_boton_A3 = 0;
//int estadoant_boton_A3 = 0;
//int boton_B1=0;
//int estado_boton_B1 = 0;
//int estadoant_boton_B1 = 0;
//int boton_B2=0;
//int estado_boton_B2 = 0;
//int estadoant_boton_B2 = 0;
int boton_SN_C=0;
int estado_SN_C = 0;
int estadoant_SN_C = 0;
int boton_C1=0;
int estado_boton_C1 = 0;
int estadoant_boton_C1 = 0;
int boton_C2=0;
int estado_boton_C2 = 0;
int estadoant_boton_C2 = 0;
int boton_C3=0;
int estado_boton_C3 = 0;
int estadoant_boton_C3 = 0;

void setup() {
//ENTRADAS
pinMode(pin_SN_C,INPUT);
pinMode(pin_boton_C1,INPUT);
pinMode(pin_boton_C2,INPUT);
pinMode(pin_boton_C3,INPUT);
//SALIDAS
pinMode(pin_motor_C, OUTPUT);
//pinMode(pin_Agitador,OUTPUT);
//pinMode(pin_Bomba,   OUTPUT);
//pinMode(pin_Refrigeracion, OUTPUT);
}

void loop() {
//LEEMOS LOS BOTONES  

estado_boton_C1 = digitalRead(pin_boton_C1);
delay(50);
if (estado_boton_C1!=estadoant_boton_C1) {    //Si el boton C1 cambia de estado !
  if (estado_boton_C1==1){                    //Lo que pasa cuando esta presionado
digitalWrite(pin_motor_C, v3);
delay(t3);
  }
  else {}   //Cuando no esta presionado 
}
estadoant_boton_C1=estado_boton_C1; 

estado_boton_C2 = digitalRead(pin_boton_C2);
delay(50);
if (estado_boton_C2!=estadoant_boton_C2) {    //Si el boton C2 cambia de estado !
  if (estado_boton_C2==1){                    //Lo que pasa cuando esta presionado
digitalWrite(pin_motor_C, v3);
delay(t3);
  }
  else{}    //Cuando no esta presionado 
}
estadoant_boton_C2=estado_boton_C2; 

estado_boton_C3 = digitalRead(pin_boton_C3);
delay(50);
if (estado_boton_C3!=estadoant_boton_C3) {    //Si el boton C3 cambia de estado !
  if (estado_boton_C3==1){                    //Lo que pasa cuando esta presionado
digitalWrite(pin_motor_C, v3);
delay(t3);
}  
  else {}   //Cuando no esta presionado 
  }

estadoant_boton_C3=estado_boton_C3; 
}

//LEEMOS EL SENSOR DE NIVEL DEL PRODUCTO C

estado_SN_C = digitalRead(pin_SN_C);
delay(50);
if (estado_SN_C!=estadoant_SN_C) {    //Si el sensor de nivel A cambia de estado !
  if (estado_SN_C==1){                    //Lo que pasa cuando esta presionado     
delay(t3);
  }
  else {}   //Cuando no esta presionado 
}
estadoant_SN_C=estado_SN_C; 

//CONDICIONES DE OPERACION PARA EL PRODUCTO C
if ((estado_SN_C==HIGH && estado_boton_C1==HIGH) && (estado_boton_C2==LOW && estado_boton_C3==LOW)){
digitalWrite(pin_motor_C, HIGH);
delay(t3);
}

if ((estado_SN_C==HIGH && estado_boton_C1==LOW) && (estado_boton_C2==HIGH && estado_boton_C3==LOW)){
digitalWrite(pin_motor_C, HIGH);
delay(t3);
}

if ((estado_SN_C==HIGH && estado_boton_C1==LOW) && (estado_boton_C2==LOW && estado_boton_C3==HIGH)){
digitalWrite(pin_motor_C, HIGH);
delay(t3);
}


}
