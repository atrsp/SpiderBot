//#include <Wire.h>
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

  

  //Posicao inicial:
  FD_corpo.write(50);
  delay(100);
  TD_corpo.write(40);
  delay(100);
  FE_corpo.write(140);
  delay(100);
  TE_corpo.write(130);
  delay(100);

  delay(1000);

  //servos da perna nao podem ir nos extremos
  FD_perna.write(120);
  delay(100);
  TD_perna.write(100);
  delay(100);
  //TD_perna.write(170);
  //delay(100);
  FE_perna.write(40);
  delay(100);
  //TE_perna.write(60);
  TE_perna.write(70);
  //delay(1000);

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

  
    // Andada Aranha
  //FE_corpo.write(70); //ok
  //FE_perna.write(50);

  
  //TD_corpo.write(40);
  /*
  //TD_perna.write(50);
  delay(300);
  FD_corpo.write(0);
  //FD_perna.write(50);
  TE_corpo.write(10);
  //TE_perna.write(50);
  
  delay(1000);
  FE_corpo.write(180);
  TD_corpo.write(180); //ok
  delay(300);
  
  FD_corpo.write(100); //ok
  TE_corpo.write(110);
  delay(1000);
 */


/*********************************************************************/
// a parte que vai para tras tem q se mover menos do q a q vai para frente.

/*
  //Andada Caranguejo
  FE_corpo.write(100); //ok
  TE_corpo.write(50); //ok
  delay(1000);
  FD_corpo.write(0);
  TD_corpo.write(20);
  delay(1000);
  

  FE_corpo.write(180);
  TE_corpo.write(130);
  delay(1000);
  
  FD_corpo.write(80); //ok
  TD_corpo.write(120); //ok
  
  delay(1000);
  
  */
  
  //frente
  FE_corpo.write(80);
  delay (1000);
  //frente
  FD_corpo.write(100);

  delay(1000);
  //frente
  TE_corpo.write(50);
  delay(1000);
  //frente
  TD_corpo.write(120);

  delay(1000);

  //tras
  FE_perna.write(80);
  delay(250);
  FE_corpo.write(180);
  delay(250);
  FE_perna.write(40);


  delay(1000);
  //tras

  FD_perna.write(150);
  delay(250);
  FD_corpo.write(0);
  delay(250);
  FD_perna.write(120);

  delay(1000);

  //tras
  delay(250);
  TE_corpo.write(130);
  delay(250);

  delay(1000);

  //tras
  TD_perna.write(125);
  delay(250);
  TD_corpo.write(20);
  delay(250);
  TD_perna.write(100);
  

  delay(1000);
  
}

void GirarHorario() {

}