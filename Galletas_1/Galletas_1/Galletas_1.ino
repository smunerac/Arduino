//ENTRADAS
int pin_boton_A1 = 10 ;    //Entrada Pulsador A1
int pin_boton_A2 = 9 ;     //Entrada Pulsador A2
int pin_boton_A3 = 8 ;     //Entrada Pulsador A3
int pin_boton_B1 = 7 ;     //Entrada Pulsador B1
int pin_boton_B2 = 6 ;     //Entrada Pulsador B2
int pin_boton_B3 = 5 ;     //Entrada Pulsador B3
int pin_SN_A=4;            //Entrada Sensor de Nivel materia prima A
int pin_SN_B=3;            //Entrada Sensor de Nivel materia prima B
//SALIDAS
int pin_motor_A = 11 ;                  //Salida a Motor materia prima A
int pin_motor_B = 12 ;                  //Salida a Motor materia prima B
//VARIABLES PARA TIEMPOS DEL MOVIMIENTO
int t1=2000;                    //Tiempo de trabajo 1
int t2=2500;                    //Tiempo de trabajo 2                    
int t3=3000;                    //Tiempo de trabajo 3
//VARIABLES PARA LECTURA DE BOTONES
int boton_A1=0;
int estado_boton_A1 = 0;
int estadoant_boton_A1 = 0;
int boton_A2=0;
int estado_boton_A2 = 0;
int estadoant_boton_A2 = 0;
int boton_A3=0;
int estado_boton_A3 = 0;
int estadoant_boton_A3 = 0;
int boton_B1=0;
int estado_boton_B1 = 0;
int estadoant_boton_B1 = 0;
int boton_B2=0;
int estado_boton_B2 = 0;
int estadoant_boton_B2 = 0;
int boton_B3=0;
int estado_boton_B3 = 0;
int estadoant_boton_B3 = 0;
//VARIABLES PARA LECTURA DE SENSORES DE NIVEL
int SN_A=0;
int estado_SN_A = 0;
int estadoant_SN_A = 0;
int SN_B=0;
int estado_SN_B = 0;
int estadoant_SN_B = 0;
void setup() {
//ENTRADAS
pinMode(pin_boton_A1,INPUT);
pinMode(pin_boton_A2,INPUT);
pinMode(pin_boton_A3,INPUT);
pinMode(pin_boton_B1,INPUT);
pinMode(pin_boton_B2,INPUT);
pinMode(pin_boton_B3,INPUT);
pinMode(pin_SN_A,INPUT);
pinMode(pin_SN_B,INPUT);
//SALIDAS
pinMode(pin_motor_A, OUTPUT);
pinMode(pin_motor_B, OUTPUT);
}

void loop() {
//LEEMOS LOS BOTONES  
estado_boton_A1 = digitalRead(pin_boton_A1);
delay(50);
if (estado_boton_A1!=estadoant_boton_A1) {    //Si el boton A1 cambia de estado !
  if (estado_boton_A1==1){               
delay(t1);
  }
  else {}     
}
estadoant_boton_A1=estado_boton_A1; 

estado_boton_A2 = digitalRead(pin_boton_A2);
delay(50);
if (estado_boton_A2!=estadoant_boton_A2) {    //Si el boton A2 cambia de estado !
  if (estado_boton_A2==1){              
delay(t1);
  }
  else{}  
} 
estadoant_boton_A2=estado_boton_A2; 

estado_boton_A3 = digitalRead(pin_boton_A3);
delay(50);
if (estado_boton_A3!=estadoant_boton_A3) {    //Si el boton A3 cambia de estado !
  if (estado_boton_A3==1){                  
delay(t1);
}  
  else {}   
  }
 estadoant_boton_A3=estado_boton_A3; 

estado_boton_B1 = digitalRead(pin_boton_B1);
delay(50);
if (estado_boton_B1!=estadoant_boton_B1) {    //Si el boton B1 cambia de estado !
  if (estado_boton_B1==1){                    
delay(t2);
}  
  else {}  
  }
 estadoant_boton_B1=estado_boton_B1;

estado_boton_B2 = digitalRead(pin_boton_B2);
delay(50);
if (estado_boton_B2!=estadoant_boton_B2) {    //Si el boton B2 cambia de estado !
  if (estado_boton_B2==1){                    
delay(t2);
}  
  else {}   
  }
 estadoant_boton_B2=estado_boton_B2;

estado_boton_B3 = digitalRead(pin_boton_B3);
delay(50);
if (estado_boton_B3!=estadoant_boton_B3) {     //Si el boton B3 cambia de estado !
  if (estado_boton_B3==1){                    
delay(t2);
}  
  else {}  
  }
 estadoant_boton_B3=estado_boton_B3;

//LEEMOS LOS SENSORES DE NIVEL DE PRODUCTO

estado_SN_A = digitalRead(pin_SN_A);
delay(50);
if (estado_SN_A!=estadoant_SN_A) {    //Si el sensor de nivel A cambia de estado !
  if (estado_SN_A==1){                  
delay(t1);
  }
  else {}  
}
estadoant_SN_A=estado_SN_A; 

estado_SN_B = digitalRead(pin_SN_B);
delay(50);
if (estado_SN_B!=estadoant_SN_B) {    //Si el sensor de nivel B cambia de estado !
  if (estado_SN_B==1){             
SN_B=1;           
delay(t2);
  }
  else{
SN_B=0;    
    }   
}
estadoant_SN_B=estado_SN_B; 

//CONDICIONALES DE OPERACION DE ACUERDO A LAS POSIBLES COMBINACIONES SELECCIONADAS

if ((estado_SN_A==HIGH && estado_boton_A1==HIGH) && (estado_boton_A2==LOW && estado_boton_A3==LOW)){
digitalWrite(pin_motor_A, HIGH);
delay(t1);
}

if ((estado_SN_A==HIGH && estado_boton_A1==LOW) && (estado_boton_A2==HIGH && estado_boton_A3==LOW)){
digitalWrite(pin_motor_A, HIGH);
delay(t2);
}

if ((estado_SN_A==HIGH && estado_boton_A1==LOW) && (estado_boton_A2==LOW && estado_boton_A3==HIGH)){
digitalWrite(pin_motor_A, HIGH);
delay(t3);
}


if ((estado_SN_B==HIGH && estado_boton_B1==HIGH) && (estado_boton_B2==LOW && estado_boton_B3==LOW)){
digitalWrite(pin_motor_B, HIGH);
delay(t1);
}

if ((estado_SN_B==HIGH && estado_boton_B1==LOW) && (estado_boton_B2==HIGH && estado_boton_B3==LOW)){
digitalWrite(pin_motor_B, HIGH);
delay(t2);
}

if ((estado_SN_B==HIGH && estado_boton_B1==LOW) && (estado_boton_B2==LOW && estado_boton_B3==HIGH)){
digitalWrite(pin_motor_B, HIGH);
delay(t3);
}


}

