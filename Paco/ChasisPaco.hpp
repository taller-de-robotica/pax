#include "RuedaPaco.hpp"

// Delantera Derecha
// SPD_DD1 = PWM_Adelante
// SPD_DD2 = PWM_Atras
#define SPD_DD1  10
#define SPD_DD2  9
#define DIR_DD1 22
#define DIR_DD2 23

// Delantera Izquierda
#define SPD_DI1 3
#define SPD_DI2 4
#define DIR_DI1 34
#define DIR_DI2 35

// Trasero Derecho
#define SPD_TD1  6
#define SPD_TD2  5
#define DIR_TD1 27
#define DIR_TD2 26

// Trasera Izquierda
#define SPD_TI1  8
#define SPD_TI2  7
#define DIR_TI1 31
#define DIR_TI2 30


class ChasisPaco
{
private:
       RuedaPaco RDD, RDI, RTD, RTI; 
public:
    ChasisPaco() : 
      RDD(SPD_DD1,SPD_DD2,DIR_DD1,DIR_DD2),
      RDI(SPD_DI1,SPD_DI2,DIR_DI1,DIR_DI2),
      RTD(SPD_TD1,SPD_TD2,DIR_TD1,DIR_TD2),
      RTI(SPD_TI1,SPD_TI2,DIR_TI1,DIR_TI2)
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
        RTD.avanzar(70);
        delay(1000);
        RTD.frenar();
        delay(1000);
    }

    void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck) {
        RDI.avanzar(speed_fl_fwd); 
        RTI.retroceder(speed_rl_bck); 
        RDD.retroceder(speed_fr_bck);
        RTD.avanzar(speed_rr_fwd);
    }

    void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd) {
        RDI.retroceder(speed_fl_bck);
        RTI.avanzar(speed_rl_fwd);
        RDD.avanzar(speed_fr_fwd);
        RTD.retroceder(speed_rr_bck);
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
};

