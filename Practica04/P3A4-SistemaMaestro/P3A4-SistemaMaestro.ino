//Codigo para el maestro
#include <Wire.h>

void setup()
{
  Wire.begin();

  Serial.begin(9600);
}

void loop()
{
    for (int i = 0; i < 2; i++){
      Wire.beginTransmission(0xAF);
      Wire.write(i);
      Wire.endTransmission();
      Serial.println(i);
      delay(500);
    }
  
}
