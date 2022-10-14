#include "DHT.h"
#define DHTPIN 21
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("setup");
  dht.begin();
}

void loop() {

  if (Serial.available() > 0){
    
    float humedad = dht.readHumidity();
    float tempC = dht.readTemperature();
    float tempF = dht.readTemperature(true);
    
    if (isnan(humedad) || isnan(tempC) || isnan(tempF)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
  
    String str = Serial.readString();
    
    if( str.equals("snsr tempC\n") ){
      Serial.print("º  TempC: ");
      Serial.print(tempC); 
      Serial.println("º");   
    }
    if(str.equals("snsr tempF\n") ){
      Serial.print("º  TempF: ");
      Serial.print(tempF); 
      Serial.println("º");   
    }
    if(str.equals("snsr hum\n") ){
      Serial.print("º  Hum: ");
      Serial.print(humedad); 
      Serial.println("%");   
    }
  }
}
