
int cuenta=0;
void setup(){

  Serial.begin(9600);

  pinMode(22, OUTPUT);  
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  
  pinMode(29, OUTPUT);  
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
 
}
void display1 (int a, int b, int c, int d, int e, int f, int g)// Función del display
{
  digitalWrite (22,a);   
  digitalWrite (23,b);   
  digitalWrite (24,c);
  digitalWrite (25,d);
  digitalWrite (26,e);
  digitalWrite (27,f);
  digitalWrite (28,g);
}

void display2 (int h, int i, int j, int k, int l, int m, int n)// Función del display
{
  digitalWrite (29,h);   
  digitalWrite (30,i);   
  digitalWrite (31,j);
  digitalWrite (32,k);
  digitalWrite (33,l);
  digitalWrite (34,m);
  digitalWrite (35,n);
}
 
void loop(){
 
  if (Serial.available()>0){
    cuenta=Serial.read();
  }
int Digit1 = cuenta %10 ;
int Digit2 = (cuenta % 100) / 10 ;
 
 
    if (Digit1=='0'){
      display1 (1,1,1,1,1,1,0); 
    }
 
    if (Digit1=='1'){
      display1 (0,1,1,0,0,0,0);
    }
    if (Digit1=='2'){
      display1 (1,1,0,1,1,0,1);
    }
    if (Digit1=='3'){
      display1 (1,1,1,1,0,0,1);
    }
    if (Digit1=='4'){
      display1 (0,1,1,0,0,1,1);
    }
    if (Digit1=='5'){
      display1 (1,0,1,1,0,1,1);
    }
    if (Digit1=='6'){
      display1 (1,0,1,1,1,1,1);
    }
    if (Digit1=='7'){
      display1 (1,1,1,0,0,0,0); 
    }
    if (Digit1=='8'){
      display1 (1,1,1,1,1,1,1); 
    }
    if (Digit1=='9'){
      display1 (1,1,1,0,0,1,1);
    }
 
   
  delay(1000);
}

/*
void CalculaDigitos( int Num)
   {
      int8_t Digit0 = Num %10 ;
      int8_t Digit1 = (Num % 100) / 10 ;
      int8_t Digit2 = (Num % 1000) / 100 ;
      int8_t Digit3 = Num  / 1000  ;



   }
   }
*/
