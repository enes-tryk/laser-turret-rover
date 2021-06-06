#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <Dabble.h>
#include <Servo.h>

Servo horizontal;
Servo vertical;

int horizAngle = 1500;
int vertiAngle = 1500;

int horn = 8;
int laser = 11;
int LED = 12;

bool turret = false;
bool Switch = false;

int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;

void setup() {

  pinMode(horn, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(LED, OUTPUT);

  vertical.attach(10);
  horizontal.attach(9);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop() {
  Dabble.processInput();

  if (turret == false) {
    digitalWrite(LED, HIGH);
    digitalWrite(laser, LOW);

    if (GamePad.isUpPressed()) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }

    else if (GamePad.isDownPressed()) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    else if (GamePad.isLeftPressed()) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }

    else if (GamePad.isRightPressed()) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    else if (GamePad.isSquarePressed()) {
      tone(horn, 750, 10);
    }

    else if (GamePad.isCirclePressed()) {

      if (turret == false && Switch) {
        turret = true;
        Switch = false;
      }


      else if (turret == true && Switch) {
        turret = false;
        Switch = false;
      }
    }

    else if (!GamePad.isCirclePressed()) {
      Switch = true;
    }
  }

  else if (turret == true) {
    digitalWrite(LED, LOW);
    digitalWrite(laser, HIGH);

    if (GamePad.isUpPressed()) {
      vertiAngle = vertiAngle - 10;
      vertical.writeMicroseconds(vertiAngle);
    }

    else if (GamePad.isDownPressed()) {
      vertiAngle = vertiAngle + 10;
      vertical.writeMicroseconds(vertiAngle);
    }

    else if (GamePad.isLeftPressed()) {
      horizAngle = horizAngle + 10;
      horizontal.writeMicroseconds(horizAngle);
    }

    else if (GamePad.isRightPressed()) {
      horizAngle = horizAngle - 10;
      horizontal.writeMicroseconds(horizAngle);
    }

    else if (GamePad.isSquarePressed()) {
      tone(horn, 750, 10);
    }

    else if (GamePad.isCirclePressed()) {
      if (turret == false && Switch) {
        turret = true;
        Switch = false;
      }

      else if (turret == true && Switch) {
        turret = false;
        Switch = false;
      }
    }

    else if (!GamePad.isCirclePressed()) {
      Switch = true;
    }

    if (horizAngle < 850) {
      horizAngle = 850;
    }

    else if (horizAngle > 2200) {
      horizAngle = 2200;
    }

    if (vertiAngle < 800) {
      vertiAngle = 800;
    }

    else if (vertiAngle > 2100) {
      vertiAngle = 2100;
    }
  }

  Serial.print(horizAngle);
  Serial.print(", ");
  Serial.print(vertiAngle);
  Serial.println(" ");
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
