/*
const int a = 22;
const int b = 23; 
const int c = 24;
const int d = 25;
const int e = 26;
const int f = 27;
const int g = 28;
const int a1 = 29;
const int b1 = 30; 
const int c1 = 31;
const int d1 = 32;
const int e1 = 33;
const int f1 = 34;
const int g1 = 35;
*/


int mensaje=0;
void setup(){
 
  Serial.begin(9600);
  pinMode(29, OUTPUT);  
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
 
}
void display (int a, int b, int c, int d, int e, int f, int g)// Función del display
{
  digitalWrite (29,a);   
  digitalWrite (30,b);   
  digitalWrite (31,c);
  digitalWrite (32,d);
  digitalWrite (33,e);
  digitalWrite (34,f);
  digitalWrite (35,g);
}
 
void loop(){
 
  if (Serial.available()>0){
    mensaje=Serial.read();
 
    if (mensaje=='0'){
      display (0,0,0,0,0,0,1); 
    }
 
    if (mensaje=='1'){
      display (1,0,0,1,1,1,1);
    }
    if (mensaje=='2'){
      display (0,0,1,0,0,1,0);
    }
    if (mensaje=='3'){
      display (0,0,0,0,1,1,0);
    }
    if (mensaje=='4'){
      display (1,0,0,1,1,0,0);
    }
    if (mensaje=='5'){
      display (0,1,0,0,1,0,0);
    }
    if (mensaje=='6'){
      display (0,1,0,0,0,0,0);
    }
    if (mensaje=='7'){
      display (0,0,0,1,1,1,1); 
    }
    if (mensaje=='8'){
      display (0,0,0,0,0,0,0); 
    }
    if (mensaje=='9'){
      display (0,0,0,0,1,0,0);
    }
 
  } 
  delay(1000);
}