#include "RuedaPaquito.hpp"

// Delantera Derecha
#define SPD_DD  9
#define DIR_DD1 26
#define DIR_DD2 27


// Delantera Izquierda
#define SPD_DI 10
#define DIR_DI1 28
#define DIR_DI2 29

// Trasero Derecho
#define SPD_TD  11
#define DIR_TD1 22
#define DIR_TD2 23

// Trasera Izquierda
#define SPD_TI  12
#define DIR_TI1 24
#define DIR_TI2 25


class Chasis
{
private:
       RuedaPaquito *RDD, *RDI, *RTD, *RTI; 
public:
    Chasis(){
//#define PAQUITO
//#ifdef PAQUITO
            RuedaPaquito RDDP(SPD_DD,DIR_DD1,DIR_DD2);
            RuedaPaquito RDIP(SPD_DI,DIR_DI1,DIR_DI2);
            RuedaPaquito RTDP(SPD_TD,DIR_TD1,DIR_TD2);
            RuedaPaquito RTIP(SPD_TI,DIR_TI1,DIR_TI2);
            RDD = &RDDP;
            RDI = &RDIP;
            RTD = &RTDP;
            RTI = &RTIP;
//#endif
    }

    void init()
    {
        RDD->init();
        RDI->init();
        RTD->init();
        RTI->init();
    }

    void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck) {
        RDI->avanzar(speed_fl_fwd); 
        RTI->retroceder(speed_rl_bck); 
        RDD->retroceder(speed_fr_bck);
        RTD->avanzar(speed_rr_fwd);
    }

    void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd) {
        RDI->retroceder(speed_fl_bck);
        RTI->avanzar(speed_rl_fwd);
        RDD->avanzar(speed_fr_fwd);
        RTD->retroceder(speed_rr_bck);
    }

    void go_advance(int speed) {
        RTI->avanzar(speed);
        RTD->avanzar(speed);
        RDD->avanzar(speed);
        RDI->avanzar(speed);
    }

    void go_back(int speed) {
        RTI->retroceder(speed);
        RTD->retroceder(speed);
        RDD->retroceder(speed);
        RDI->retroceder(speed);
    }

    void left_turn(int speed) { 
        RTI->avanzar(0);
        RTD->avanzar(speed);
        RDD->avanzar(speed);
        RDI->avanzar(0);
    }

    void right_turn(int speed) {
        RTI->avanzar(speed);
        RTD->retroceder(0);
        RDD->retroceder(0);
        RDI->avanzar(speed);
    }

    void left_back(int speed) {
        RTI->avanzar(0);
        RTD->retroceder(speed);
        RDD->retroceder(speed);
        RDI->avanzar(0);
    }

    void right_back(int speed) {
        RTI->retroceder(speed);
        RTD->avanzar(0);
        RDD->avanzar(0);
        RDI->retroceder(speed);
    }

    void clockwise(int speed) {
        RTI->avanzar(speed);
        RTD->retroceder(speed);
        RDD->retroceder(speed);
        RDI->avanzar(speed);
    }

    void countclockwise(int speed) {
        RTI->retroceder(speed);
        RTD->avanzar(speed);
        RDD->avanzar(speed);
        RDI->retroceder(speed);
    }

    void frenar() {
        RTI->frenar();
        RTD->frenar();
        RDD->frenar();
        RDI->frenar();
    }
};

Chasis chasis = Chasis();

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.println(0);
chasis.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  chasis.go_advance(70);
  delay(500);
  chasis.frenar();
}
