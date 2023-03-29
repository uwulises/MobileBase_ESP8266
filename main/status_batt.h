#ifndef STATUS_BATT
#define STATUS_BATT
#include <Arduino.h>
// Voltaje mapeo 11.1-12.6V a 330-385 ish

#define BATT_PIN A0 // Analog pin ESP8266

#define MIN_VOLTAGE_A_VALUE 330
#define MAX_VOLTAGE_A_VALUE 380
#define MIN_VOLTAGE_BATT 11.1
#define MAX_VOLTAGE_BATT 12.6

int read_voltage(void);

#endif