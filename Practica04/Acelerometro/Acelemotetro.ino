#define X A8
#define Y A9
#define Z A10


float Xg, Yg, Zg;
float Xval, Yval, Zval;

float Z_min = 272.0; 
float Z_max = 412.0;

float X_min = 267.0;
float X_max = 402.0;

float Y_min = 267.0;
float Y_max = 403.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(X);
  //xg = Xval/((404));
  Yval = analogRead(Y);
  Zval = analogRead(Z);

  Xg = map(Xval,X_min,X_max,-100,100);
  Xg = Xg/100;
  Yg = map(Yval,Y_min,Y_max,-100,100);
  Yg = Yg/100;
  Zg = map(Zval,Z_min,Z_max,-100,100);
  Zg = Zg/100;

  Serial.print("X: ");
  Serial.println(Xval);
  Serial.print("Y: ");
  Serial.println(Yval);
  Serial.print("Z: ");
  Serial.println(Zval);
  

}
