#include "web_server.h"

ESP8266WebServer server(80);

const char *ssid = "Amica";
const char *password = "battlebots";

void handleFileRead(String path) {
  // If the path ends with "/", return index.html
  if (path.endsWith("/")) {
    path += "index.html";
  }

  // Open the file from SPIFFS
  String contentType;
  if (SPIFFS.exists(path)) {
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, contentType);
    file.close();
  } else {
    server.send(404, "text/plain", "File not found");
  }
}


float handleMotorFWBWRequest(void) {
  float FWBW_val = server.arg("val").toInt();
  int p_vx = FWBW_val;
  //Serial.print("FWBW val: ");
  //Serial.println(FWBW_val);
  // TODO: control motor 1 based on the velocity value
  return p_vx;
}

float handleMotorLRRequest(void) {
  float LR_val = server.arg("val").toInt();
  int p_vy = LR_val;
  //Serial.print("LR val: ");
  //Serial.println(LR_val); 
  // TODO: control motor 2 based on the velocity value
  return p_vy;
}



void run_web_server(void) {
  // Initialize serial communication
  Serial.begin(115200);
  // Create a new SoftAP network
  WiFi.softAP(ssid, password);
  Serial.println("");
  Serial.println("");
  // Print the IP address of the SoftAP network
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("");
  Serial.println("");
  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("Failed to initialize SPIFFS");
    return;
  }
  server.on("/FWBW", HTTP_GET, handleMotorFWBWRequest);
  server.on("/LR", HTTP_GET, handleMotorLRRequest);
  // Set up web server
  server.onNotFound([]() {
    handleFileRead(server.uri());
  });

  server.begin();
  Serial.println("Web server started");
}




void handle_client(void) {
  server.handleClient();
}

