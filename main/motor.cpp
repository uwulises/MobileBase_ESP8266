#include "motor.h"

void attach_motors(void)
{
    pinMode(pwmA, OUTPUT);
    pinMode(in1A, OUTPUT);
    pinMode(in2A, OUTPUT);
    pinMode(pwmB, OUTPUT);
    pinMode(in1B, OUTPUT);
    pinMode(in2B, OUTPUT);
}

void motor_backward(void)
{
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
    analogWrite(pwmA, MAX_SPEED);
}

void motor_forward(void)
{
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
    analogWrite(pwmB, MAX_SPEED);
}

void motor_stop(void)
{
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, LOW);
    analogWrite(pwmA, 0);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, LOW);
    analogWrite(pwmB, 0);
}