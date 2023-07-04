#include "motor.h"

void motors_setup(void)
{
  pinMode(PWM_A, OUTPUT);
  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);
}

void motor_cmd_vel(void) {
  float px = handleMotorFWBWRequest();
  float py = handleMotorLRRequest();
  float vec_vel = sqrt(pow(px, 2) + pow(py, 2));
  float ang_vel = atan2 (py, px) * 180 / PI;
}

void motor_FWBW(bool dir1)
{ 
  motor_cmd_vel();
    
  if (dir1) {
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    analogWrite(PWM_A, SPEED_A);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
    analogWrite(PWM_B, SPEED_B);
  }
  else {
    digitalWrite(IN1_A, !LOW);
    digitalWrite(IN2_A, !HIGH);
    analogWrite(PWM_A, SPEED_A);
    digitalWrite(IN1_B, !LOW);
    digitalWrite(IN2_B, !HIGH);
    analogWrite(PWM_B, SPEED_B);
  }

}

void motor_LR(bool dir2) {
  if (dir2) {
    digitalWrite(IN1_A, !LOW);
    digitalWrite(IN2_A, !HIGH);
    analogWrite(PWM_A, SPEED_A);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
    analogWrite(PWM_B, SPEED_B);
  }
  else {
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);
    analogWrite(PWM_A, SPEED_A);
    digitalWrite(IN1_B, !LOW);
    digitalWrite(IN2_B, !HIGH);
    analogWrite(PWM_B, SPEED_B);
  }
}

void motor_stop(void)
{
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, LOW);
  analogWrite(PWM_A, 0);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, LOW);
  analogWrite(PWM_B, 0);
}
