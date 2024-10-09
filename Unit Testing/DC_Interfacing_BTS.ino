int l_pwm = 9;                    //check
int r_pwm = 10;                   //check
int l_en = 6;                     //check
int r_en = 7;                     //check

void setup() {
  pinMode(l_pwm, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  pinMode(l_en, OUTPUT);
  pinMode(r_en, OUTPUT);
  
  digitalWrite(l_en, HIGH);
  digitalWrite(r_en, HIGH);
  Serial.begin(115200);

}

void loop() {
  Serial.println("Enter the Speed : ");
  while(Serial.available() == 0){}
  int speed = Serial.parseInt();
  int x = map(speed, 0, 100, 0, 255 ); // map(var, wanted range , available range)
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, x);
}
