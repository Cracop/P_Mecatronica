#define pot A0
#define led 13

float value = 0;
float voltaje = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  voltaje = value/1023*5;
  Serial.print("Voltaje: "); // Imprimir letrero
  Serial.println(voltaje);

  if (voltaje > 3){
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(100);
}
