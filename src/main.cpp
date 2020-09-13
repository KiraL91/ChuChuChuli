#include "../include/manager.h"

Kiral::Chuli::Manager* manager;

void setup() {
  manager = new Kiral::Chuli::Manager();
  manager->Setup();
}

void loop() {
  manager->Run();
}
