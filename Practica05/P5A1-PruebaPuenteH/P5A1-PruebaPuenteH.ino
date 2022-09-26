#define motA 10
#define motB 11

void setup() {
  pinMode(motA, OUTPUT); //Se declaran las salidas
  pinMode(motB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Estado 1: Levogiro
  digitalWrite(motA, HIGH);
  digitalWrite(motB, LOW);
  Serial.println("Levogiro");
  delay(1000);
  //Estado 2: Freno pasivo
  digitalWrite(motA, LOW);
  digitalWrite(motB, LOW);
  Serial.println("Freno pasivo");
  delay(1000);
  //Estado 3: Dextrogiro
  digitalWrite(motA, LOW);
  digitalWrite(motB, HIGH);
  Serial.println("Dextrogiro");
  delay(1000);
  //Estado 4: Freno activo
  digitalWrite(motA, HIGH);
  digitalWrite(motB, HIGH);
  Serial.println("Freno activo");
  delay(1000);
}
