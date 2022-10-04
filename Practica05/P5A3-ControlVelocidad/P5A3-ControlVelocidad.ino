#include <Wire.h>
#define motA 10
#define motB 11
#define pot A0
#define sal 9

<<<<<<< HEAD
float val, salida;
int voltaje;
=======
float pote, potencia, salida;
>>>>>>> 5dd4e17a09df64c34faf3468b0ceafb7546ed786

void setup() {
  pinMode(motA,OUTPUT);
  pinMode(motB,OUTPUT);
  pinMode(sal, OUTPUT);
  Serial.begin(9600);
}

void loop() {
<<<<<<< HEAD
  val = analogRead(pot);
  voltaje = map(val,0, 1023, 0, 5);
   analogWrite(sal, salida);
   Serial.println(salida);
   Serial.println(voltaje);
   delay(1000);
=======
  pote=analogRead(pot);
  potencia = map(pote,0, 1023, 0, 5);
  
  if(potencia<= 5 && potencia>=3){
    Dextrogiro();
    salida = map(pote,615,1023,0,255);
    }else{
      if(potencia>=2){
        salida = 0;
        Detenido();
        }else{
          salida = map(pote,410,0,0,255);
          Levogiro();
        }
      }
   
   analogWrite(sal, salida);
   Serial.println(salida);
   Serial.println(potencia);
}

void Levogiro(){
  digitalWrite(motA, HIGH);
  digitalWrite(motB, LOW);
  Serial.print("Levogiro ");
  delay(1000);
}

void Detenido(){
  digitalWrite(motA, LOW);
  digitalWrite(motB, LOW);
  Serial.print("Detenido");
    delay(1000);
}

void Dextrogiro(){
  digitalWrite(motA, LOW);
  digitalWrite(motB, HIGH);
  Serial.print("Dextrogiro ");
  delay(253);
>>>>>>> 5dd4e17a09df64c34faf3468b0ceafb7546ed786
}
