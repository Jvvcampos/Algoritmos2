#include<stdio.h>

#define TAM 25
int main()
{
    int i;
    float vetA[TAM];
    float vetB[TAM];

    printf("Entrada de dados:\n\n");
    printf("Elementos do vetor A:\n");
    for(i=0;i<TAM;i++)
    {
        scanf(" %f",&vetA[i]);
    }

    printf("\n\nElementos do vetor B:\n");
    for(i=0;i<TAM;i++)
    {
        scanf(" %f",&vetB[i]);
    }

    float vetC[TAM*2];
    for(i=0;i<TAM;i++)
    {
        vetC[i*2] = vetA[i];
        vetC[i*2+1] = vetB[i];
    }
    
    printf("\n\n\nVetor A: {");
    for(i=0;i<TAM;i++)
    {
        printf(" %.2f ", vetA[i]);
    }
    printf("}");
    
    printf("\n\n\nVetor B: {");
    for(i=0;i<TAM;i++)
    {
        printf(" %.2f ", vetB[i]);
    }
    printf("}");
    
    printf("\n\n\nVetor C: {");
    for(i=0;i<TAM*2;i++)
    {
        printf(" %.2f ", vetC[i]);
    }
    printf("}\n");
}