#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>



ESP8266WebServer server(80);

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

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  // Create a new SoftAP network
  WiFi.softAP("bbots", "12345678");

  // Print the IP address of the SoftAP network
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("Failed to initialize SPIFFS");
    return;
  }

  // Set up web server
  server.onNotFound([]() {
    handleFileRead(server.uri());
  });

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}
