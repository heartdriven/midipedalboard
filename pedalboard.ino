#include <Wire.h>
#include "SparkFun_TCA9534.h"

// Array of 6 sensor objects:
TCA9534 sensors[6];
// Respective sensor addresses:
int addresses[6] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25};
// Main state object, which keeps track of the read values:
int state[6][8];
// Amount of sensors per sensorbar:
int sizes[6] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(115200);

  // Hardcoded lengths of sensor for now:
  sizes[0] = 8;

  // Set state initial values:
  for (int i = 0; i < 6; i++) {
    // Set all states to HIGH initially:
    for (int j = 0; j < sizes[i]; j++) {
      state[i][j] = NULL;
    }
  }
  // Wait for Serial to be ready before printing anything:
  while(!Serial);

  Wire.begin();
  Wire.setClock(3400000);

  for (int i = 0; i < 6; i++) {
    if (sensors[i].begin(Wire, addresses[i]) == true) {
      char bufferSensorbar[40];
      sprintf(bufferSensorbar, "Sensorbar %i active.", i);
      Serial.println(bufferSensorbar);
      for (int j = 0; j < sizes[i]; j++) {
        sensors[i].pinMode(j, INPUT_PULLUP);
        sensors[i].digitalWrite(j, HIGH);

        // Also, set initial state to HIGH:
        state[i][j] = HIGH;
      }
    }
  }
}

void loop() {
  // Loops over all 6 sensor bars (if defined):
  for (int i = 0; i < 6; i++) {
    // Looping over all sensors as defined in sizes[] array:
    for (int j = 0; j < sizes[i]; j++) {
      char bufferCurrentState[40];
      // Reading state of the sensor:
      bool readState = sensors[i].digitalRead(j);
      if (state[i][j] != readState) {
        sprintf(bufferCurrentState, "[%i - %i] - %s", i, j, readState ? "HIGH" : "LOW");
        Serial.println(bufferCurrentState);
        state[i][j] = readState;

        // toString function for debugging:
        printState(i);
      }
    }
  }
}

/*
  Debug function that prints the current state.

  Loops over the current state array of a certain sensorbar and prints the
  values that were stored in a readable manner.
*/
void printState(int i) {
  Serial.print("Sensorbar ");
  Serial.print(i);
  Serial.print(" state: [");
  for (int j = 0; j < sizes[i]; j++) {
    Serial.print(state[i][j]);
    if (j > sizes[i] - 1) {
      Serial.print("-");
    }
  }
  Serial.print("]\n");
}
