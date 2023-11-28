#include "calibration.hpp"

CalibrateQuyca calibrationQuyca;

CalibrateQuyca::CalibrateQuyca() {
  this->updating = false;

  this->qtr.setTypeRC();
  this->qtr.setSensorPins((const uint8_t[]){D1,D5,D0,D6},NUM_SENSORS);

  this->change_qtr.setTypeRC();
  this->change_qtr.setSensorPins((const uint8_t[]){D1,D5,D0,D6},NUM_SENSORS);
}

void CalibrateQuyca::readCalibration() {
  this->updating = true;
  this->change_qtr.calibrate();
}

void CalibrateQuyca::updateCalibration() {
  if (this->updating) {
    this->qtr.calibrationOn = this->change_qtr.calibrationOn;
    this->qtr.calibrationOff = this->change_qtr.calibrationOff;

    this->updating = false;
  }

  this->change_qtr.resetCalibration();
}

// WRAPPER //////////////////////////////////////////////////////////////////////////////

void CalibrateQuyca::calibrate() {
  this->qtr.calibrate();
}

uint16_t CalibrateQuyca::readLineBlack(uint16_t* SS) {
  return this->qtr.readLineBlack(SS);
}

void CalibrateQuyca::resetCalibration() {
  this->qtr.resetCalibration();
}

void CalibrateQuyca::readValues() {
  this->qtr.read(sensorValues);
}
