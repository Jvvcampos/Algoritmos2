/*
Exercício 8. (Busca sequencial versus Busca binária) Considere os dois últimos
programas. Suponha que você queira pesquisar a ocorrência do número x. O
objetivo deste exercício é contar o número de testes/comparações de x com os
elementos do vetor, que cada um dos programas precisa fazer para tomar uma
decisão. Para isso, em cada um dos programas, acrescente um contador para
determinar este número. Compare o desempenho de ambos os programas,
considerando o número de comparações realizadas.
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