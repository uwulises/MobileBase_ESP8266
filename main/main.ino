#include "web_server.h"

void setup() {
  run_web_server();
  motors_setup();
  attack_setup();
}

void loop() {
  handle_client();
}
