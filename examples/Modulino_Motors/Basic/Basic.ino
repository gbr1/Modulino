#include <Modulino.h>

ModulinoMotors motors;

void setup() {
  Modulino.begin();
  motors.begin();
}

void loop(){
  for (int i = -motors.MAX_SPEED; i<motors.MAX_SPEED; i++){
    motors.setSpeed(i,i);
    delay(1);
  }
  for (int i = motors.MAX_SPEED; i>-motors.MAX_SPEED; i--){
    motors.setSpeed(i,i);
    delay(1);
  }
}