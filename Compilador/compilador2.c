/*
Esse código é de um compilador sintático, em que ele irá pegar um arquivo.txt e irá verificar se o código presente nele está de acordo com o padrão exigido. 
Apenas irá verificar comandos básicos como os de declaração de variável, abertura de blocos como os if's, else's e funções.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int linhas_lidas = 0;

void transformar_minusculo(char linha[])//Essa função irá transformar tudo em minúsculo.
{
    int i = 0;
    while(linha[i]!='\0')
    {
        linha[i] = tolower(linha[i]);
        i++;
    }
    linha[i]='\0';
}

void preparar_linha(char linha[])//Essa função irá remover a identação para facilitar a leitura, depois chamará outra função para espaços.
{
    int i = 0;
    int ident = -1;
    while(linha[i]==' ')
    {
        ident++;
        i++;
    }
    if(ident>=0)
    {
        for(i=0; i<strlen(linha); i++)
        {
            ident++;
            linha[i]=linha[ident];
        }
    }
    tirar_espacos(linha);
}

void tirar_espacos(char linha[])//Essa função removerá espaços duplos no código, acima disso o código irá parar.
{
    for(int i=0; i<strlen(linha); i++){
        if(linha[i]==' ' && linha[i+1]==' ')
        {
            if(linha[i+2]==' ')
            {
                printf("O código do arquivo está contendo espaços triplos, conserte-os antes de tentar executar o compilador novamente!\n");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);  
            }
            linha[i]=linha[i+1];
            int j = i+1;
            for(j = j; j<strlen(linha); j++){
                linha[j]=linha[j+1];
            }
        }  
    }
}

void verifica_var(char linha[])
{
  if(linha[4]=='i' && linha[5]=='n' && linha[6]=='t' && linha[7]==' ')//Váriavel como tipo inteiro
    {
        for(int i = 8; i<strlen(linha)-2; i++)
        {
            if(linha[i]=='>' && linha[i+1]=='=' || linha[i]=='<' && linha[i+1]=='=' || linha[i]=='=' && linha[i+1]=='=' || linha[i]=='!' && linha[i+1]=='=')
            {
                printf("Uso de operadores lógicos indevido, somente é permitido usar = para atribuir valores");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
        }
        if(linha[strlen(linha)-2]!=';')
        {
            printf("O comando var está faltando o ';' no final da linha %d!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
            exit(0);
        }
    }
    else if(linha[4]=='f' && linha[5]=='l' && linha[6]=='o' && linha[7]=='a' && linha[8]=='t' && linha[9]==' ')//Váriavel como tipo float
    {
        for(int i = 10; i<strlen(linha)-2; i++)
        {
            if(linha[i]=='>' && linha[i+1]=='=' || linha[i]=='<' && linha[i+1]=='=' || linha[i]=='=' && linha[i+1]=='=' || linha[i]=='!' && linha[i+1]=='=')
            {
                printf("Uso de operadores lógicos indevido, somente é permitido usar = para atribuir valores");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
        }
        if(linha[strlen(linha)-2]!=';')
        {
            printf("O comando var está faltando o ';' no final da linha %d!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
            exit(0);
        }
    }
    else if(linha[4]=='c' && linha[5]=='h' && linha[6]=='a' && linha[7]=='r' && linha[8]==' ')
    {
        printf("Váriavel de tipo string\n");
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
        linhas_lidas++;
        transformar_minusculo(linha);
        preparar_linha(linha);
        
        //printf("Linha sem espaï¿½os %d: %s", i, linha);

        if((strncmp(linha, "var", 3)==0))
        {
            verifica_var(linha);
        }

        //if((strncmp(leitura, "if(", 3)==0) || (strncmp(leitura, "if (", 4)==0))


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
            printf("linha vï¿½zia\n");
        }*/
        if(strncmp(linha, "!stop", 5) == 0)
        {   
          free(fp);
          free(leitura);  
        }
        i++;
    }
    fclose(fp);

    return 0;
}