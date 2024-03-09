#define LDRpin A5
#define ServoPin 9
#include<Servo.h>

Servo servo;

int angle = 0;
int intensity = 0;

int maxIntensity = 0;
int maxAngle = 0;

int minIntensity = 100;




void rotateBy(int a) 
{
  servo.write(servo.read() + a); // rotate further by 'a' degrees
  intensity = analogRead(A5); // reading intensity at current position
}




void placeAt(int a) 
{
  servo.write(a);
}




void checkForHigh()
{
   servo.write(0); // Position at 0 degree

  /* Test Intensity at every angle */
   for (int i=0; i<=180; i++)
   {
      Serial.print("Checking at angle : ");
      Serial.print(i);
      placeAt(i);

      intensity = analogRead(A5); // reading intensity at current position
      angle = servo.read(); // getting servo's current angle ( = i)

      if (intensity > maxIntensity) 
      {
        // Updating the current maximum value
        maxIntensity = intensity;
        maxAngle = angle;
      }
   }

}



void setup()
{
  Serial.begin(9600);
  servo.attach(ServoPin);

  checkForHigh();
  placeAt(maxAngle);
}





void loop()
{
  delay(100);
  
  intensity = analogRead(A5); // reading intensity at current position

  if (intensity < minIntensity) 
  {
    checkForHigh();
    placeAt(maxAngle);
  }
}
