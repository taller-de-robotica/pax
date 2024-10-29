#include "ChasisPaco.hpp"


ChasisPaco chasis = ChasisPaco();


void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
//Serial.println(0);
Serial.begin(9600);
//Keyboard.begin();
chasis.init();
chasis.frenar();
}

void loop() {
  int vel = 70;



    char inChar  = 0;
    while(true){
      delay(500);
      inChar = 0;
      
      inChar  = Serial.read();
      Serial.print(inChar);
      if (inChar == '2'){
        chasis.go_back(vel);
        continue;
      } else if( inChar == '8') {
        chasis.go_advance(vel);
        continue;
      } else if( inChar == '5') {
        chasis.frenar();
        continue;
      }
        else if( inChar == '6') {
        chasis.clockwise(vel);
        continue;
      }else if( inChar == '4') {
        chasis.countclockwise(vel);
        continue;
      }else {
        //chasis.frenar();
      }
    

  }
  


      

  // put your main code here, to run repeatedly:
  //chasis.go_advance(50);
  //delay(500);
  //chasis.countclockwise(50);
  //chasis.clockwise(100);
  //delay(5000);
  //chasis.frenar();
  //chasis.go_back(50);
  //delay(500);
  //chasis.frenar();
  //delay(1000);
  //chasis.frenar();
  //chasis.go_advance(50);

}
