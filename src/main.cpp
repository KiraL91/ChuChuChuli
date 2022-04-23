#include "../include/manager.h"
#include "../include/configuration.h"

Kiral::Chuli::Manager* manager;

void setup() {
  Kiral::Chuli::ConfigurationBuilder* cb = new Kiral::Chuli::ConfigurationBuilder();
  Kiral::Chuli::Configuration conf = cb
    ->SetPinInSwitch(32)
    ->SetPinOuAudio(25)
    ->SetTimer(0)
    ->SetSpeechSpeed(2)
    ->Build();
  manager = new Kiral::Chuli::Manager(conf);
  manager->Setup();
}

void loop() {
  manager->Run();
}
