#include <Servo.h>

int pinNumber = 2;

const int servoPin1 = 9;
const int servoPin2 = 10;

Servo servo1;
Servo servo2;

void setup() {
  // initialize the digital pins as an output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  // turn the Serial protocol on
  Serial.begin(9600);
}

void loop() {
  byte byteRead;
  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the most recent byte
    byteRead = Serial.read();
    // subtract '0' from the read byte to convert from text to a number
    byteRead = byteRead - '0';
    // pin off if the byteRead = 0
    if (pinNumber == 9) {
      pinNumber += 2;
    }
    if (pinNumber == 13) {
      delay(5000);
      for (pinNumber; pinNumber > 2; pinNumber--) {
        digitalWrite(pinNumber, LOW);
      }
      servo1.write(90);
      servo2.write(90);
      delay(1000);
    }
    if (byteRead == 0) {
      // turn off pinNumber
      digitalWrite(pinNumber, LOW);
    }
    // pin on if the byteRead = 1
    else {
      digitalWrite(pinNumber, HIGH);
    }
    pinNumber++;
  }
}
