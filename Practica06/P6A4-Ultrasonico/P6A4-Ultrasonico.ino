#define echoPin 6
#define trigPin 7
#define LED 8

long duracion;
int distancia;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duracion = pulseIn(echoPin, HIGH);

  distancia = duracion * 0.0343 / 2; //Por la velocidad del sonido

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" CM"); 

  if(distancia <= 15){
    digitalWrite(LED,HIGH);
  } else{
    digitalWrite(LED,LOW);
  }
}
