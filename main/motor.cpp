#include "motor.h"

void motors_setup(void)
{
  pinMode(pwmA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
}

void motor_cmd_vel(void) {
  float px = handleMotorFWBWRequest();
  float py = handleMotorLRRequest();
  float vec_vel = sqrt(pow(px, 2) + pow(py, 2));
  float ang_vel = atan2 (py, px) * 180 / PI;
}

void motor_FWBW(bool dir1)
{
  if (dir1) {
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
    analogWrite(pwmB, MAX_SPEED);
  }
  else {
    digitalWrite(in1A, !LOW);
    digitalWrite(in2A, !HIGH);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, !LOW);
    digitalWrite(in2B, !HIGH);
    analogWrite(pwmB, MAX_SPEED);
  }

}

void motor_LR(bool dir2) {
  if (dir2) {
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, !LOW);
    digitalWrite(in2B, !HIGH);
    analogWrite(pwmB, MAX_SPEED);
  }
  else {
    digitalWrite(in1A, !LOW);
    digitalWrite(in2A, !HIGH);
    analogWrite(pwmA, MAX_SPEED);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
    analogWrite(pwmB, MAX_SPEED);
  }
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
