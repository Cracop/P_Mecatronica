#define motA 10
#define motB 11
#define pot A0 //Entrada analógica

float value = 0;
float voltaje = 0;

void setup() {
  pinMode(motA, OUTPUT); //Declaración de salidas
  pinMode(motB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  voltaje = map(value,0,1023,0,5);
  Serial.println(value);
  
  if (voltaje > 0 && voltaje < 2) {
    levo();
  } 
  else if (voltaje >= 2 && voltaje < 3) {
    detener();
  }
  if (voltaje >= 3 && voltaje < 5) {
    dex();
  } 
  delay(1500);
}

void levo() {
  digitalWrite(motA,HIGH);
  digitalWrite(motB,LOW);
  Serial.println("Levogiro");
}

void dex() {
  digitalWrite(motA,LOW);
  digitalWrite(motB,HIGH);
  Serial.println("Dextrogiro");
}

void detener() {
  digitalWrite(motA,LOW);
  digitalWrite(motB,LOW);
  Serial.println("Detenido");
}
