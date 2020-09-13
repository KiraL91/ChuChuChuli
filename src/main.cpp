#include <Arduino.h>

#include "../lib/XT_DAC_Audio/XT_DAC_Audio.h"
#include "../assets/sound/sound.h"

#define PIN_OUT_AUDIO 25
#define PIN_IN_SWITCH 32
#define TIMER_0 0

XT_Wav_Class ChuliSound(Sound);
XT_DAC_Audio_Class DacAudio(PIN_OUT_AUDIO, TIMER_0);

bool play = false;

void IRAM_ATTR isr() {
  play = !true;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_IN_SWITCH, INPUT);
  attachInterrupt(PIN_IN_SWITCH, isr, FALLING);
  ChuliSound.Speed = 2;
}

void loop() {
  DacAudio.FillBuffer();
  if(!ChuliSound.Playing && play) {
    DacAudio.Play(&ChuliSound);
    play = false;
  }
}
