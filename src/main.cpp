#include <Arduino.h>

// Declaration of variables and their respective pins
int vacant1 = 11;
int vacant2 = 9;
int occupied1 = 10;
int occupied2 = 8;
int button2 = 3;
int button1 = 2;

// Setting the state of the buttons, this will allow the users to simply use a button to determine room occupancy
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
    // LED lights are set as the outputs
    pinMode(vacant1, OUTPUT);
    pinMode(occupied1, OUTPUT);
    pinMode(vacant2, OUTPUT);
    pinMode(occupied2, OUTPUT);

    // Buttons are set as inputs to obtain the button states
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);

    // Simply used for debugging and to make sure everything runs smoothly, can be disabled
    Serial.begin(9600);
}

void loop() {
  // Read the state of the buttons
  int state1 = digitalRead(button1);
  int state2 = digitalRead(button2);

  if (state1 == HIGH) {
    buttonState1 += 1;
  }

  if (state2 == HIGH) {
    buttonState2 += 1;
  }

  // Control room occupancy indicators through determination of on/off button states
  if ((buttonState1 % 2) == 0) {
    digitalWrite(vacant1, HIGH);
    digitalWrite(occupied1, LOW);
  } else {
    digitalWrite(vacant1, LOW);
    digitalWrite(occupied1, HIGH);
  }

  if ((buttonState2 % 2) == 0) {
    digitalWrite(vacant2, HIGH);
    digitalWrite(occupied2, LOW);
  } else {
    digitalWrite(vacant2, LOW);
    digitalWrite(occupied2, HIGH);
  }

  // Output button states to the Serial Monitor
  Serial.println("Button State 1: " + String(buttonState1));
  Serial.println("Button State 2: " + String(buttonState2));

  delay(1200);
}

