#include <Wire.h>
#define motA 10
#define motB 11
#define pot A10
#define sal 9

float val, voltaje, salida;

void setup() {
  pinMode(motA,OUTPUT);
  pinMode(motB,OUTPUT);
  pinMode(sal, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pot);
  voltaje = map(val,0, 1023, 0, 5);
  
  if(voltaje<= 5 && voltaje>=3){
    Dextrogiro();
    salida = map(val,615,1023,0,255);
    }else{
      if(voltaje>=2){
        salida = 0;
        Detenido();
        }else{
          salida = map(val,410,0,0,255);
          Levogiro();
        }
      }
   
   analogWrite(sal, salida);
   Serial.println(salida);
   Serial.println(voltaje);
}

void Levogiro(){
  digitalWrite(motA, HIGH);
  digitalWrite(motB, LOW);
  Serial.print("Levogiro ");
}

void Detenido(){
  digitalWrite(motA, LOW);
  digitalWrite(motB, LOW);
  Serial.print("Detenido");
}

void Dextrogiro(){
  digitalWrite(motA, LOW);
  digitalWrite(motB, HIGH);
  Serial.print("Dextrogiro ");
  delay(253);
}
