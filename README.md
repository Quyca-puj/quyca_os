
# QUYCA_OS

## WIFI arduino

Antes de intentar compilar el proyecto, es necesario crear el archivo `wifi_config.h`.
En este archivo se deberán contener los siguientes valores. Ambos deben ser strings.

    #define WIFI_SSID "ssid_red"
    #define WIFI_PASS "pass_red"

## Instalar board para el nodemcu
instalar controlador 'esp8266'

### IDE
https://arduino.github.io/arduino-cli/1.0/getting-started/#adding-3rd-party-cores


### CLI
https://www.instructables.com/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/


## dependencias adicionales
- QTRSensors
- Adafruit NeoPixel
- ArduinoQueue
- AUnit

Pueden ser instaladas a traves del IDE de arduino o con el siguiente comando:  

    make install

## Linux 
En caso de estar usando linux para el desarrollo  

https://docs.platformio.org/en/latest/core/installation/udev-rules.html#platformio-udev-rules

## arduino-cli
https://arduino.github.io/arduino-cli/0.33/getting-started/  

esto también quedó en un makefile  
Para encontrar la tarjeta conectada  

    arduino-cli board list

Compilar  

    arduino-cli compile --fqbn esp8266:esp8266:nodemcuv2 quyca_os.ino

Para cargar el programa al arduino será algo similar a lo siguiente. PORT se encuentra con `board list`.  

    arduino-cli upload -p <PORT> --fqbn esp8266:esp8266:nodemcuv2 quyca_os.ino

# comandos

los comandos recibidos deben estar en el siguiente formato:  

    <alias> <comando> <parametros>

## alias
Sirve para diferenciar entre robots. No se usa.

## comando
Actividad que será realizada por el robot.

### Basicos
- "stop_all"
- "stop_mvt"
- "calibration"
- "connect"

### Movimiento
- "forward"
- "left"
- "right"
- "t_forward"
- "t_reverse"
- "t_left"
- "t_right"
- "roll"
- "reverse_roll"

### Emociones
- "very_happy"
- "happy"
- "neutral"
- "sad"
- "very_sad"
- "angry"
- "sick"
- "surprised"
- "off"

### Config
- "cfg_offset_der"
- "cfg_offset_izq"

## Pruebas

Una forma rápida para hacer pruebas es utilizar `netcat`.  

    nc <ip> 6000

el alias siempre es `morado`.  

    morado forward
    morado calibration
    morado cfg_offset_der 50
