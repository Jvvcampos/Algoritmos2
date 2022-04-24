   
/*
Exercício 1. Faça um programa que leia um valor n e depois leia uma sequência
de n números inteiros e os armazene em um vetor. Posteriormente, seu programa
deve determinar o maior e o menor elemento do vetor.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int n[100000];
    char continuar;
    int cont = 0;
    int maior = 0;
    int menor = 10000;
    
    do
    {
        printf("Digite um número: ");
        scanf(" %d", &n[cont]);
        
        if(maior < n[cont]){
            maior = n[cont];
        }
        if(menor > n[cont]){
            menor = n[cont];
        }

        printf("Deseja adicionar mais números? (s/n)\n");
        scanf(" %c", &continuar);
        printf("\n\n");

        cont++;

    } while (continuar != 'n' && continuar != 'N');

    printf("\nMaior valor: %d\nMenor valor: %d\n", maior, menor);
    
    return 0;
}