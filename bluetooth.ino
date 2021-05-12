#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int signalR = 12;
int signalL = 11;
int headlight = 13;
int horn = 4;

int motorR1 = 9;
int motorR2 = 8;
int motorL1 = 6;
int motorL2 = 7;

void setup() {

  pinMode(signalR, OUTPUT);
  pinMode(signalL, OUTPUT);
  pinMode(headlight, OUTPUT);
  pinMode(horn, OUTPUT);
  
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);

  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop() {
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
  }

  else if (GamePad.isDownPressed()) {
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
  }

  else if (GamePad.isLeftPressed()) {
    digitalWrite(signalL, (millis() / 350) % 2);
    
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
  }

  else if (GamePad.isRightPressed()) {
    digitalWrite(signalR, (millis() / 350) % 2);
    
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
  }
  
  else if (GamePad.isSquarePressed()) {
    tone(horn, 750, 10);
  }

  else if (GamePad.isCirclePressed()) {
    
    if (digitalRead(headlight) == LOW) {
      digitalWrite(headlight, HIGH);
      delay(250);
    }
    
    else if (digitalRead(headlight) == HIGH) {
      digitalWrite(headlight, LOW);
      delay(250);
    }
  }

  else {
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, LOW);
    
    digitalWrite(signalR, LOW);
    digitalWrite(signalL, LOW);
  }
}
