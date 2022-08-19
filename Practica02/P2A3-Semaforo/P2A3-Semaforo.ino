#define R1 13
#define A1 12
#define V1 11

#define R2 10
#define A2 9
#define V2 8


void setup() {
  // put your setup code here, to run once:
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(V1,OUTPUT);
  pinMode(V2,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  
  digitalWrite(V1,LOW);
  digitalWrite(V2,HIGH);
  delay(5000);
  
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
  
  digitalWrite(V1,LOW);
  digitalWrite(V2,LOW);
  delay(1000);

  digitalWrite(R1,LOW);
  digitalWrite(R2,HIGH);
  
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  
  digitalWrite(V1,HIGH);
  digitalWrite(V2,LOW);
  delay(5000);

  digitalWrite(R1,LOW);
  digitalWrite(R2,HIGH);
  
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW);
  
  digitalWrite(V1,LOW);
  digitalWrite(V2,LOW);
  delay(1000);
  
  
}
