/*
Esse código é de um compilador sintático, em que ele irá pegar um arquivo.txt e irá verificar se o código presente nele está de acordo com o padrão exigido. 
Apenas irá verificar comandos básicos como os de declaração de variável, abertura de blocos como os if's, else's e funções.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void transformar_minusculo(char linha[])
{
    int i = 0;
    while(linha[i]!='\0')
    {
        linha[i] = tolower(linha[i]);
        i++;
    }
    linha[i]='\0';
}

void tirar_espacos(char linha[])
{
    int i = 0;
    for(i=0; i<strlen(linha); i++){
        if(linha[i]==' '){
            linha[i]=linha[i+1];
            int j = i+1;
            for(j = j; j<strlen(linha); j++){
                linha[j]=linha[j+1];
            }
        }   
    }
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *fp;
    char arquivo[20];
    char linha[100];
    char result[100];
    char *leitura;
    int i;

    //Digitar o nome do arquivo para leitura
    printf("Digite o nome do arquivo a ser lido pelo compilador: ");
    scanf("%s", &arquivo);
    fp = fopen(arquivo, "rt");
    //

    if(fp == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }

    i = 1;
    while(!feof(fp))
    {
        leitura = fgets(linha, 100, fp);
        transformar_minusculo(linha);
        printf("Linha %d: %s", i, linha);
        tirar_espacos(linha);
        
        printf("Linha sem espaços %d: %s", i, linha);
        /*if(strcmp(leitura, "!Start\n") == 0)
        {
            printf("Programa iniciado!\n");
            //fflush(leitura);
            //printf("Linha %d: %s", i, linha);
        }
        if(strcmp(leitura, "!Stop") == 0)
        {
            printf("Programa finalizado!\n");
        }
        else if(strcmp(leitura, "\n") == 0)
        {
            printf("linha vázia\n");
        }*/
        if(strcmp(leitura, "!stop\n") == 0)
        {
            
        }
        i++;
    }
    fclose(fp);

    return 0;
}