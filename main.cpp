//#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>

//Iniciando servos:
// F: Frente; T: Tras; D: Direita; E: Esquerda;

Servo FD_corpo;
Servo FD_perna;
#define pinFD_corpo 13
#define pinFD_perna 12

Servo TD_corpo;
Servo TD_perna;
#define pinTD_corpo 11
#define pinTD_perna 10

Servo FE_corpo;
Servo FE_perna;
#define pinFE_corpo 9
#define pinFE_perna 8

Servo TE_corpo;
Servo TE_perna;
#define pinTE_corpo 7
#define pinTE_perna 6

//Iniciando sensor ultrassonico:
#define pinEcho 5
#define pinTrigger 4

float distancia;

#define distanciaSegura 20

void setup() {

  //Setup dos servos:
  //Attachs - seta os pinos:
  FD_corpo.attach(pinFD_corpo);
  FD_perna.attach(pinFD_perna);
  
  TD_corpo.attach(pinTD_corpo);
  TD_perna.attach(pinTD_perna);

  FE_corpo.attach(pinFE_corpo);
  FE_perna.attach(pinFE_perna);

  TE_corpo.attach(pinTE_corpo);
  TE_perna.attach(pinTE_perna);

  //Posicao inicial:
  FD_corpo.write(0);
  FD_perna.write(0);

  TD_corpo.write(0);
  TD_perna.write(0);

  FE_corpo.write(0);
  FE_perna.write(0);

  TE_corpo.write(0);
  TE_perna.write(0);

  //Setup do sensor ultrassonico:
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);
}

void loop() {

  //Leitura da distancia:
  distancia = LeDistancia();

  //Processa decisao de movimento:
  if (distancia <= distanciaSegura) {

    GirarHorario();
  }
  else {

    AndarReto();
  }
}

float LeDistancia() {

  digitalWrite(pinTrigger, LOW);
  delayMicrosseconds(5);

  digitalWrite(pinTrigger, HIGH);
  delayMicrosseconds(10);
  digitalWrite(pinTrigger, LOW);

  return (pulseIn(pinEcho, HIGH) * 0.017);
}

void AndarReto();

void GirarHorario();
