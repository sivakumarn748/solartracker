#define LDRping A5
#define ServoPin 9

#include<Servo.h>

Servo servo;

int intensity = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(ServoPin);
  servo.write(90);
}

void loop() {
  Serial.println(analogRead(A5));
}
