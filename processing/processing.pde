import processing.serial.*;

Serial comPort;
int counter = 0; // helps to keep track of values sent
int numItems = 0; // keep track of the number of values in text file
boolean sendStrings = false; // turns sending on and off
StringLoader sLoader; // used to send values to Arduino

void setup() {
  comPort = new Serial(this, Serial.list()[0], 9600);
  background(255, 0, 0); // start with a red background
}

void draw() {
}

void mousePressed() {
  // toggle between sending values and not sending values
  sendStrings = !sendStrings;
  // if sendStrings is true then send values to Arduino
  if (sendStrings) {
    background(0, 255, 0); // change the background to green
    /* when the background is green, transmit
    text file values to the Arduino */
    sLoader = new StringLoader();
    sLoader.start();
  } else {
    background(255, 0, 0); // change background to red
    // reset the counter
    counter = 0;
  }
}

/*============================================================*/
/* the StringLoader class imports data from a text file
 on a new thread and sends each value once every half second */
public class StringLoader extends Thread {

  public StringLoader() {
    // default constructor
  }

  public void run() {
    String textFileLines[] = loadStrings("C:/School/University/Projects/Toast-the-North/output.txt");
    String lineItems[] = splitTokens(textFileLines[0], ",");
    numItems = lineItems.length;
    for (int i = counter; i < numItems; i++) {
      comPort.write(lineItems[i]);
      print(lineItems[i]);
      delay(500);
    }
    counter = numItems;
  }

}