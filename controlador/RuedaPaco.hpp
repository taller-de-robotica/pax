
// Implementación de una rueda específica
class RuedaPaco{
private:
    int speedPWM1, speedPWM2, dirPin1, dirPin2;
public:
    RuedaPaco(int speedPWM1, int speedPWM2, int dirPin1, int dirPin2)
    {
        this->speedPWM1 = speedPWM1;
        this->speedPWM2 = speedPWM2;
        this->dirPin1 = dirPin1;
        this->dirPin2 = dirPin2;
        // Configuración de pines como salida
    }

    void init()
    {
        //Serial.println(1);
        pinMode(this->speedPWM1, OUTPUT);
        pinMode(this->speedPWM2, OUTPUT);
        pinMode(this->dirPin1, OUTPUT);
        pinMode(this->dirPin2, OUTPUT);
        analogWrite(this->speedPWM1, 0);
        analogWrite(this->speedPWM2, 0);
        digitalWrite(this->dirPin1, LOW);
        digitalWrite(this->dirPin2, LOW);
    }

    void avanzar(int velocidad){
        analogWrite(this->speedPWM1, velocidad);
        analogWrite(this->speedPWM2, 0);
        digitalWrite(this->dirPin1, HIGH);
        digitalWrite(this->dirPin2, HIGH);
    }

    void retroceder(int velocidad) {
        analogWrite(this->speedPWM1, 0);
        analogWrite(this->speedPWM2, velocidad);
        digitalWrite(this->dirPin1, HIGH);
        digitalWrite(this->dirPin2, HIGH);
    }

    void frenar() {
        analogWrite(this->speedPWM1, 0);
        analogWrite(this->speedPWM2, 0);
        digitalWrite(this->dirPin1, HIGH);
        digitalWrite(this->dirPin2, HIGH);
    }
};
