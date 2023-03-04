#include "web_server.h"
#include "motor.h"

void setup() {
  run_web_server();
}

void loop() {
  handle_client();
}
