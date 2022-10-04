#define LED 7
#define lectura A0

float volt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(lectura,INPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
