
# QUYCA_OS

## WIFI arduino

Antes de intentar compilar el proyecto, es necesario crear el archivo `wifi_config.h`.
En este archivo se deberán contener los siguientes valores. Ambos deben ser strings.

    #define WIFI_SSID "ssid_red"
    #define WIFI_PASS "pass_red"

## Instalar board para el nodemcu
https://www.instructables.com/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/

instalar controlador 'esp8266'

## dependencias adicionales
- QTRSensors
- Adafruit NeoPixel
- ArduinoQueue


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
