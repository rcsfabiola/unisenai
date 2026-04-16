#include<stdio.h>

// EXECUTAR NO TERMINAL:
// gcc vetor.c -o vetor
// ./vetor

// VETORES ou ARRAY >>> variável com múltiplas posições de armazenamento, onde cada posição é identificada por um número inteiro (índice) e pode armazenar um valor do mesmo tipo de dado.

int main(){
  float v1[4] = {7.1, 8.4, 9.5, 5.2};

  printf("Exibindo o vaor dos vetores: \n\n");
  // printf("v1[0] = %.1f\n", v1[0]);
  // printf("v1[1] = %.2f\n", v1[1]);
  // printf("v1[2] = %.3f\n", v1[2]);
  // printf("v1[3] = %.4f\n", v1[3]);

  int i;
  for (i = 0; i < 4; i++)
  {
    /* code */
    // printf("v1[0] = %f\n", v1[0]);
    printf("v1[%d] = %.1f\n", i, v1[i]);

    int tamanho = sizeof(v1);
    printf("Tamanho do vetor: %d\n", tamanho);
  }
  return 0;
}
