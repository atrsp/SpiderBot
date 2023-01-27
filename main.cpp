//#include <Wire.h>
#include <Servo.h>

/*
#define pin_serv 3
Servo servo;

void setup() {
  servo.attach(pin_serv);
}

void loop() {
  servo.write(40);
  delay(200);
  servo.write(140);
  delay(200);
}
*/


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

#define posIncial_FD_corpo 50
#define posInicial_FD_perna 135

#define posInicial_TD_corpo 40
#define posInicial_TD_perna 100

#define posInicial_FE_corpo 140
#define posInicial_FE_perna 100

#define posInicial_TE_corpo 130
#define posInicial_TE_perna 70

void AndarReto();

void GirarHorario();

void setup() {

  //Setup monitor serial

  Serial.begin(9600);

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

  
  //Posicao inicial corpo:
  FD_corpo.write(posIncial_FD_corpo);
  delay(100);
  TD_corpo.write(posInicial_TD_corpo);
  delay(100);
  FE_corpo.write(posInicial_FE_corpo);
  delay(100);
  TE_corpo.write(posInicial_TE_corpo);

  delay(1000);

  //Posicao inicial perna
  FD_perna.write(posInicial_FD_perna);
  delay(100);
  TD_perna.write(posInicial_TD_perna);
  delay(100);
  FE_perna.write(posInicial_FE_perna);
  delay(100);
  //FE_perna.write(posInicial_FE_perna + 80);
  //delay(100);
  TE_perna.write(posInicial_TE_perna);

  delay(3000);

  //Setup do sensor ultrassonico:
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);
}

void loop() {

  /*
  //Leitura da distancia:
  distancia = LeDistancia();
  
  Serial.println("Distancia = ");
  Serial.print(distancia);
  
  //Processa decisao de movimento:
  if (distancia <= distanciaSegura) {
    GirarHorario();
  }
  else {
    AndarReto();
  }
  */

  AndarReto();
}

float LeDistancia() {

  digitalWrite(pinTrigger, LOW);
  //delayMicrosseconds(5);
  delay(0.005);

  digitalWrite(pinTrigger, HIGH);
  //delayMicrosseconds(10);
  delay(0.01);
  digitalWrite(pinTrigger, LOW);

  return (pulseIn(pinEcho, HIGH) * 0.017);
}

void AndarReto() {
  

  /*

  // andada funcional
  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta (-40)
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 20); //-20
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa pos_inicial

  //delay (250);
  
  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 20); //+20
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa pos_inicial

  //delay(250);

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 30); //-40
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa pos_inicial

  //delay(250);

  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 30); //+40
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa pos_inicial

  //delay(250);


/**************************************************************/
  /*

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //+40
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta pos_inicial

  //delay(250);

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //-50
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta pos_inicial

  //delay(250);

  //tras
  TE_perna.write(posInicial_TE_perna + 20);
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); // +10
  delay(150);
  TE_perna.write(posInicial_TE_perna);

  //delay(250);

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 10); //-30
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta pos_inicial

  //delay(250);
  */




  //teste 2 de andada

  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta (-40)
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 20); //-20
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa pos_inicial

  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 30); //+40
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa pos_inicial

  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 20); //+20
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa pos_inicial

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 30); //-40
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa pos_inicial


  /***************************************************/

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //+40
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta pos_inicial

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 10); //-30
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta pos_inicial

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //-50
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta pos_inicial

  //tras
  TE_perna.write(posInicial_TE_perna + 20);
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); // +10
  delay(150);
  TE_perna.write(posInicial_TE_perna);

}

void GirarHorario() {

}
