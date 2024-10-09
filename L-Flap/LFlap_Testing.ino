#include <Servo.h>
int dc;
Servo s;

#define servoPin 36                  //check

int l_pwm = 9;                       //check
int r_pwm = 10;                      //check
int l_en = 6;                        //check
int r_en = 7;                        //check

int dc_pwm = 30;                     //check

int motor, servo;

void setup() {
  Serial.begin(115200);
  s.attach(servoPin);
  pinMode(r_en, OUTPUT);
  pinMode(l_en, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  pinMode(l_pwm, OUTPUT);

  digitalWrite(r_en, HIGH);
  digitalWrite(l_en, HIGH);
  s.write(150);
}

void loop() {

  Serial.println("1. DC \n2. Servo");
  while(Serial.available()==0);
  motor = Serial.parseInt();
  Serial.println(motor);

  if(motor == 1){
    Serial.println("DC : \n1.Lift   2.Down");
    while (Serial.available()==0);
    dc = Serial.parseInt();
    Serial.println(dc);
    if(dc == 1){
      Serial.println("Lift");
      analogWrite(l_pwm, 0);
      analogWrite(r_pwm, dc_pwm);
    }
    else if (dc == 2) {
      Serial.println("Down");
      analogWrite(r_pwm, 0);
      analogWrite(l_pwm, dc_pwm);
    }
      delay(5600);
      analogWrite(r_pwm, 0);
      analogWrite(l_pwm, 0);
  }

  else if(motor == 2){
    Serial.println("Servo : \n1.Grip   2.Ungrip");
    while (Serial.available()==0);
    servo = Serial.parseInt();
    Serial.println(servo);
    if(servo == 1){
      Serial.println("Grip");
      s.write(150);

    }
    else if (servo == 2) {
      Serial.println("Ungrip");
      s.write(190);
    }
  }
  Serial.println();
}
