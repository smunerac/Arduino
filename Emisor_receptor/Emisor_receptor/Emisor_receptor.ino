const int pinEmi = 1;
const int pinLed = 7;

int valorSensor = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  valorSensor=analogRead(pinEmi);
  
  if (valorSensor>900){
    digitalWrite(pinLed, LOW);
  }
  
  else{
    digitalWrite(pinLed, HIGH);
  }
  
  Serial.print("sensor = ");
  Serial.println(valorSensor);
  
  delay(1000);
}

