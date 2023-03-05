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


void handleMotor1Request(void) {
  int velocity = server.arg("velocity").toInt();
  Serial.print("Motor 1 velocity: ");
  Serial.println(velocity);
  // TODO: control motor 1 based on the velocity value
  server.send(200, "text/html", "Velocity set to " + String(velocity) + ".");
}

void handleMotor2Request(void) {
  int velocity = server.arg("velocity").toInt();
  Serial.print("Motor 2 velocity: ");
  Serial.println(velocity);
  // TODO: control motor 2 based on the velocity value
  server.send(200, "text/html", "Velocity set to " + String(velocity) + ".");
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
  server.on("/motor1", HTTP_GET, handleMotor1Request);
  server.on("/motor2", HTTP_GET, handleMotor2Request);
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

