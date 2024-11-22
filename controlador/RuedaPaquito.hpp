
// Implementación de una rueda específica
class RuedaPaquito {
private:
    int speedPWM, dirPin1, dirPin2;
public:
    RuedaPaquito(int speedPWM, int dirPin1, int dirPin2)
    {
        this->speedPWM = speedPWM;
        this->dirPin1 = dirPin1;
        this->dirPin2 = dirPin2;
        // Configuración de pines como salida
    }

    void init()
    {
        //Serial.println(1);
        pinMode(this->speedPWM, OUTPUT);
        pinMode(this->dirPin1, OUTPUT);
        pinMode(this->dirPin2, OUTPUT);
        analogWrite(this->speedPWM, 0);
        digitalWrite(this->dirPin1, LOW);
        digitalWrite(this->dirPin2, LOW);
    }

    void avanzar(int velocidad){
        analogWrite(this->speedPWM, velocidad);
        digitalWrite(this->dirPin1, HIGH);
        digitalWrite(this->dirPin2, LOW);
    }

    void retroceder(int velocidad) {
        analogWrite(this->speedPWM, velocidad);
        digitalWrite(this->dirPin1, LOW);
        digitalWrite(this->dirPin2, HIGH);
    }

    void frenar() {
        analogWrite(this->speedPWM, 0);
    }
};
