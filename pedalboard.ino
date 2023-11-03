#include <Wire.h>
#include "SparkFun_TCA9534.h"

// Array of 6 sensor objects:
TCA9534 Sensor;

void setup() {
  Serial.begin(115200);
  while(!Serial);

  Wire.begin();
  if (Sensor.begin(Wire, 0x20) == true) {
    Serial.println("Connected to sensor 1.");
    Sensor.pinMode(0, GPIO_IN);
    Sensor.pinMode(1, GPIO_IN);
    Sensor.pinMode(2, GPIO_IN);
    Sensor.pinMode(3, GPIO_IN);
    Sensor.pinMode(4, GPIO_IN);
    Sensor.pinMode(5, GPIO_IN);
    Sensor.pinMode(6, GPIO_IN);
    Sensor.pinMode(7, GPIO_IN);
  }
}

void loop() {
  bool val0 = Sensor.digitalRead(0);
  bool val1 = Sensor.digitalRead(1);
  bool val2 = Sensor.digitalRead(2);
  bool val3 = Sensor.digitalRead(3);
  bool val4 = Sensor.digitalRead(4);
  bool val5 = Sensor.digitalRead(5);
  bool val6 = Sensor.digitalRead(6);
  bool val7 = Sensor.digitalRead(7);

  // Print for debugging:
  Serial.print(val0 ? "HI " : "LO ");
  Serial.print(val1 ? "HI " : "LO ");
  Serial.print(val2 ? "HI " : "LO ");
  Serial.print(val3 ? "HI " : "LO ");
  Serial.print(val4 ? "HI " : "LO ");
  Serial.print(val5 ? "HI " : "LO ");
  Serial.print(val6 ? "HI " : "LO ");
  Serial.print(val7 ? "HI\n" : "LO\n");
}
