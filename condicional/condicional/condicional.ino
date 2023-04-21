// 

int estado = 0;
int salida = 0;
int estadoanterior=0;


void setup() {
 pinMode(8, INPUT);    // declaramos el pin 8 como una entrada
 pinMode(4, OUTPUT);    //declaramos el pin 4 como una salida
 
}

void loop() {
  estado = digitalRead(8);       //leer el estado del boton
    if(estado == HIGH) {
     digitalWrite(4, HIGH);      //encendemos el led
    }
    else {
    digitalWrite(4, LOW);        //apagamos el led
    }  
     
}

