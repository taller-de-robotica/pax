#include "RuedaPaquito.hpp"

// Delantera Derecha
#define SPD_DD  9
#define DIR_DD1 27
#define DIR_DD2 26

// Delantera Izquierda
#define SPD_DI 10
#define DIR_DI1 29
#define DIR_DI2 28

// Trasero Derecho
#define SPD_TD  11
#define DIR_TD1 23
#define DIR_TD2 22

// Trasera Izquierda
#define SPD_TI  12
#define DIR_TI1 25
#define DIR_TI2 24


class ChasisPaquito
{
private:
       RuedaPaquito RDD, RDI, RTD, RTI; 
public:
    ChasisPaquito() : 
      RDD(SPD_DD,DIR_DD1,DIR_DD2),
      RDI(SPD_DI,DIR_DI1,DIR_DI2),
      RTD(SPD_TD,DIR_TD1,DIR_TD2),
      RTI(SPD_TI,DIR_TI1,DIR_TI2)
      {
      }
    
    void init()
    {
        RDI.init();
        RDD.init();
        RTI.init();
        RTD.init();
    }

    void testRueda(){
        RTI.avanzar(70);
        delay(1000);
        RTI.frenar();
        delay(1000);
    }

    void right_shift(int speed) {
        RDI.retroceder(speed); 
        RTI.avanzar(speed); 
        RDD.avanzar(speed);
        RTD.retroceder(speed);
    }

    void left_shift(int speed) {
        RDI.avanzar(speed);
        RTI.retroceder(speed);
        RDD.retroceder(speed);
        RTD.avanzar(speed);
    }

    void go_advance(int speed) {
        RTI.avanzar(speed);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.avanzar(speed);
    }

    void go_back(int speed) {
        RTI.retroceder(speed);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.retroceder(speed);
    }

    void left_turn(int speed) { 
        RTI.avanzar(0);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.avanzar(0);
    }

    void right_turn(int speed) {
        RTI.avanzar(speed);
        RTD.retroceder(0);
        RDD.retroceder(0);
        RDI.avanzar(speed);
    }

    void left_back(int speed) {
        RTI.avanzar(0);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.avanzar(0);
    }

    void right_back(int speed) {
        RTI.retroceder(speed);
        RTD.avanzar(0);
        RDD.avanzar(0);
        RDI.retroceder(speed);
    }

    void clockwise(int speed) {
        RTI.avanzar(speed);
        RTD.retroceder(speed);
        RDD.retroceder(speed);
        RDI.avanzar(speed);
    }

    void countclockwise(int speed) {
        RTI.retroceder(speed);
        RTD.avanzar(speed);
        RDD.avanzar(speed);
        RDI.retroceder(speed);
    }

    void frenar() {
        RTI.frenar();
        RTD.frenar();
        RDD.frenar();
        RDI.frenar();
    }
    void forward_right(int speed) {
        RDD.avanzar(speed);
        RTI.avanzar(speed);
    }
    void forward_left(int speed) {
        RDI.avanzar(speed);
        RTD.avanzar(speed);
    }
    void backward_right(int speed) {
        RDI.retroceder(speed);
        RTD.retroceder(speed);
    }
    void backward_left(int speed) {
        RDD.retroceder(speed);
        RTI.retroceder(speed);
    }
};

