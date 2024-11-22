/*
 * Referencias:
 * https://programarfacil.com/blog/arduino-blog/comunicacion-i2c-con-arduino/
 */
// La librería Wire permite usar I2C
#include <Wire.h>

// Encabezados para Paquito
#include "ChasisPaquito.hpp"
ChasisPaquito chasis = ChasisPaquito(); 

//encabezados para Paco
//#include "ChasisPaco.hpp"
//ChasisPaco chasis = ChasisPaco();



//const int LED_PIN = 13;
const int SLAVE_ADDRESS = 0x8; // Hexadecimal entre 8 y 127
char buf[100];
int vel = 70;


const int PIN_LED = 13; 
const int PIN_BUZZER = 4;


void whistle(int baseFreq, bool up, int timesFirst, int timesSecond){
}


void babble() {
  int K = 2000; 
  for (int i= 0; i <= random(3, 9); i++){
     digitalWrite(PIN_LED, HIGH); 
     tone(PIN_BUZZER, K + random(-1700, 0)); 
     delay (random(70, 170)); 
     digitalWrite(PIN_LED, LOW); 
     noTone (PIN_BUZZER); 
     delay(random(0, 30));
  }
}



void setup() {
  Serial.begin(9600); 
  pinMode(PIN_BUZZER, OUTPUT); 
  pinMode(PIN_LED, OUTPUT); 
  randomSeed(analogRead(0));
  Serial.begin(9600);

  // Se sube al camión I2C como esclavo con la dirección indicada
  Wire.begin(SLAVE_ADDRESS);

  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);

  // Llama requestEvent cuando se soliciten datos
  Wire.onRequest(requestEvent);

  chasis.init();

  // Setup pin 13 as output and turn LED off
  //pinMode(LED_PIN, OUTPUT);
  //digitalWrite(LED_PIN, LOW);
}

// Función que se ejecuta cuando el maestro va a enviar información.
void receiveEvent(int howMany) {
  sprintf(buf, "Received number %d:\n", howMany);
  Serial.print(buf);
  int ava;
  while (ava = Wire.available()) {
    unsigned int c = Wire.read(); // receive byte as a character
    //sprintf(buf, "Wire read %d: %d=%c\n", ava, c, c);

    unsigned int inChar  = c;
      //Serial.print(inChar);
      if (inChar == 255){
        chasis.frenar();
        continue;
      } else if( inChar == 15) {
        chasis.go_advance(vel);
        continue;
      } else if( inChar == 240) {
        chasis.go_back(vel);
        continue;
      }else if( inChar == 165) {
        chasis.clockwise(vel);
        continue;
      }else if( inChar == 90) {
        chasis.countclockwise(vel);
        continue;
      }else if (inchar == 150) {
        chasis.right_turn(vel);
        continue;
      }else if (inchar == 105) {
        chasis.left_turn(vel);
        continue;
      }else if (inchar == 5) {
        chasis.right_shift(vel);
        continue;
      }else if (inchar == 10) {
        chasis.left_shift(vel);
        continue;
      }else if (inchar == 80) {
        chasis.right_back(vel);
        continue;
      }else if (inchar == 160) {
        chasis.left_back(vel);
        continue;
      }else{
        babble();
      }

    Serial.print(buf);
  }
}

// Función que se ejecuta cuando el maestro solicita información.
void requestEvent() {

}

void loop() {
  babble();
  noTone(PIN_BUZZER);
  delay(random(2000,4000));
}

