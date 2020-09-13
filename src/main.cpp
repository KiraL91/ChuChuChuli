#include "../include/manager.h"
#include "../include/config.h"

Kiral::Chuli::Manager* manager;

void setup() {
  manager = new Kiral::Chuli::Manager(PIN_OUT_AUDIO, TIMER_0);
  manager->Setup(PIN_IN_SWITCH);
}

void loop() {
  manager->Run();
}
