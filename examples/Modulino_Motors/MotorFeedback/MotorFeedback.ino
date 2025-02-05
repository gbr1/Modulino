#include <Modulino.h>

ModulinoMotors motors;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Modulino.begin();
  motors.begin();
  motors.setSpeed(motors.MAX_SPEED, motors.MAX_SPEED);
}

void loop(){
  uint16_t senseA, senseB;
  motors.getSense(senseA, senseB);
  Serial.print(senseA);
  Serial.print("\t");
  Serial.print(senseB);
  Serial.print("\n");
  delay(100);
}