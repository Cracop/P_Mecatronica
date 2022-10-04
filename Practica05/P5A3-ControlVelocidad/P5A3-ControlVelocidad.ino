#include <Wire.h>
#define motA 10
#define motB 11
#define pot A10
#define sal 9

float val, salida;
int voltaje;

void setup() {
  pinMode(motA,OUTPUT);
  pinMode(motB,OUTPUT);
  pinMode(sal, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pot);
  voltaje = map(val,0, 1023, 0, 5);
   analogWrite(sal, salida);
   Serial.println(salida);
   Serial.println(voltaje);
   delay(1000);
}
