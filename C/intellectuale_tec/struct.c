#include<stdio.h>

// EXECUTAR NO TERMINAL:
// gcc struct.c -o struct
// ./struct

int main() {
  struct fichaAluno {
    int matricula;
    float nota1;
    float nota2;
  };
  
    struct fichaAluno aluno[3];
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno[0].matricula);
    printf("Digite a primeira nota do aluno: ");
    scanf("%f", &aluno[0].nota1);
    printf("Digite a segunda nota do aluno: ");
    scanf("%f", &aluno[0].nota2);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno[1].matricula);
    printf("Digite a primeira nota do aluno: ");
    scanf("%f", &aluno[1].nota1);
    printf("Digite a segunda nota do aluno: ");
    scanf("%f", &aluno[1].nota2);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno[2].matricula);
    printf("Digite a primeira nota do aluno: ");
    scanf("%f", &aluno[2].nota1);
    printf("Digite a segunda nota do aluno: ");
    scanf("%f", &aluno[2].nota2);
}



