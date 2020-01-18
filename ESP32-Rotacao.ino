// Controle de Motores de Passo Baseado em Driver a4988 em Experimento RPS - Motor do estágio de rotação
// Laboratório de Sensores e Instrumentação - Grupo de Fotônica - UFPE
// Gabriel de Freitas
// OBS: 6.163° / revolução. 1 passo rotaciona 0,061°
//---------------------------------------------------
#include <math.h>
const int stepPin = 16;
const int dirPin = 19;
const int MS1 = 9;
const int MS2 = 10;
const int MS3 = 11;
int stepsPerRevolution=100;
float pi = 3.14159;
// Definição de parâmetros do prisma
float alpha = pi/4;             //Ângulo em rad
float beta = pi/4;
float gama = pi/4;
float w = 0;                    //Posição atual do feixe na face superior do prisma, inicialmente 0
float a, b, c;                  //Dimensões do prisma
//Fim da definição de parâmetros do prisma

void setup() {
Serial.begin(9600);
}

void loop() {
  float theta = 0;                //Ângulo a ser rotacionado [Receber do Usuário]
  if (theta<0){                   //Verifica para qual lado deve rotacionar
    digitalWrite(dirPin, HIGH);   //Rotaciona para região negativa(Esquerda)
  }
  else{
    digitalWrite(dirPin, LOW);    //Rotaciona para região positiva (Direita)
  }
  if(theta<0.003)
  {
    digitalWrite(MS1,HIGH);
    digitalWrite(MS2,HIGH);
    digitalWrite(MS3,HIGH);
  }
  if(theta<0,007)
  {
    digitalWrite(MS1,HIGH);
    digitalWrite(MS2,HIGH);
    digitalWrite(MS3,LOW);
  }
  if(theta<0,015)
  {
    digitalWrite(MS1,LOW);
    digitalWrite(MS2,HIGH);
    digitalWrite(MS3,LOW); 
  }
  if(theta<0,03)
  {
    digitalWrite(MS1,HIGH);
    digitalWrite(MS2,LOW);
    digitalWrite(MS3,LOW);
  }
  else
  {
    digitalWrite(MS1, LOW);
    digitalWrite(MS2, LOW);
    digitalWrite(MS3, LOW);
  }
 
  for(int i = 0; i < (theta/0,061); i++)    //Dá o número de passos relacionado ao ângulo a ser rotacionado - Atenção para a imprecisão nesse for
  {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  
}