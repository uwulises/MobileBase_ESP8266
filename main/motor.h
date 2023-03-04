#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

#define pwmA 13
#define in1A 12
#define in2A 14

#define pwmB 2
#define in1B 0
#define in2B 4
#define MAX_SPEED 255

void attach_motors(void);

void motor_backward(void);

void motor_forward(void);

void motor_stop(void);

#endif
