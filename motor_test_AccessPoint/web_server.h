#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "motor.h"
#include <ESP8266WiFi.h>
const char *ssid = "Amica";
const char *password = "battlebots";
WiFiServer server(80);

void launch_wifi_access_point()
{
  Serial.begin(9600);
  delay(50);
  WiFi.softAP(ssid, password);
  server.begin(); // Iniciamos el servidor
  delay(50);
  Serial.println("Servidor Iniciado");
  Serial.println("Ingrese desde un navegador web usando la siguiente IP:");
  Serial.println("La red establecida por softAP tendrá una dirección IP predeterminada de 192.168.4.1");
}

void wificlient()
{
  WiFiClient client = server.available();
  if (client) // Si hay un cliente presente
  {
    Serial.println("Nuevo Cliente");

    // esperamos hasta que hayan datos disponibles
    while (!client.available() && client.connected())
    {
      delay(1);
    }

    // Leemos la primera línea de la petición del cliente.
    String linea1 = client.readStringUntil('r');
    Serial.println(linea1);

    if (linea1.indexOf("BW") > 0)
    {
      motor_backward();
      Serial.println("backward");
    }
    if (linea1.indexOf("FW") > 0)
    {

      motor_forward();
      Serial.println("forward");
    }
    if (linea1.indexOf("L") > 0)
    {

      motor_L();
      Serial.println("left");
    }
    if (linea1.indexOf("R") > 0)
    {

      motor_R();
      Serial.println("right");
    }
    if (linea1.indexOf("STOP") > 0)
    {

      motor_stop();
      Serial.println("stop");
    }

    client.flush();

    Serial.println("Enviando respuesta...");
    // Encabesado http
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close"); // La conexión se cierra después de finalizar de la respuesta
    client.println();
    // Pagina html  para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
    client.println("<head><title>BBots2023</title>");
    client.println(" <style>\n\
                   .button {\n\
                   border: none;\n\
                   color: white;\n\
                   padding: 30px 25px;\n\
                   width: 100%;\n\
                   text-align: center;\n\
                   text-decoration: none;\n\
                   display: inline-block;\n\
                   font-size: 30px;\n\
                   margin: 4px 2px;\n\
                   cursor: pointer;\n\
                 }\n\
                   .button1 {background-color: #4CAF50;} \n\
                   .button2 {background-color: #008CBA;} \n\
                   .button3 {background-color: #da1626;} \n\
                   </style>");
    client.println("<body>");
    client.println("<h1 align='center'>Test Amica Battlebots 2023</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br />");
    client.println("<button class='button button1' onClick=location.href='./?FW'>ADELANTE</button>");
    client.println("<br />");
    client.println("<button class='button button2' onClick=location.href='./?L'>IZQUIERDA</button>");
    client.println("<button class='button button2' onClick=location.href='./?R'>DERECHA</button>");
    client.println("<br />");
    client.println("<button class='button button2' onClick=location.href='./?BW'>ATRAS</button>");
    client.println("<br />");
    client.println("<br />");
    client.println("<button class='button button3' onClick=location.href='./?STOP'>STOP</button>");
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");

    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();
  }

}
#endif
