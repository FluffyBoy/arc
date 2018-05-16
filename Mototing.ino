#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
String c ; int f;
void setup() {
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  Serial.begin (9600);
}

void trans(int motion)
{ if (motion > 0) {
    motor1.run(FORWARD); motor1.setSpeed(motion); motor2.run(FORWARD); motor2.setSpeed(motion);
  }
  else {
    motor1.run(BACKWARD);
    motor1.setSpeed(-motion);
    motor2.run(BACKWARD);
    motor2.setSpeed(-motion);
  }
}
int n;
 void loop()
{ if (Serial.available())
  { c = Serial.readStringUntil('\n');
    
    
    f=c[0]*100+c[1]*10+c[2]; // на вход 3 цифры 9*9*9 до нуля             0-250-499 +-500
    if (f > 500) {f -= 500; n=500;}
    f -=250;
    
    if(f>0)f+=6; 
    if(f<0)f-=6;
    if(n>0)
    { 
      motor3.setSpeed(255);
      if(n>250)motor3.run(FORWARD);
      if(n==250)motor3.run(RELEASE);            
      if(n<250)motor3.run(BACKWARD);
      n--;       
    }
    trans(f);
    delay(1);
  }

}
