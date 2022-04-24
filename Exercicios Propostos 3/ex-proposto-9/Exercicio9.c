/*
Exercício 9. Escreva um programa que leia do teclado uma frase e a coloque em
um vetor de caracteres. Entre as palavras que compõem a frase, pode haver um
ou mais espaços em branco ou sinais de pontuação ( , e . ) . O programa deve
escrever na tela as palavras que compõem a frase, uma por linha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    char frase[200];
    printf("Digite a sua frase por gentileza!\n");
    fflush(stdin);
    fgets(frase, 200, stdin);
    int tamanho = strlen(frase)-2;
    printf("As palavras são:\n");

    for(int i = 0; i <= tamanho; i++)
    {
        if(frase[i]!=' ' && frase[i]!=',' && frase[i]!='.')
        {
            printf("%c", frase[i]);
        }
        else if(frase[i+1]!=' ' && frase[i+1]!=',' && frase[i+1]!='.')
        {
            printf("\n");
        }
    }
    return 0;
}