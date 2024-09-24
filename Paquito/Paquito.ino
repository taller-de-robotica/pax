#include "ChasisPaquito.hpp"

ChasisPaquito chasis = ChasisPaquito();


void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
//Serial.println(0);
chasis.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //chasis.go_advance(50);
  //delay(500);
  chasis.countclockwise(20);
  delay(5000);
  chasis.frenar();
  //chasis.go_back(50);
  delay(500);
  //chasis.frenar();
  //delay(1000);
  //chasis.frenar();
  //chasis.go_advance(50);

}
