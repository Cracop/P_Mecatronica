// Codigo para el maestro
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define X A0
#define Y A1
#define Z A2

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float XG, YG, ZG, roll_angle;
int servo_angle;

float x_min = 267.0;
float x_max = 402.0;
float y_min = 267.0;
float y_max = 403.0;
float z_min = 272.0;
float z_max = 412.0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {
  XG = map(analogRead(X), x_min, x_max, -100, 100);
  XG = XG/100;
  YG = map(analogRead(Y), y_min, y_max, -100, 100);
  YG = YG/100;
  ZG = map(analogRead(Z), z_min, z_max, -100, 100);
  ZG = ZG/100;

  // Calculamos el ángulo del roll
  roll_angle = -atan(tan(YG/(sqrt(sq(XG)+sq(ZG)))))*180/PI;

  // Convertir angulo de roll a angulo de servo
  servo_angle = map((int)roll_angle, -90, 90, 0, 90);

  // Mandar a esclavo
  Wire.beginTransmission(0xAF);
  Wire.write(servo_angle);
  Wire.endTransmission();

  // Imprimimos resultados en pantalla LCD
  lcd.setCursor(0,0);
  lcd.print("Angulo: ");
  lcd.setCursor(8,0);
  lcd.print(servo_angle);

  delay(50);
  
  // Imprimimos resultados en consola
  Serial.print("Ángulo Roll: ");
  Serial.print(roll_angle);
  Serial.print("  Ángulo Servo: ");
  Serial.println(servo_angle);
}
