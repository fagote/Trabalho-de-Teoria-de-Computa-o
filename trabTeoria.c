// ALUNO: Leonardo G. Fagote
// RA: 2152304
// DISCIPLINA: Teoria de Computação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

typedef struct{
  char u[TAM];
  char v[TAM];
  char z[TAM];
} Palavra;
// l = {0^n 1^n 2^n | n>=0}
int main(){

  Palavra w, w1;
  char *word,*word1;

  word = (char*)malloc(sizeof(char)*60);
  word1 = (char*)malloc(sizeof(char)*60);

  // inicializando string com zeros para não conter lixo de memória no vetor
  for(int i = 0; i < 60; i++){
    word[i] = 0;
    word1[i] = 0;
  }

  printf("Para a  linguagem L = {a^n b^n c^n | n>=0}, determinar pelo lema do bombeamento se ela eh regular\n");

  //----------------------------------
  // Bloco de código para a formação da palavra
  int p = 3; // iterações para a formação da palavra inicial

  // tirando lixo de memória
  for(int i = 0; i < p; i++){
    w1.u[i] = 0;
    w1.v[i] = 0;
    w1.z[i] = 0;
  }

  // loop para formar a palavra
  for(int i = 0; i < p; i++){
    w1.u[i] = 'a';
    w1.v[i] = 'b';
    w1.z[i] = 'c';
  }

  // junção de uvz para mostrar a palavra de entrada
  strcat(word1,w1.u);
  strcat(word1,w1.v);
  strcat(word1,w1.z);

  printf("Entrada da palavra: \n");
  printf("Palavra formada: %s\n",word1);
  //----------------------------------

  //----------------------------------
  // Bloco de código para a escolha de UVZ
  printf("Escolha u: ");
  fgets(w.u,19,stdin);
  printf("Tamanho de u: %i\n",strlen(w.u)-1);
  fflush(stdin);
  printf("Escolha v: ");
  fgets(w.v,19,stdin);
  printf("Tamanho de v: %i\n",strlen(w.v)-1);
  fflush(stdin);
  printf("Escolha z: ");
  fgets(w.z,19,stdin);
  printf("Tamanho de z: %i\n",strlen(w.z)-1);
  fflush(stdin);
  //----------------------------------
  printf("Prova por contradicao: \na^p b^p c^p\n");

  strcat(word,w.u); //
  strcat(word,w.v); // junção de uvz
  strcat(word,w.z); //

  // determinação do tamanho da palavra
  int tamanhoW = (strlen(w.u)+strlen(w.v)+strlen(w.z)-3);
  printf("Tamanho da palavra: %i\n",tamanhoW);

  printf("Palavra formada: %s\n",word); // mostrando a palavra formada

  int x; // quantidade de iteraçoes para o bombeamento

  // condições para o lema do bombeamento
  //    |w| >= p               |uv| <= p                        |v| >= 1
  if(tamanhoW >= p && (strlen(w.u)+strlen(w.v)-2) <= p && (strlen(w.v)-1) >= 1){
    printf("Digite a quantidade de iteracoes para o bombeamento: ");
    scanf("%i",&x);
    for(int i = 0; i < x; i++){
      printf("Entrou for\n");
      strcat(w1.v,w.v); // bombeamento de v
    }

    printf("Mostrando v apos o bombeamento: %s",w.v);
  }


  return 0;
}
