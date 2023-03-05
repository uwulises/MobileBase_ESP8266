#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "web_server.h"
#include <math.h>
#define pwmA 13
#define in1A 12
#define in2A 14

#define pwmB 2
#define in1B 0
#define in2B 4
#define MAX_SPEED 255
#define TRACK_WIDTH 1
#define WHEEL_RADIUS 1

void motors_setup(void);

void motor_cmd_vel(void);

void motor_FWBW(bool dir1);

void motor_LR(bool dir2);

void motor_stop(void);

#endif
