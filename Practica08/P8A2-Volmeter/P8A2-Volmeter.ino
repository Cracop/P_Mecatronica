#define voltage A0
#define LED 13

float minV = 400;
float maxV = 800;

int porcentajeVolt;

void setup() {
  Serial.begin(9600);
  pinMode(LED, output);
}

void loop() {
  volmeter();

  if (porcentajeVolt > 0) {
    LightFollower();
  } else {
    LowBattery();
  }

}

void volmeter() {
  porcentajeVolt = map(voltage, minV, maxH, 0, 100);
}

void LightFollower() {
  digitalWrite(LED, HIGH);
  Serial.println("Light Follower");
}

void LowBattery() {
  digitalWrite(LED, LOW);
}
