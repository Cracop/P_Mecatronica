#define LED 13

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED, OUTPUT); //PIN(LED, SALIDA O ENTRADA)

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH); //HIGH Estado alto lógico 5V, LOW - Estado bajo 0V
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
