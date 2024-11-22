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

    void right_shift(int speed) {
        RDD.retroceder(speed);
        RDI.avanzar(speed); 
        RTD.avanzar(speed);
        RTI.retroceder(speed); 
    }

    void left_shift(int speed) {
        RDD.avanzar(speed);
        RDI.retroceder(speed);
        RTD.retroceder(speed);
        RTI.avanzar(speed);
    }

    void left_turn(int speed) { 
        RDD.avanzar(speed);
        RDI.avanzar(0);
        RTD.avanzar(speed);
        RTI.avanzar(0);
    }

    void right_turn(int speed) {
        RDD.retroceder(0);
        RDI.avanzar(speed);
        RTD.retroceder(0);
        RTI.avanzar(speed);
    }

    void left_back(int speed) {
        RDD.retroceder(speed);
        RDI.avanzar(0);
        RTD.retroceder(speed);
        RTI.avanzar(0);
    }

    void right_back(int speed) {
        RDD.avanzar(0);
        RDI.retroceder(speed);
        RTD.avanzar(0);
        RTI.retroceder(speed);
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

	void testRuedaDI(int vel) { // Rueda Delantera Izquierda
	    RDI.avanzar(vel);
	    delay(1000);
	    RDI.frenar();
	    delay(1000);
	}

	void testRuedaDD(int vel) { // Rueda Delantera Derecha
	    RDD.avanzar(vel);
	    delay(1000);
	    RDD.frenar();
	    delay(1000);
	}

	void testRuedaTI(int vel) { // Rueda Trasera Izquierda
	    RTI.avanzar(vel);
	    delay(1000);
	    RTI.frenar();
	    delay(1000);
	}

	void testRuedaTD(int vel) { // Rueda Trasera Derecha
	    RTD.avanzar(vel);
	    delay(1000);
	    RTD.frenar();
	    delay(1000);
	}
	
	void testRuedas(int vel) {
	    Serial.println("Probando Rueda Delantera Izquierda...");
	    testRuedaDI(vel);

	    Serial.println("Probando Rueda Delantera Derecha...");
	    testRuedaDD(vel);

	    Serial.println("Probando Rueda Trasera Izquierda...");
	    testRuedaTI(vel);

	    Serial.println("Probando Rueda Trasera Derecha...");
	    testRuedaTD(vel);

	    Serial.println("Pruebas completadas.");
	}

};

