#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int headlight = 13;
int horn = 4;
int right1 = 9;
int right2 = 8;
int left1 = 6;
int left2 = 7;

void setup() {

  pinMode(headlight, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);

  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop() {
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    digitalWrite(right1, LOW);
    digitalWrite(right2, HIGH);
    digitalWrite(left1, LOW);
    digitalWrite(left2, HIGH);
  }

  else if (GamePad.isDownPressed()) {
    digitalWrite(right1, HIGH);
    digitalWrite(right2, LOW);
    digitalWrite(left1, HIGH);
    digitalWrite(left2, LOW);
  }

  else if (GamePad.isLeftPressed()) {
    digitalWrite(right1, LOW);
    digitalWrite(right2, HIGH);
    digitalWrite(left1, HIGH);
    digitalWrite(left2, LOW);
  }

  else if (GamePad.isRightPressed()) {
    digitalWrite(right1, HIGH);
    digitalWrite(right2, LOW);
    digitalWrite(left1, LOW);
    digitalWrite(left2, HIGH);
  }

  else if (GamePad.isCrossPressed()) {
    tone(horn, 750, 10);
  }

  else if (GamePad.isCirclePressed()) {
    if (digitalRead(headlight) == LOW) {
      digitalWrite(headlight, HIGH);
      delay(250);
    }
    else if (digitalRead(headlight) == HIGH){
      digitalWrite(headlight, LOW);
      delay(250);
    }
  }

  else {
    digitalWrite(right1, LOW);
    digitalWrite(right2, LOW);
    digitalWrite(left1, LOW);
    digitalWrite(left2, LOW);
  }
}
