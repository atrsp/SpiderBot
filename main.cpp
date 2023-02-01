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

//distancia segura para desvio de obstaculo definido como 30cm
#define distanciaSegura 30

//Definindo posicoes iniciais de movimento dos servos
#define posIncial_FD_corpo 50
#define posInicial_FD_perna 135 

#define posInicial_TD_corpo 40
#define posInicial_TD_perna 100 

#define posInicial_FE_corpo 140
#define posInicial_FE_perna 100 

#define posInicial_TE_corpo 130
#define posInicial_TE_perna 70 

//cabeçalhos das funcoes utilizadas
void PosInicial();
void AndarReto();
void GirarHorario();
float LeDistancia();


void setup() {

  //Setup monitor serial
  Serial.begin(9600);

  //Setup dos servos:
  //Attachs - configuram os pinos para uso:
  FD_corpo.attach(pinFD_corpo);
  FD_perna.attach(pinFD_perna);
  
  TD_corpo.attach(pinTD_corpo);
  TD_perna.attach(pinTD_perna);

  FE_corpo.attach(pinFE_corpo);
  FE_perna.attach(pinFE_perna);

  TE_corpo.attach(pinTE_corpo);
  TE_perna.attach(pinTE_perna);

  delay(1000);
  PosInicial();
  delay(1000);

  //Setup do sensor ultrassonico:
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);
}


/*****************LOOP*****************/
void loop() {
  
  //Leitura da distancia:
  distancia = LeDistancia();
  Serial.println("Distancia = ");
  Serial.print(distancia);
  
  //Processa decisao de movimento:
  if (distancia <= distanciaSegura) {
    delay(1000);
    PosInicial();
    delay(500);
    GirarHorario();
    delay(500);
    PosInicial();
  }
  else {
    AndarReto();
  }

}
/*****************************************/


void PosInicial() {

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
  TE_perna.write(posInicial_TE_perna);
}

float LeDistancia() {

  digitalWrite(pinTrigger, LOW);
  delay(0.005);

  digitalWrite(pinTrigger, HIGH);
  delay(0.01);
  digitalWrite(pinTrigger, LOW);

  return (pulseIn(pinEcho, HIGH) * 0.017);
}

void AndarReto() {

  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta perna
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 20); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa perna para pos_inicial

  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta perna
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 30); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa perna para pos_inicial

  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta perna
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 20); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa perna para pos_inicial

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 30); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa perna para pos_inicial


  /***************************************************/

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa perna
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta perna para pos_inicial

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa perna
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 10); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta perna para pos_inicial

  //tras
  TE_perna.write(posInicial_TE_perna + 20); //abaixa perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna);//levanta perna para pos_inicial

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa perna
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta perna para pos_inicial

}


void GirarHorario() {
  //o movimento eh repetido 3 vezes

  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta perna
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 80); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa perna para pos_inicial

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 20); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta perna para pos_inicial

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 70); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa perna para pos_inicial

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa perna 
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta perna para pos_inicial


/*****************************************************/

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa perna 
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta perna para pos_inicial
  
  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 50); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa perna para pos_inicial
  
  //tras
  TE_perna.write(posInicial_TE_perna + 20); //abaixa perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna);//levanta perna para pos_inicial

  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta perna 
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 70); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa perna para pos_inicial


  /*-----------------------------------*/


  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta perna
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 80); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa perna para pos_inicial

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 20); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta perna para pos_inicial

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 70); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa perna para pos_inicial

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa perna 
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta perna para pos_inicial


/*****************************************************/

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa perna 
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta perna para pos_inicial
  
  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 50); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa perna para pos_inicial
  
  //tras
  TE_perna.write(posInicial_TE_perna + 20); //abaixa perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna);//abaixa perna para pos_inicial

  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta perna 
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 70); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa perna para pos_inicial


  /*-----------------------------------*/


  //frente
  FE_perna.write(posInicial_FE_perna - 30); //levanta perna 
  delay(150);
  FE_corpo.write(posInicial_FE_corpo - 80); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //abaixa perna para pos_inicial

  //tras
  TD_perna.write(posInicial_TD_perna + 25); //abaixa perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo - 20); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //levanta perna para pos_inicial

  //frente
  TE_perna.write(posInicial_TE_perna - 30); //levanta perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo - 70); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna); //abaixa perna pos_inicial

  //tras
  FD_perna.write(posInicial_FD_perna + 40); //abaixa perna 
  delay(150);
  FD_corpo.write(posIncial_FD_corpo - 40); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //levanta perna pos_inicial


/*****************************************************/

  //tras
  FE_perna.write(posInicial_FE_perna + 30); //abaixa perna
  delay(150);
  FE_corpo.write(posInicial_FE_corpo + 30); //move corpo
  delay(150);
  FE_perna.write(posInicial_FE_perna); //levanta perna pos_inicial
  
  //frente
  TD_perna.write(posInicial_TD_perna - 30); //levanta perna 
  delay(150);
  TD_corpo.write(posInicial_TD_corpo + 50); //move corpo
  delay(150);
  TD_perna.write(posInicial_TD_perna); //abaixa perna para pos_inicial
  
  //tras
  TE_perna.write(posInicial_TE_perna + 20); //abaixa perna
  delay(150);
  TE_corpo.write(posInicial_TE_corpo + 10); //move corpo
  delay(150);
  TE_perna.write(posInicial_TE_perna); //levanta perna para pos_inicial

  //frente
  FD_perna.write(posInicial_FD_perna - 30); //levanta perna
  delay(150);
  FD_corpo.write(posIncial_FD_corpo + 70); //move corpo
  delay(150);
  FD_perna.write(posInicial_FD_perna); //abaixa perna para pos_inicial
  
}