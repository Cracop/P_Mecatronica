// Codigo para el esclavo
#include <Wire.h>
#include <Servo.h>

Servo servo; // Definimos una variable para el servo motor

int servo_angle;

void setup() {
  servo.attach(3);
  
  Wire.begin(0xAF);
  
  Serial.begin(9600);
}

void loop() {
  // Imprimimos llegadas de datos
  Wire.onReceive(lectura);
  Serial.print("  Ángulo Servo: ");
  Serial.println(servo_angle);
}

void lectura() {
  servo_angle = Wire.read();
  servo.write(servo_angle);
}
