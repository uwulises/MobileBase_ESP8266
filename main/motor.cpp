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

  float rawLeft;
  float rawRight;

  // Now angle indicates the measure of turn
  // Along a straight line, with an angle o, the turn co-efficient is same
  // this applies for angles between 0-90, with angle 0 the co-eff is -1
  // with angle 45, the co-efficient is 0 and with angle 90, it is 1
  ​
  float tcoeff = -1 + (ang_vel / 90) * 2;
  float turn = tcoeff * abs(abs(y) - abs(x));
  turn = round(turn * 100) / 100;
  ​
  float mov = sqrt(pow(px, 2) + pow(py, 2)); // podria ser el max entre px y py

  // First and third quadrant
  if ((x >= 0 && y >= 0) || (x < 0 && y < 0))  {
    rawLeft = mov; 
    rawRight = turn;
  }
  else {
    rawRight = mov; 
    rawLeft = turn;
  }
  ​
  // Reverse polarity
  if (y < 0) {
    rawLeft *= -1; //cambiar el signo a ambos
    rawRight *= -1;
  }
  
  ​
  // Map the values onto the defined rang
  SPEED_A = map(rawLeft, MIN_JOY, MAX_JOY, MIN_SPEED, MAX_SPEED);
  SPEED_B = map(rawRight, MIN_JOY, MAX_JOY, MIN_SPEED, MAX_SPEED);

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
