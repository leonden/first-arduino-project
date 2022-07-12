#include <RCSwitch.h>

int buttonLeft = 13;
int buttonMid = 12;
int buttonRight = 11;

int buttonLeftStatus = 0;
int buttonMidStatus = 0;
int buttonRightStatus = 0;

RCSwitch sendModule = RCSwitch();

void setup() {
  Serial.begin(9600);

  // defining pin as transmitting pin
  sendModule.enableTransmit(10);

  // defining the pin as input
  pinMode(buttonLeft, INPUT);
  pinMode(buttonMid, INPUT);
  pinMode(buttonRight, INPUT);
}

void loop() {
  // reads status of pin
  buttonLeftStatus = digitalRead(buttonLeft);
  buttonMidStatus = digitalRead(buttonMid);
  buttonRightStatus = digitalRead(buttonRight);

  if (buttonLeftStatus == HIGH) {
    sendModule.send(1111, 24);  // sendModule sends signal 1111
    Serial.println("left button pressed");
    delay(1000);
    sendModule.resetAvailable();
  } else if (buttonMidStatus == HIGH) {
    sendModule.send(2222, 24);  // sendModule sends signal 2222
    Serial.println("mid button pressed");
    delay(1000);
    sendModule.resetAvailable();
  } else if (buttonRightStatus == HIGH) {
    sendModule.send(3333, 24);  // sendModule sends signal 3333
    Serial.println("right button pressed");
    delay(1000);
    sendModule.resetAvailable();
  }
}