#include "web_server.h"

void setup() {
  run_web_server();
  motors_setup();
}

void loop() {
  handle_client();
}
