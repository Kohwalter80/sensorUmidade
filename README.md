# sensorUmidade
Biblioteca para ser usada com o Arduino IDE para sensor de umidade capacitivo V1.2 modificado.

Para realizar a modificação no sensor de umidade capacitivo V1.2, realizar os sequintes passos:
1- Remover R2, T4 e C4.
2- Conectar os terminais de T4 em R2. O da direita de um no da direita do outro, e o da esquerda de um no da esquerda do outro.
3- Opcional: se retirar R3, a saída se torna uma saída open collector.

Seco, sem água, a frequência de oscilação é em torno de 55 kHz. Imerso em água, a frequência é de cerca de 30 kHz. Isso vai dar um tempo, em microssegundos, para 10 ciclos entre 333 e 182, mais ou menos.
O circuito, alimentado com 5 V, consome aproximadamente 1,4 mA.
