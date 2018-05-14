# arc
GO
#include <AFMotor.h> // Подключаем библиотеку для работы с шилдом 
AF_DCMotor motor1(1);// Подключаем моторы к клеммникам M1
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
char c=' ';
    int f;
void setup() {
  motor1.setSpeed(255);// Задаем максимальную скорость вращения моторов
  motor1.run(RELEASE);
  Serial.begin (9600);
}
void trans(int motion)
{
  if (motion > 0)
  { motor1.run(FORWARD); 
    motor1.setSpeed(motion); 
     motor2.run(FORWARD); 
    motor2.setSpeed(motion); 

  }
  else
  {
    motor1.run(BACKWARD); 
    motor1.setSpeed(-motion); 
     motor2.run(BACKWARD); 
    motor2.setSpeed(-motion); 
  }


}
void puck() {
  motor3.run(FORWARD); // Задаем движение вперед
  motor3.setSpeed(255); // Задаем скорость движения
  delay(1000); //Указываем время движения
  motor3.run(RELEASE); // Останавливаем двигатели
  delay(100); // Указываем время задержки

  motor3.run(BACKWARD);  // Задаем движение назад
  motor3.setSpeed(255);  // Задаем скорость движения
  delay(1000); // Указываем время движения}
}
void loop() {
  if (Serial.available())
  { c = Serial.read();
    f= int(c);
    if (f>127) {
        f=f-128;
        puck();      
    }
    f-=64; f*=4;
    trans(f);
    
  }


}

