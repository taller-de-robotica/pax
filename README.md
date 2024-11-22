# pax
OOP para pacos

# Control de Robots Miniatura: Paco y Paquito

Este repositorio contiene el código para controlar dos robots miniatura, Paco y Paquito, a través de una interfaz web. El sistema utiliza una combinación de Arduino, Python y comunicación I2C para enviar comandos de movimiento a los robots.

## Arquitectura del Sistema

El sistema se divide en dos componentes principales:

1. **Firmware Arduino (controlador):**  Controla los motores de los robots y recibe comandos a través de I2C.
2. **Aplicación Python (tcp-i2c):** Recibe comandos de movimiento a través de una interfaz web y los transmite al Arduino mediante I2C.

## Funcionamiento

1. **Interfaz Web:** La aplicación Python ejecuta un servidor web que muestra una página con una imagen de la webcam. Esta página también acepta comandos POST a la ruta `/command/` con los siguientes comandos de movimiento:

    * `stop`
    * `forward`
    * `backward`
    * `clockwise`
    * `countclockwise`
    * `right`
    * `left`
    * `fwd_right`
    * `fwd_left`
    * `bkwd_right`
    * `bkwd_left`

2. **Comunicación I2C:** Al recibir un comando, la aplicación Python lo traduce a un byte específico y lo envía al Arduino a través de I2C. La codificación de los comandos se detalla más adelante.

3. **Control del Robot:** El Arduino recibe el byte de comando y lo utiliza para controlar los motores de Paco o Paquito. El firmware Arduino contiene clases específicas para cada robot (`ChasisPaco` y `ChasisPaquito`) que abstraen el control de los motores individuales.

## Codificación de Comandos I2C

Los comandos de movimiento se codifican en un byte utilizando el siguiente esquema:

```
0b-bbbbffff
```

Donde:

* `bbbb`: Representa las ruedas que se mueven hacia atrás (1 = activo, 0 = inactivo).
* `ffff`: Representa las ruedas que se mueven hacia adelante (1 = activo, 0 = inactivo).

La correspondencia entre comandos y bytes es la siguiente:

```python
STOP =             0b11111111 # 255
FORWARD =          0b00001111 #  15
BACKWARD =         0b11110000 # 240
CLOCKWISE =        0b10100101 # 165
COUNTERCLOCKWISE = 0b01011010 #  90
RIGHT =            0b10010110 # 150
LEFT =             0b01101001 # 105
FORWARD_RIGHT =    0b00000101 # 5
FORWARD_LEFT =     0b00001010 # 10
BACKWARD_RIGHT =   0b01010000 # 80
BACKWARD_LEFT =    0b10100000 # 160
```

Si un bit está activo en ambas mitades del byte para la misma rueda, el resultado es una contradicción y se interpreta como `STOP`.

## Instrucciones de Uso

### Arduino

1. Abrir la carpeta `controlador` en el Arduino IDE.
2. Abrir el archivo `pax-control.ino`.
3. Descomentar la línea correspondiente a la instancia de `ChasisPaco` o `ChasisPaquito` según el robot que se quiera controlar. Asegurarse de que el header correspondiente esté incluido.
4. Compilar y cargar el código al Arduino conectado por USB.

### Raspberry Pi / Laptop

1. Instalar las librerías necesarias:
   ```bash
   pip3 install numpy opencv-contrib-python imutils smbus2
   ```
2. Ejecutar el archivo `webcami2c.py` en la Raspberry Pi o laptop.
3. Acceder a la interfaz web a través de un navegador en la dirección `http://<ip_raspberry>:8000`.
4. Enviar comandos POST a la ruta `/command/` para controlar el robot. Por ejemplo:

   ```bash
   curl -X POST -d "forward" http://<ip_raspberry>:8000/command/
   ```

## Estructura del Repositorio

```
├── controlador
│   ├── ChasisPaco.hpp
│   ├── ChasisPaquito.hpp
│   ├── pax-control.ino
│   ├── RuedaPaco.hpp
│   └── RuedaPaquito.hpp
├── LICENSE
├── README.md
└── tcp-i2c
    └── webcami2c.py
```

## Detalles Adicionales

* El robot emite un sonido ("babble") cuando recibe un comando no válido.
* La velocidad del robot se controla mediante la variable `vel` en el archivo `pax-control.ino`.
* El archivo `webcami2c.py` transmite video desde la webcam. Se puede adaptar para usar una cámara conectada a la Raspberry Pi si se define `IN_RASPBERRY = True`.

## Licencia
This project is licensed under the Apache License, Version 2.0. See the `LICENSE` file for details.

You can also find the license text at [http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)