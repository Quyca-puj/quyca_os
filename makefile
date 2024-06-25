BOARD = esp8266:esp8266:nodemcuv2
SKETCH = quyca_os.ino
PORT = /dev/ttyUSB0

compile:
	arduino-cli compile --fqbn $(BOARD) $(SKETCH)

list:
	arduino-cli board list

upload:
	arduino-cli upload -p $(PORT) --fqbn $(BOARD) $(SKETCH)

monitor:
	arduino-cli monitor -p $(PORT) -c baudrate=115200

all: compile upload monitor

install-core:
	arduino-cli core update-index --additional-urls https://arduino.esp8266.com/stable/package_esp8266com_index.json
	arduino-cli core install 'esp8266:esp8266' --additional-urls https://arduino.esp8266.com/stable/package_esp8266com_index.json

install-deps:
	arduino-cli lib install 'Adafruit NeoPixel@1.11.0' QTRSensors@4.0.0 ArduinoQueue@1.2.5 AUnit@1.7.0

install: install-core install-deps
