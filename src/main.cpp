#include <Arduino.h>

// Declaration of variables and their respective pins
int button1 = 2;
int button2 = 3;
int vacant1 = 4;
int vacant2 = 6;
int occupied1 = 7;
int occupied2 = 8;

// Setting the state of the buttons, this will allow the users to simply use a button to determine room occupancy
int buttonState1 = 0;
int buttonState2 = 0;

bool bool_vacant1 = false;
bool bool_vacant2 = false;

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
    bool_vacant1 = true;
  } else {
    digitalWrite(vacant1, LOW);
    digitalWrite(occupied1, HIGH);
    bool_vacant1 = false;
  }

  if ((buttonState2 % 2) == 0) {
    digitalWrite(vacant2, HIGH);
    digitalWrite(occupied2, LOW);
    bool_vacant2 = true;
  } else {
    digitalWrite(vacant2, LOW);
    digitalWrite(occupied2, HIGH);
    bool_vacant2 = false;
  }

  // Output button states to the Serial Monitor
  Serial.println(bool_vacant1);
  Serial.println(bool_vacant2);

  delay(1200);
}

