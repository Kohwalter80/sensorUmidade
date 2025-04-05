#include "sensorUmidade.h"

SensorUmidade sensor(2); // Pino D4 (GPIO2), timeout padrão (1ms)
SensorUmidade sensor2(14, 2000000); // pino D5 (GPIO14), timeout 2000 ms = 2 segundos

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long tempoTotal = sensor.medir();
  unsigned long tempoTotal2 = sensor2.medir();

  if (tempoTotal == 0) {
    Serial.println("Sensor 1 (D4) Timeout!");
  } else {
    Serial.print("Sensor 1 (D4) Periodo de 10 ciclos: ");
    Serial.print(tempoTotal);
    Serial.println(" us");

    Serial.print("Sensor 1 (D4) Periodo médio por ciclo: ");
    Serial.print(tempoTotal / 10.0);
    Serial.println(" us");

    Serial.print("Sensor 1 (D4) Frequência aproximada: ");
    Serial.print(1000000.0 / (tempoTotal / 10.0));
    Serial.println(" Hz");
  }

  if (tempoTotal2 == 0) {
    Serial.println("Sensor 2 (D5) Timeout!");
  } else {
    Serial.print("Sensor 2 (D5) Periodo de 10 ciclos: ");
    Serial.print(tempoTotal2);
    Serial.println(" us");

    Serial.print("Sensor 2 (D5) Periodo médio por ciclo: ");
    Serial.print(tempoTotal2 / 10.0);
    Serial.println(" us");

    Serial.print("Sensor 2 (D5) Frequência aproximada: ");
    Serial.print(1000000.0 / (tempoTotal2 / 10.0));
    Serial.println(" Hz");
  }
  delay(5000); // Aguarda 5 segundos
}
