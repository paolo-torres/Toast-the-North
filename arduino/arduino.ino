int pinNumber = 2;

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
  // turn the Serial protocol on
  Serial.begin(9600);
}

void loop() {
  byte byteRead;
  // check if data has been sent from the computer:
  if (Serial.available() > 0) {
    // read the most recent byte
    byteRead = Serial.read();
    // subtract '0' from the read byte to convert from text to a number
    byteRead = byteRead - '0';
    // pin off if the byteRead = 0
    if (byteRead == 0) {
      // turn off pinNumber
      digitalWrite(pinNumber, LOW);
    } else { // pin on if the byteRead = 1
      digitalWrite(pinNumber, HIGH);
      delay(2000);
      digitalWrite(pinNumber, LOW);
    }
    if (pinNumber == 13) {
      delay(5000);
      // turn off all lights
      for(pinNumber; pinNumber > 1; pinNumber--) {
        digitalWrite(pinNumber, LOW);
      }
      pinNumber = 1;
    }
    pinNumber++;
  }
}
