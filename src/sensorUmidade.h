#ifndef sensorUmidade_h
#define sensorUmidade_h

#include "Arduino.h"

class SensorUmidade {
public:
  SensorUmidade(int pino, unsigned long timeoutUs = 1000);
  unsigned long medir();

private:
  int _pino;
  unsigned long _timeoutUs;
};

#endif
