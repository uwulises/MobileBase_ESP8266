#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
//Librerias propias
#include "motor.h"
#include "attack.h"

/**
 * @brief Funcion que lee un archivo de tipo html para publicarse en web server via FS
 * 
 * @param path direccion del archivo dentro del microcontrolador
 */
void handleFileRead(String path);

/**
 * @brief Inicia servidor web dentro del micro via ESP8266WebServer y tambien access point wifi via ESP8266WiFi.h
 * 
 */
void run_web_server(void);

/**
 * @brief Funcion que utiliza comando de velocidad para control cinematico avance-retroceso
 * 
 * @return float ponderador de velocidad en eje X
 */
float handleMotorFWBWRequest(void);

/**
 * @brief Funcion que utiliza comando de velocidad para control cinematico viraje izquierda-derecha
 * 
 * @return float ponderador de velocidad en eje Y
 */
float handleMotorLRRequest(void);

/**
 * @brief Metodo que utiliza el argumento de la seccion botones, segun la id ejecuta una accion
 * id: {1:adelante,2:izquierda,3:derecha,4:atras,5:stop,6:attack1,7:attack2}
 */
void handleButtonRequest(void);

/**
 * @brief Funcion para trabajar con las solicitudes del cliente
 * 
 */
void handle_client(void);

#endif
