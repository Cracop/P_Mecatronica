#define LED 13
#define BTN 12

int buttonState ;

void setup(){
  pinMode(LED,OUTPUT);
  pinMode(BTN,INPUT);
}

void loop(){
  
  buttonState = digitalRead(BTN);

  if (buttonState == 1){
    //Rutina de 4 Hz
    digitalWrite(LED,HIGH);
    delay(250);
    digitalWrite(LED,LOW);
    delay(250);
  }else{
    //Rutina de 1 Hz
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
  }
}
