#ifndef CALIBRATION_HPP_
#define CALIBRATION_HPP_

#include <QTRSensors.h>

//Define sensor Motor

#define D5 14 //Frente Derecho
#define D6 12 // Espalda Derecho
#define D1 5  //Frente Izquierdo
#define D0 16 //Espalda Izquierdo

#define NUM_SENSORS   4

class CalibrateQuyca {

  QTRSensors qtr;
  // esta copia es usada para actualizar la calibracion
  QTRSensors change_qtr;

  bool updating;

public:
  uint16_t sensorValues[NUM_SENSORS];

  CalibrateQuyca();

  // genera una nueva version
  void readCalibration();
  // reemplaza la version vieja por la nueva
  void updateCalibration();

  // wrapper

  void calibrate();
  uint16_t readLineBlack(uint16_t* SS);
  void readValues();
  void resetCalibration();

} ;

extern CalibrateQuyca calibrationQuyca;

#endif
