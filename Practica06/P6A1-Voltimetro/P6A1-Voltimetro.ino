#define volt A0
#define LED 7

float value = 0.0;
float brillo = 0.0;
float voltaje = 0.0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(volt,INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(volt);
  brillo = value/1023*255;
  voltaje = value/1023*5;
  
  Serial.print("%Voltaje:");
  Serial.println(voltaje);
  Serial.print("%Value:");
  Serial.println(value);
  delay(100);
  analogWrite(LED,brillo);

}
