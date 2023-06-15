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
