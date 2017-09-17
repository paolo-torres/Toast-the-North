#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200 // motor is a 1.8 deg stepper so 200 steps

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);


void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(60);
  Serial.println("60");
  delay(2000);
}

void loop()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);
  Serial.println("60");
  delay(2000);
  stepper.setSpeed(10);
  Serial.println("10");
  delay(2000);
  stepper.setSpeed(120);
  Serial.println("120");
  delay(2000);
  //stepper.setSpeed(60);
  //Serial.println("60");
  //delay(10000);
  Serial.println("forward");
  stepper.step(STEPS);
} 
