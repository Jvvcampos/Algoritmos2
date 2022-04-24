/*
Exercício 4. Escreva um programa que leia uma sequência de n inteiros e
determine quantas sequências isoladas de números iguais existem. Exemplo:
para n = 13.

                        3 4 4 1 2 5 5 5 2 2 6 2 2

Há 4 grupos de 1 elemento (3, 1, 2 e 6), 3 grupos de 2 elementos (4, 2 e 2) e 1
grupo de 3 elementos (5). O valor n deve ser um dado de entrada.
*/

#include <stdio.h>

int main()
{
    int sequencia[50], n, seq = 0, count;

    printf("Qual o tamanho da sequencia (2 a 50)?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Posicao %d:\n", i + 1);
        scanf("%d", &sequencia[i]);
    }

    printf("Valores: [");
    for (count = 0; count < n - 1; count++)
    {
        printf("%d, " ,sequencia[count]);

        if (seq > 0 && sequencia[count] == sequencia[count - 1])
            continue;

        if (sequencia[count + 1] == sequencia[count])
            seq += 1;
    }
    printf("%d ]\nSequencias encontradas: %d", sequencia[count],  seq);
}