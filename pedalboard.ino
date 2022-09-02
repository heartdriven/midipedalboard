#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int mem[] = {0, 0, 0, 0, 0};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  pinMode(13, OUTPUT);
}

void loop() {
  int sensorVal[] = {
    !digitalRead(2), !digitalRead(3), !digitalRead(4), !digitalRead(5), !digitalRead(6)
  };

  for (int j = 0; j < 5; j++) {
    if (sensorVal[j] != mem[j]) {
      mem[j] = sensorVal[j];

        if (mem[j]) {
          MIDI.sendNoteOn(j + 48, 64, 1);
          digitalWrite(13, HIGH);
          
        } else {
          MIDI.sendNoteOff(j + 48, 64, 1);
          digitalWrite(13, LOW);
        }
    }
  }
}
