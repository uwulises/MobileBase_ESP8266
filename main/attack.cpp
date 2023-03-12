#include "attack.h"

void attack_setup(void) {
  pinMode(attack_1_pin, OUTPUT);
  pinMode(attack_2_pin, OUTPUT);
  //start LOW (LED on attack 1 toggle ON)
  digitalWrite(attack_1_pin, LOW);
  digitalWrite(attack_2_pin, LOW);
}
void one_hit(void) {

}

void rotational_hit() {

}
