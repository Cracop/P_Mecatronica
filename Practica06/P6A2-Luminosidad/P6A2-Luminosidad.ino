#include <DHT_U.h>

#define pot A0
#define LED 13

float value = 0.0;
float brillo = 0.0;
float valor = 0.0;
float y = 0;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  value = analogRead(pot);
  y = map(brillo,0,999,0,255);
  brillo = 255-(value/1024*255);
  
  Serial.print("%Brillo:");
  Serial.println(brillo);
  Serial.println(y);
  delay(500);
  analogWrite(LED,brillo);
}
