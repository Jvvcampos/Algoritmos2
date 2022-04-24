/*
Exercício 5. Dadas duas sequências de n e m elementos binários (0 ou 1), onde n
≤ m, faça um programa que verifique quantas vezes a primeira sequência ocorre
na segunda. Ex: se a primeira for 101 e a segunda 1101010011010, então o
resultado deve ser 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//letura das sequências
void leitura(char primeirasequencia[], char segundasequencia[]) {
    printf("Digite a primera sequência: ");
    fflush(stdin);
    fgets(primeirasequencia,100,stdin);
    printf("Digite a segunda sequência: ");
    fflush(stdin);
    fgets(segundasequencia,100,stdin);
}

int main(){

    char n[100];
    char m[100];
    int vezes=0;

    leitura(n, m);

    //conta o tamanho de cada char tirando o espaço no buffer e o enter
    int tamanhoN = strlen(n)-1;
    int tamanhoM = strlen(m)-1;

    if(tamanhoN > tamanhoM){
        printf("A primeria sequência deve ser menor que a segunda.");
        return 0;
    }

    for(int i=0; i<tamanhoM; i++){
            int aparece=0;

        for(int j=0; j<tamanhoN; j++){
            if(m[i+j] == n[j]){
                aparece++;
            }
        }

        if(aparece == tamanhoN){
            vezes++;
        }
    }

    printf("\nA primeira sequência aparece %i vez(es) na segunda.",vezes);
    return 0;
}