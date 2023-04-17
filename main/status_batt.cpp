#include "status_batt.h"

int lecture = 0;
float voltage_batt = 0.0;
float battery_level = 0.0;
int read_voltage(void)
{
    lecture = analogRead(A0);
    if (lecture < 300){
        battery_level=-1;
        //manda -1 como valor de no lectura de la bateria
    }
    else{
        voltage_batt = map(lecture,MIN_VOLTAGE_A_VALUE,MAX_VOLTAGE_A_VALUE,MIN_VOLTAGE_BATT,MAX_VOLTAGE_BATT);
        battery_level = 100*voltage_batt/MAX_VOLTAGE_BATT;

    }
    return battery_level; 
}