#include "web_server.h"

ESP8266WebServer server(80);

//Nombre y password del punto WIFI
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

void handleButtonRequest(void) {

  int id = server.arg("val").toInt();
  //Avanzar
  if (id == 1) {
    motor_FWBW(1);
    server.send(200, "text/plain", "OK");
  }
  //Izquierda
  if (id == 2) {
    motor_LR(1);
    server.send(200, "text/plain", "OK");
  }
  //Derecha
  if (id == 3) {
    motor_LR(0);
    server.send(200, "text/plain", "OK");
  }
  //Atras
  if (id == 4) {
    motor_FWBW(0);
    server.send(200, "text/plain", "OK");
  }
  //Stop
  if (id == 5) {
    motor_stop();
    server.send(200, "text/plain", "OK");
  }

  //Puedes modificar las siguientes acciones id 6 y 7
  if (id == 6) {
    Serial.println("ATTACK 1");    
    one_hit();
    server.send(200, "text/plain", "OK");
  }
  if (id == 7) {
    Serial.println("ATTACK 2");
    rotational_hit();
    server.send(200, "text/plain", "OK");
  }  
  else {
  }

}

void handleJoyRequest(void){
  int x_dir = server.arg("x_axis").toInt();
  int y_dir = server.arg("y_axis").toInt();
  Serial.print(x_dir);
  Serial.println(y_dir);
  if (x_dir == 1){
    motor_LR(1);
    server.send(200, "text/plain", "OK");
    }
  if (x_dir == -1){
    motor_LR(0);
    server.send(200, "text/plain", "OK");
  }
  if (y_dir == 1){
    motor_FWBW(1);
    server.send(200, "text/plain", "OK");
    }
  if (y_dir == -1){
    motor_FWBW(0);
    server.send(200, "text/plain", "OK");
  }

  if ((x_dir + y_dir)==0) {
    motor_stop();
    server.send(200, "text/plain", "OK");
  }
  
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
  server.on("/B", HTTP_GET, handleButtonRequest);
  server.on("/joystick", HTTP_GET,handleJoyRequest);
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
