#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "web_server.h"
#include <math.h>

#define PWM_A 15
#define IN1_A 14
#define IN2_A 12

#define PWM_B 13
#define IN1_B 4
#define IN2_B 5
#define MAX_SPEED 255
#define TRACK_WIDTH 1
#define WHEEL_RADIUS 1

void motors_setup(void);

void motor_cmd_vel(void);

void motor_FWBW(bool dir1);

void motor_LR(bool dir2);

void motor_stop(void);

#endif
