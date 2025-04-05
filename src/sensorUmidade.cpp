#include "sensorUmidade.h"

SensorUmidade::SensorUmidade(int pino, unsigned long timeoutUs) {
  _pino = pino;
  _timeoutUs = timeoutUs;
}

unsigned long SensorUmidade::medir() {
  pinMode(_pino, INPUT_PULLUP);
  int contadorCiclos = 0;
  unsigned long tempoInicio = micros();
  unsigned long tempoAtual = tempoInicio;
  unsigned long tempoTimeout = tempoInicio;
  unsigned long tempo = 0;
  bool estadoAtual = digitalRead(_pino);
  bool estadoAnterior = estadoAtual;
  while (contadorCiclos <= 10) {
    tempoAtual = micros();
    estadoAtual = digitalRead(_pino);
    if ((tempoAtual - tempoTimeout) > _timeoutUs) return 0; // Timeout excedido
    if (estadoAtual && !estadoAnterior) { // bordo de subida
      if (!contadorCiclos) tempoInicio = tempoAtual; // primeiro bordo de subida
      contadorCiclos++;
      if (contadorCiclos > 10) break; // sai quando ele achar um bordo de subida depois do 10o. ciclo
    }
    estadoAnterior = estadoAtual;
  }
  return (tempoAtual - tempoInicio); // retorna o tempo de 10 ciclos, em microssegundos
}
