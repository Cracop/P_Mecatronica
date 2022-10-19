#define sensor A0
#define LED 8

long duracion;
long distancia;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);  
}

void loop() {
    duracion = analogRead(sensor);
    distancia = pow(duracion/328.88,-1/0.596);
    if(distancia < 15){
      digitalWrite(LED,HIGH);
      
    }else{
      digitalWrite(LED,LOW);
    }

    Serial.print("Distancia: ");
    Serial.println(distancia);
    Serial.println(" cm");
}
