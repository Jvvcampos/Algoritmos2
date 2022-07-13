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

void verifica_var(char linha[])//função para verificar o comando var
{
  if(linha[4]=='i' && linha[5]=='n' && linha[6]=='t' && linha[7]==' ')//Variável como tipo inteiro
    {
        printf("Váriavel de tipo int\n");
        for(int i = 8; i<strlen(linha)-2; i++)
        {
            if(linha[i]=='>' && linha[i+1]=='=' || linha[i]=='<' && linha[i+1]=='=' || linha[i]=='=' && linha[i+1]=='=' || linha[i]=='!' && linha[i+1]=='=')
            {
                printf("Uso de operadores lógicos indevido, somente é permitido usar = para atribuir valores!\n");
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
        }
        if(linha[strlen(linha)-2]!=';')
        {
            printf("O comando var está faltando o ';' no final da linha %d!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
            exit(0);
        }
    }
    else if(linha[4]=='f' && linha[5]=='l' && linha[6]=='o' && linha[7]=='a' && linha[8]=='t' && linha[9]==' ')//Variável como tipo float
    {
        printf("Váriavel de tipo float\n");
        for(int i = 10; i<strlen(linha)-2; i++)
        {
            if(linha[i]=='>' && linha[i+1]=='=' || linha[i]=='<' && linha[i+1]=='=' || linha[i]=='=' && linha[i+1]=='=' || linha[i]=='!' && linha[i+1]=='=')
            {
                printf("Uso de operadores lógicos indevido, somente é permitido usar = para atribuir valores!\n");
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
        }
        if(linha[strlen(linha)-2]!=';')
        {
            printf("O comando var está faltando o ';' no final da linha %d!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
            exit(0);
        }
    }
    else if(linha[4]=='c' && linha[5]=='h' && linha[6]=='a' && linha[7]=='r' && linha[8]==' ')//Variável de tipo char
    {
        printf("Váriavel de tipo string\n");
        int chave_char=0;
        for(int i = 9; i<strlen(linha)-2; i++)//Esse for vai verificar a presença de [] e a garantia dos operadores lógicos
        {
            if(linha[i]=='[')
            {
                chave_char+=1;
            }
            if(linha[i]==']')
            {
                chave_char-=1;
            }
            if(linha[i]=='>' && linha[i+1]=='=' || linha[i]=='<' && linha[i+1]=='=' || linha[i]=='=' && linha[i+1]=='=' || linha[i]=='!' && linha[i+1]=='=')
            {
                printf("Uso de operadores lógicos indevido, somente é permitido usar = para atribuir valores!\n");
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
            if(chave_char>=1 || chave_char<0)
            {
                printf("Erro nos colchetes do tamanho do char na linha %d, foi colocado um colchete de abertura a mais ou um de fechamento!!\n", linhas_lidas);
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
                exit(0);
            }
        }
        if(chave_char!=0)
        {
            printf("Erro nos colchetes do tamanho do char na linha %d, não foi fechado o colchete!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
            exit(0);
        }  
        if(linha[strlen(linha)-2]!=';' )
        {
            printf("O comando var está faltando o ';' no final da linha %d!!\n", linhas_lidas);
            printf("Conserte o erro e tente novamente!\n");
            printf("Foram lidas %d linhas do arquivo!", linhas_lidas);
            exit(0);
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
    int verificador_start = 0;
    int verificador_stop = 0;
    int verificador_main = 0;
    int verificador_chaves = 0;

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

    while(!feof(fp))
    {
        leitura = fgets(linha, 100, fp);
        linhas_lidas++;
        transformar_minusculo(linha);
        preparar_linha(linha);

        if((strncmp(linha, "!start", 5)==0))//Vai inicializar o verificador para travar o funcionamento do restante do código se não tiver o Start
        {
            verificador_start+=1;
            if(verificador_start>1)//Tratamento de exceção para duplicação do comando start
            {
                printf("Um comando de Start a mais foi inserido no código, remova o excedente, lembre-se que o código só irá contar apartir de quando o !start for iniciado!\n", linhas_lidas);
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
                exit(0);
            }
        }
        if(verificador_start==1 && verificador_stop==0)
        {
            if((strncmp(linha, "var", 3)==0))
            {
                verifica_var(linha);
            }
        }
        if(strncmp(linha, "func void main()", 16)==0 && verificador_start==1 && verificador_stop==0 || strncmp(linha, "func void main ()", 17)==0 && verificador_start==1 && verificador_stop==0)//Mesmo principio do Start, mas para função Main
        {
            if(verificador_main>1)//Tratamento de exceção para duplicação da criação da main
            {
                printf("Houve uma tentativa de abertura de outra main na linha %d, apague-a e deixe seu código dentro de apenas uma função main!\n", linhas_lidas);
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
                exit(0);
            }
            if(linha[strlen(linha)-2]!='{')//Verificar a presença da chave de abertura na main
            {
                printf("A abertura da main faltou a chave de abertura no final da linha %d!\n", linhas_lidas);
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
                exit(0);
            }
            else//A main irá operar sempre com um o valor 1 no verificador_chaves até reconhecer sua chave de fechamento devidamente
            {
                verificador_main+=1;
                verificador_chaves+=1;
            }
        }
        /*if(verificador_chaves==1 && verificador_main==1 && verificador_start==1)
        {
            if(strncmp(linha, ))
        }*/

        if(strncmp(linha, "}", 1)==0)//Ajustar o contador de acordo com as chaves de fechamento
        {
            verificador_chaves-=1;
        }
        if(strncmp(linha, "!stop", 5) == 0)//Verificador para checar se o código teve o Stop colocado devidamente
        {   
            verificador_stop+=1;
            if(verificador_stop>1)//Tratamento de exceção para duplicação do comando stop
            {
                printf("Um comando de Stop a mais foi inserido no código, remova o excedente, lembre-se que o código irá deixar de verificar depois do !stop\n", linhas_lidas);
                printf("Conserte o erro e tente novamente!\n");
                printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
                exit(0);
            }
        }
        i++;
    }
    fclose(fp);

    if(verificador_chaves>0)
    {
        if(verificador_main==1 && verificador_chaves==1)
        {
            printf("O arquivo terminou de ser lido, porém, a main não foi fechada e assim ficou incorreto!\n");
        }
        else
        {
            printf("O arquivo terminou de ser lido, porém, o código ficou com uma chave a mais e assim, incorreto!\n");
        }
    }
    else if(verificador_chaves<0)
    {
        printf("O arquivo terminou de ser lido, porém, o código ficou com uma chave a menos e assim ficou incorreto!\n");
    }

    if(verificador_stop<1)
    {
        printf("O arquivo terminou de ser lido, porém, o código ficou sem o !stop para parar a leitura do código e assim ficou incorreto!\n"); 
    }
    if(verificador_stop==1 && verificador_chaves==0)
    {
        printf("O código estava totalmente correto!\n");
    }
    printf("Foram lidas %d linhas do arquivo!\n", linhas_lidas);
    free(fp);
    free(leitura);
    return 0;
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