#ifndef ATTACK_H
#define ATTACK_H

#include <Arduino.h>
#define SPEED_HIT 255 //PWM value
#define attack_1_pin 2 //PWM LED only output
#define attack_2_pin 0 //PWM only output

void attack_setup(void);

void attack_1(void);

void attack_2(void);


#endif
