#include <Servo.h>
Servo motor;
int a, servoPin = 3;

void setup() {
  motor.attach(servoPin);
  Serial.begin(115200);
  // motor.write(0);
}
void loop() {
  Serial.println("Enter the Angle : ");
  while(Serial.available() == 0);
  a = Serial.parseInt();
  motor.write(a); //a is in degree use to give angle.
}
