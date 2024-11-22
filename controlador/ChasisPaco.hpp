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

