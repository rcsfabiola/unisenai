#include <stdio.h>

// EXECUTAR NO TERMINAL:
// cd intellectuale_tec
// gcc aula01.c -o aula01
// ./aula01


// // Primeiro código em C
// int main(){
//   printf("Hello, World!\n");
//   return 0;
// }

// // Variáveis e Tipos de Dados
// int globalVar = 10; 
// float globalFloat = 3.14;
// double globalDouble = 2.71828;

// char globalChar = 'A';
// char globalString[] = "Hello, World!";

//   int main() {
//     printf("Global Variables: %d\n", globalVar);
//     printf("Global Float: %.2f\n", globalFloat);
//     printf("Global Double: %.5f\n", globalDouble);
//     printf("Global Char: %c\n", globalChar);
//     printf("Global String: %s\n", globalString);  
// 	return 0;
// }

// int main(){

//   // VARIAVEIS
//   int valor1, valor2, soma, sub, mult, div;

//   // ENTRADA
//   printf("Digite o valor: ");
//   scanf("%d", &valor1);

//   printf("Digite outro valor: ");
//   scanf("%d", &valor2);

//    // PROCESSAMENTO
//   soma = valor1 + valor2;
//   sub = valor1 - valor2;
//   mult = valor1 * valor2;
//   div = valor1 / valor2;

//   // SAIDA
//   printf("A soma dos valores é: %d + %d = %d\n", valor1, valor2, soma);
//   printf("A subtração dos valores é: %d - %d = %d\n", valor1, valor2, sub);
//   printf("A multiplicação dos valores é: %d * %d = %d\n", valor1, valor2, mult);
//   printf("A divisão dos valores é: %d / %d = %d\n", valor1, valor2, div);

//   return 0;
// }

// // if else
// int main(){
//   int num, resto;

//   printf("Digite um numero: ");
//   scanf("%d", &num);

//   resto = num % 2;
//   if (resto == 0) {
//     printf("O numero %d é par.\n", num);
//   } else {
//     printf("O numero %d é impar.\n", num);
//   }
// }

// // OPERADOR CONDICIONAL >>>  && ||
//  int main() {
//   float nota1, nota2, media, freq;

//   printf("Digite a primeira nota: ");
//   scanf("%f", &nota1);

//   printf("Digite a segunda nota: ");
//   scanf("%f", &nota2);

//   printf("Digite a frequência do aluno (em porcentagem): ");
//   scanf("%f", &freq);

//   media = (nota1 + nota2) /2;
//   printf("A média é: %.1f\n", media);
  
//   if(media >= 6 && freq >= 75){
//     printf("Aluno aprovado!\n");
//   }else if(media < 3 || freq < 50){
//     printf("Aluno Reprovado.\n");
//   }else{
//     printf("Aluno em recuperação.\n");
//   }  
// }

// // OPERADOR CONDICIONAL >>> TERNÁRIO
// int main(){
//   int num;

//   printf("Digite um número inteiro: ");
//   scanf("%d", &num);

//   num > 0 ? printf("O número é positivo\n") : printf("O número é negativo ou zero\n");
//   return 0;
// }

// LOOPING FOR / WHILE / DO WHILE
// int main(){
//   int cont;
//   for(cont=1; cont <= 10; cont++){
//     printf("%d ", cont);
//     printf("boa noite!\n");
//   }
//   return 0;
// }

// int main(){
//   int cont = 1;
//   while(cont <= 5){
//     printf("%d - C\n", cont);
//     cont++;
//   }
//   return 0;
// }

// int main(){
//   int cont = 1;
//   do{
//     printf("%d - C\n", cont);
//     cont++;
//   }while(cont <= 10);
//   return 0;
// }