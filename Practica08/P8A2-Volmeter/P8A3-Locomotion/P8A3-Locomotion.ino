#define acelerar1 2
#define signal2MotorA 3
#define signal1MotorA 4

#define acelerar2 7
#define signal1MotorB 6
#define signal2MotorB 5

#define voltimetro A0

void setup() {
  Serial.begin(9600);
  
  pinMode(signal1MotorA, OUTPUT);
  pinMode(signal1MotorB, OUTPUT);
  pinMode(signal2MotorA, OUTPUT);
  pinMode(signal2MotorB, OUTPUT);

  stopRobot();
}

void loop() {
  DriveRobot(1,1);
  delay(2000);
  DriveRobot(-1,-1);
  delay(2000);
  DriveRobot(1,-1);
  delay(2000);
  DriveRobot(-1,1);
  delay(2000);
  DriveRobot(0,0);
  delay(2000);
}

void DriveRobot(float LSignal, float RSignal) {
  if (LSignal > 0 && RSignal > 0) {
    digitalWrite(signal1MotorA, HIGH);
    digitalWrite(signal2MotorA, LOW);

    digitalWrite(signal1MotorB, HIGH);
    digitalWrite(signal2MotorB, LOW);
  } else if (LSignal > 0 && RSignal < 0) {
    digitalWrite(signal1MotorA, HIGH);
    digitalWrite(signal2MotorA, LOW);
    
    digitalWrite(signal1MotorB, LOW);
    digitalWrite(signal2MotorB, HIGH);
  } else if (LSignal < 0 && RSignal > 0) {
    digitalWrite(signal1MotorA, HIGH);
    digitalWrite(signal2MotorA, LOW);

    digitalWrite(signal1MotorB, HIGH);
    digitalWrite(signal2MotorB, LOW);
  } else {
    stopRobot();
  }
}

void stopRobot() {
    digitalWrite(signal1MotorA, LOW);
    digitalWrite(signal2MotorA, LOW);
    digitalWrite(signal1MotorB, LOW);
    digitalWrite(signal2MotorB, LOW);
}
