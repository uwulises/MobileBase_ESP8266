#ifndef MOTOR_H
#define MOTOR_H

#define PWM_A 15
#define IN1_A 14
#define IN2_A 12

#define PWM_A 13
#define IN1_B 4
#define IN2_B 5

void attach_motors()
{
    pinMode(PWM_A, OUTPUT);
    pinMode(IN1_A, OUTPUT);
    pinMode(IN2_A, OUTPUT);
    pinMode(PWM_A, OUTPUT);
    pinMode(IN1_B, OUTPUT);
    pinMode(IN2_B, OUTPUT);
}

void motor_backward()
{
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);
    analogWrite(PWM_A, 255);
    digitalWrite(IN1_B, HIGH);
    digitalWrite(IN2_B, LOW);
    analogWrite(PWM_A, 255);
}

void motor_forward()
{
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    analogWrite(PWM_A, 255);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
    analogWrite(PWM_A, 255);
}

void motor_L()
{
    digitalWrite(IN1_A, !LOW);
    digitalWrite(IN2_A, !HIGH);
    analogWrite(PWM_A, 255);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
    analogWrite(PWM_A, 255);
}

void motor_R()
{
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    analogWrite(PWM_A, 255);
    digitalWrite(IN1_B, !LOW);
    digitalWrite(IN2_B, !HIGH);
    analogWrite(PWM_A, 255);
}

void motor_stop()
{
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, LOW);
    analogWrite(PWM_A, 0);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, LOW);
    analogWrite(PWM_A, 0);
}

#endif
