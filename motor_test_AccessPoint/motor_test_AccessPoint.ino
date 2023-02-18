
#include "web_server.h"

void setup()
{

  attach_motors();
  launch_wifi_access_point();
}

void loop()
{
  wificlient();
}
