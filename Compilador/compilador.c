#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char nome [50];

    if((fp = fopen("arquivo.txt","w")) != NULL)
    {
        for(int i = 0; i < 3; i++)
        {
            printf("Escreva um nome: ");
            gets(nome);
            fprintf(fp, "Nome %d: %s\n", i+1, nome);
        }
    }

    fclose(fp);

    return 0;
}