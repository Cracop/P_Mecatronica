#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define LED 8

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int pos;

#define sensor A1

//luminosidad
#define pot A0
float luminosidad = 0.0;
float brillo = 0.0;
float valor = 0.0;
float valVolt = 0.0;

//ultrasonico
#define echoPin 6
#define trigPin 7
long duracion;
int distancia;

//temperatura humedad
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 19  
DHT dht(DHTPIN, DHTTYPE);
String dato;

//voltimetro
#define volt A2

float voltaje = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  //lcd
  lcd.init();                      // initialize the lcd 
  //lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  //ultrasonico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //temperatura humedad
  dht.begin();

  //voltimetro
  pinMode(volt,INPUT);
}


void loop() {
    duracion = analogRead(sensor);
    distancia = pow(duracion/758.73,-1/.486);

    //luminosidad
    luminosidad = analogRead(pot);

    // ultrasonico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duracion = pulseIn(echoPin, HIGH);
    float dUltrasonico = duracion * 0.0343/2;

    //voltimetro
    valVolt = analogRead(volt);
    voltaje = valVolt/1023*5;
    
    //temperatura
    float t = dht.readTemperature();

    //prints en el monitor serial
    Serial.print("V: ");
    Serial.print(valVolt);
    Serial.print(" bits -- L: ");
    Serial.print(luminosidad);
    Serial.print(" bits -- T: ");
    Serial.print(t);
    Serial.print(" C° -- DU: ");
    Serial.print(dUltrasonico);
    Serial.print(" cm -- DS: ");
    Serial.print(distancia);
    Serial.println(" cm");

    String linea2individual="";
    String linea2conjunto="";
    int cont=0;
    
    //lcd
    lcd.setCursor(0,0);
    String lString = String(luminosidad);
    lcd.print("L: " + lString + " bits");
    if(valVolt>357){ // voltaje menor a 6.40V
      linea2individual = "Low Battery";
      linea2conjunto += "Bt-";
      cont++;
    }
    if(t>26){
      linea2individual = "Overheating";
      linea2conjunto += "OvrH-";
      cont++;
    }
    if(dUltrasonico < 15){
      linea2individual = "U_Obstacle";
      linea2conjunto += "UObs-";
      cont++;
    }
    if(distancia < 15){
      linea2individual = "S_Obstacle";
      linea2conjunto += "SObs-";
      cont++;
    }
    if(cont>0){
      digitalWrite(LED,HIGH);
      lcd.setCursor(0,1);
      if(cont>1){
        lcd.print(linea2conjunto + "                             ");
      }
      else
        lcd.print(linea2individual + "                             ");
    }
    else{
      lcd.setCursor(0,1);
      lcd.print("                    ");
      digitalWrite(LED,LOW);
      
    }
}
