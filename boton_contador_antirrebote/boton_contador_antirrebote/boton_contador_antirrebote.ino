//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
const int boton = 12; //Le ponemos nombre al pin 2
const int led = 2; //Le ponemos nombre al pin 13
int contador = 0;  //Variable para guardar la cuenta de pulsaciones
int estadoAnteriorBoton = 0; //Declaramos e inicializamos la variable
int valorBoton = 0; //Declaramos e inicializamos la variable
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600);   //Inicia comunicación serie
  pinMode(boton,INPUT);     //Configura el pin 2 como una entrada, pulsador
  pinMode(led,OUTPUT);   //Configura el pin 13 como una salida, LED
}

//------------------------------------
//Funcion ciclica
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este alimentado el Arduino

valorBoton=digitalRead(boton); //Leemos el estado del pulsador
delay(100);
if(valorBoton!=estadoAnteriorBoton){ //Si hay un cambio de estado, entramos en el if

  if(valorBoton==1){
    contador++; //Aumentamos en una unidad la cuenta
    Serial.println(contador); //Imprime el valor por consola
    digitalWrite(led,HIGH); //Encendemos el led
  }
if(valorBoton==0){
    digitalWrite(led,LOW); //Apagamos el led
  }
}
estadoAnteriorBoton=valorBoton; //guardamos el estado actual del pulsador para la siguiente iteración
}
