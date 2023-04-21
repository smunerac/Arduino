/*
int estado = 0 ;              //declarar variable de enteros
const int led=3 ;              //declarar constante de numeros enteros

void setup () {  
pinMode(4,OUTPUT);    //declarar el pin como salida,(0v-5v) posibles:2,4,7,8,12,13
pinMode(8,INPUT);     //declarar el pin como entrada,(0v-5v) posibles:2,4,7,8,12,13
pinMode(3, OUTPUT);   //declarar el pin como salida variable, posibles(PWM):3,5,6,9,10,11
}

void loop () {
if (estado == HIGH) {         ////comparar si la variable esta en estado HIGH o LOW, entonces realizar { }
}  
if ((estado == HIGH) && (estadoanterior == LOW)) {    //cumplir doble condicional, y ejecutar {}
}
else {              sino, ejecutar { }
}
for (brillo = 0 ; brillo<256; brillo++) {    //para brillo desde 0 hasta 256, aumentando de uno en uno, ejecute { }
}
for (brillo = 255 ; brillo>=0; brillo--) {   //para brillo desde 255 hasta 0, disminuyendo de uno en uno, ejecute { }
}
digitalWrite(4,HIGH);        //darle estado HIGH al pin 4 (salida)
digitalWrite(4,LOW);         //darle estado LOW al pin 4   (salida)
estado = digitalRead(8);     // leer el estado del pin(HIGH o LOW), y almacenar en variable "estado", posibles: 2,4,7,8,12,13
brillo = analogRead(3) ;     //leer el valor del pin 3 analogico, variable(0-1024) y almacenarlo en la variable, posibles (A0-A5)
analogWrite(3, brillo);      //llevar el valor de "brillo" a la salida variable PWM (0-256) del pin 3, posibles(PWM):3,5,6,9,10,11
delay(1000);                 //esperar 1000 milisegundos, entre 10 y 50 para antirrebotes de botones
A0-A5   solo para entradas de "voltajes", analogicas, (0-1024), NUNCA SALIDAS
}
 

const int d0=13;     //diodo 0 conectado al pin 13
const int d1=12;     //diodo 1 conectado al pin 12
const int d2=11;     //diodo 2 conectado al pin 11
const int d3=10;     //diodo 3 conectado al pin 10
const int rs=9;      //puerto rs conectado al pin 9
const int wr=8;      //puerto wr conectado al pin 8
const int rd=7;      //puerto rd conectado al pin 7

int D0=0;
int D1=0;
int D2=0;
int D3=0;
int RS=0;
int WR=0;
int RD=0;

void setup () {
pinMode(d0, INPUT) ;    //declarar el pin d0 como entrada
pinMode(d1, INPUT) ;    //declarar el pin d1 como entrada
pinMode(d2, INPUT) ;    //declarar el pin d2 como entrada
pinMode(d3, INPUT) ;    //declarar el pin d3 como entrada
pinMode(rs, INPUT) ;    //declarar el pin rs como entrada
pinMode(wr, INPUT) ;    //declarar el pin wr como entrada
pinMode(rd, INPUT) ;    //declarar el pin rd como entrada
Serial.begin(9600);	// abre el puerto serie y establece la velocidad en 9600 bps
// READ STATUS REGISTER
leer(); //1
RS=HIGH;
WR=HIGH;
RD=LOW;
escribir();  //2
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//3
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//4
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=HIGH;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//5
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
leer();//6
RS=HIGH;
WR=HIGH;
RD=LOW;
}
void escribir(){
pinMode(d0, OUTPUT) ;    //declarar el pin d0 como entrada
pinMode(d1, OUTPUT) ;    //declarar el pin d1 como entrada
pinMode(d2, OUTPUT) ;    //declarar el pin d2 como entrada
pinMode(d3, OUTPUT) ;    //declarar el pin d3 como entrada
pinMode(rs, OUTPUT) ;    //declarar el pin rs como entrada
pinMode(wr, OUTPUT) ;    //declarar el pin wr como entrada
pinMode(rd, OUTPUT) ;  
}
void leer() {
 pinMode(d0, INPUT) ;    //declarar el pin d0 como entrada
pinMode(d1, INPUT) ;    //declarar el pin d1 como entrada
pinMode(d2, INPUT) ;    //declarar el pin d2 como entrada
pinMode(d3, INPUT) ;    //declarar el pin d3 como entrada
pinMode(rs, OUTPUT) ;    //declarar el pin rs como entrada
pinMode(wr, OUTPUT) ;    //declarar el pin wr como entrada
pinMode(rd, OUTPUT) ;  
}



void loop () {

D0 = digitalRead(d0);
D1 = digitalRead(d1);
D2 = digitalRead(d2);
D3 = digitalRead(d3);
RS = digitalRead(rs);
WR = digitalRead(wr);
RD = digitalRead(rd);  
  
if (D3==LOW&&D2==LOW&&D1==LOW&&D0==HIGH){ 
Serial.println("1") ;
}  
if (D3==LOW&&D2==LOW&&D1==HIGH&&D0==LOW){ 
Serial.println("2") ;
} 
if (D3==LOW&&D2==LOW&&D1==HIGH&&D0==HIGH){ 
Serial.println("3") ;
} 
if (D3==LOW&&D2==HIGH&&D1==LOW&&D0==LOW){ 
Serial.println("4") ;
} 
if (D3==LOW&&D2==HIGH&&D1==LOW&&D0==HIGH){ 
Serial.println("5") ;
}
if (D3==LOW&&D2==HIGH&&D1==HIGH&&D0==LOW){  
Serial.println("6") ;
} 
if (D3==LOW&&D2==HIGH&&D1==HIGH&&D0==HIGH){ 
Serial.println("7") ;
} 
if (D3==HIGH&&D2==LOW&&D1==LOW&&D0==LOW){ 
Serial.println("8") ;
} 
if (D3==HIGH&&D2==LOW&&D1==LOW&&D0==HIGH){ 
Serial.println("9") ;
} 
if (D3==HIGH&&D2==LOW&&D1==HIGH&&D0==LOW){ 
Serial.println("0") ;
} 
if (D3==HIGH&&D2==LOW&&D1==HIGH&&D0==HIGH){  
Serial.println("*") ;
}   
if (D3==HIGH&&D2==HIGH&&D1==LOW&&D0==LOW){  
Serial.println("#") ;
} 
if (D3==HIGH&&D2==HIGH&&D1==LOW&&D0==HIGH){ 
Serial.println("A") ;
} 
if (D3==HIGH&&D2==HIGH&&D1==HIGH&&D0==LOW){  
Serial.println("B") ;
} 
iif (D3==HIGH&&D2==HIGH&&D1==HIGH&&D0==HIGH){  
Serial.println("C") ;
} 
if (D3==LOW&&D2==LOW&&D1==LOW&&D0==LOW){ 
Serial.println("D") ;
} 


}


*/
const int dy1=250;   // delay 1
const int dy2=600;   // delay 2

const int d0=13;     //diodo 0 conectado al pin 13
const int d1=12;     //diodo 1 conectado al pin 12
const int d2=11;     //diodo 2 conectado al pin 11
const int d3=10;     //diodo 3 conectado al pin 10
const int rs=9;      //puerto rs conectado al pin 9
const int wr=8;      //puerto wr conectado al pin 8
const int rd=7;      //puerto rd conectado al pin 7

int D0=0;
int D1=0;
int D2=0;
int D3=0;
int RS=0;
int WR=0;
int RD=0;

void inicializarmt(){        // READ STATUS REGISTER
leer(); //1
RS=HIGH;
WR=HIGH;
RD=LOW;
escribir();  //2
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//3
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//4
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=HIGH;
D2=LOW;
D1=LOW;
D0=LOW;
escribir();//5
RS=HIGH;
WR=LOW;
RD=HIGH;
D3=LOW;
D2=LOW;
D1=LOW;
D0=LOW;
leer();//6
RS=HIGH;
WR=HIGH;
RD=LOW;
}

void leer() {
 pinMode(d0, INPUT) ;    //declarar el pin d0 como entrada
pinMode(d1, INPUT) ;    //declarar el pin d1 como entrada
pinMode(d2, INPUT) ;    //declarar el pin d2 como entrada
pinMode(d3, INPUT) ;    //declarar el pin d3 como entrada
pinMode(rs, OUTPUT) ;    //declarar el pin rs como entrada
pinMode(wr, OUTPUT) ;    //declarar el pin wr como entrada
pinMode(rd, OUTPUT) ;  
}

void setup () {
pinMode(d0, INPUT) ;    //declarar el pin d0 como entrada
pinMode(d1, INPUT) ;    //declarar el pin d1 como entrada
pinMode(d2, INPUT) ;    //declarar el pin d2 como entrada
pinMode(d3, INPUT) ;    //declarar el pin d3 como entrada
pinMode(rs, OUTPUT) ;    //declarar el pin rs como entrada
pinMode(wr, OUTPUT) ;    //declarar el pin wr como entrada
pinMode(rd, OUTPUT) ;    //declarar el pin rd como entrada
Serial.begin(9600);	// abre el puerto serie y establece la velocidad en 9600 bps

}

void loop(){
  
D0 = digitalRead(d0);
D1 = digitalRead(d1);
D2 = digitalRead(d2);
D3 = digitalRead(d3);
RS = digitalRead(rs);
WR = digitalRead(wr);
RD = digitalRead(rd);  
  
if (D3==LOW||D2==LOW||D1==LOW||D0==HIGH){ 
Serial.println("1") ;
delay(dy1);
}  
if (D3==LOW||D2==LOW||D1==HIGH||D0==LOW){ 
Serial.println("2") ;
delay(dy1);
} 
if (D3==LOW||D2==LOW||D1==HIGH||D0==HIGH){ 
Serial.println("3") ;
delay(dy1);
} 
if (D3==LOW||D2==HIGH||D1==LOW||D0==LOW){ 
Serial.println("4") ;
delay(dy1);
} 
if (D3==LOW||D2==HIGH||D1==LOW||D0==HIGH){ 
Serial.println("5") ;
delay(dy1);
}
if (D3==LOW||D2==HIGH||D1==HIGH||D0==LOW){  
Serial.println("6") ;
delay(dy1);
} 
if (D3==LOW||D2==HIGH||D1==HIGH||D0==HIGH){ 
Serial.println("7") ;
delay(dy1);
} 
if (D3==HIGH||D2==LOW||D1==LOW||D0==LOW){ 
Serial.println("8") ;
delay(dy1);
} 
if (D3==HIGH||D2==LOW||D1==LOW||D0==HIGH){ 
Serial.println("9") ;
delay(dy1);
} 
if (D3==HIGH||D2==LOW||D1==HIGH||D0==LOW){ 
Serial.println("0") ;
delay(dy1);
} 
if (D3==HIGH||D2==LOW||D1==HIGH||D0==HIGH){  
Serial.println("*") ;
delay(dy1);
}   
if (D3==HIGH||D2==HIGH||D1==LOW||D0==LOW){  
Serial.println("#") ;
delay(dy1);
} 
if (D3==HIGH&&D2==HIGH&&D1==LOW&&D0==HIGH){ 
Serial.println("A") ;
delay(dy1);
} 
if (D3==HIGH&&D2==HIGH&&D1==HIGH&&D0==LOW){  
Serial.println("B") ;
delay(dy1);
} 
iif (D3==HIGH&&D2==HIGH&&D1==HIGH&&D0==HIGH){  
Serial.println("C") ;
delay(dy1);
} 
if (D3==LOW&&D2==LOW&&D1==LOW&&D0==LOW){ 
Serial.println("D") ;
delay(dy1);
} 


}
  
  
