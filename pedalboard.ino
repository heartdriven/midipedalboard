#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int mem[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  

  pinMode(30, OUTPUT);
}

void loop() {
  int sensorVal[] = {
    !digitalRead(2),
    !digitalRead(3),
    !digitalRead(4),
    !digitalRead(5),
    !digitalRead(6),
    !digitalRead(7),
    !digitalRead(8),
    !digitalRead(9),
    !digitalRead(10),
    !digitalRead(11),
    !digitalRead(12),
    !digitalRead(13),
    !digitalRead(14),
    !digitalRead(15),
    !digitalRead(16),
    !digitalRead(17),
    !digitalRead(18),
    !digitalRead(19),
    !digitalRead(20),
    !digitalRead(21),
    !digitalRead(22),
    !digitalRead(23),
    !digitalRead(24),
    !digitalRead(25),
    !digitalRead(26),
    !digitalRead(27),
    !digitalRead(28)
  };

  for (int j = 0; j < 27; j++) {
    if (sensorVal[j] != mem[j]) {
      mem[j] = sensorVal[j];

        if (mem[j]) {
          MIDI.sendNoteOn(j + 48, 64, 1);
          digitalWrite(30, HIGH);
          
        } else {
          MIDI.sendNoteOff(j + 48, 64, 1);
          digitalWrite(30, LOW);
        }
    }
  }
}
