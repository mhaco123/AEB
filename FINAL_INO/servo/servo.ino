#include <Servo.h>

void setup() {
  // put your setup code here, to run once:

Servo myservo;
Servo mymotor;
myservo.attach(9);
mymotor.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(filteredDirection);
mymotor.write(filteredVelocity);

}
