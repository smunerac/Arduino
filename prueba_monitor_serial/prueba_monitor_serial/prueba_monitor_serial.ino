/* Simple Serial ECHO script : Written by ScottC 03/07/2012 */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */

int g
void setup() {                
Serial.begin(9600);
}

void loop() {
   

  g=digitalRead(8);
  if (g==HIGH) {
  Serial.println("3")}
  delay(300)
  
  }

