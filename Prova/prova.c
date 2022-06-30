/*
Prova de Algoritmos II - Crie um algoritmo que faça a multiplicação de matrizes e implemente na
linguagem de programação C. O programa deve possuir as seguintes funcionalidades:
● Ler três valores: M, N e P; (1,5)
● Receber como entrada uma matriz AMxN e outra matriz BNxP, com valores
inteiros no intervalo [-10, 10]; (2,0)
● Realizar a multiplicação da matriz A por B e salvar o resultado na matriz
CMxP; (5,0)
● Exibir a matriz resultante C. (1,5)
*/

#include <stdio.h>
#include <math.h>

int M = 0;
int N = 0; 
int P = 0;

int preenche_matrizA(int A[M][N])//Essa é a função que irá preencher a matriz A
{
    for(int i = 0; i<M; i++)//Nesse for irá percorrer toda a matriz enquanto coloca os números em suas posições
    {
        for(int j = 0; j<N; j++)
        {
            printf("\nElemento da matriz A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    return 0;
}

int preenche_matrizB(int B[N][P])
{
    int aux_leitura = 0;//Aqui declarei uma auxiliar para checar a restrição de valores digitados
    
    printf("\nDigite elementos entre -10 e 10 para a matriz B");
    for(int i = 0; i<N; i++)//Assim como no for que preenche a matriz A, faço o mesmo aqui
    {
        for(int j = 0; j<P; j++)
        {
            printf("\nElemento da matriz B[%d][%d] = ", i, j);
            scanf("%d", &aux_leitura);//Aqui coloco o valor da posição na variável auxiliar para verificar
            
            if(aux_leitura>=-10 && aux_leitura<=10)//Aqui eu verifico se o número digitado está de acordo
            {
                B[i][j] = aux_leitura;//Estando OK, irá ser colocado em seu lugar
            }
            else//Caso o número não atendo o último IF, será deduzido do iterador do for, tendo em vista que assim que executa todos os comandos ele já soma novamente, assim, faço ele permanecer na mesma posição.
            {
                j-=1;
                printf("Valor digitado não atende o solicitado!");//Só informo para quem está digitando que não está de acordo
            }
        }
    }
    return 0;
}

int multiplica_matrizes(int A[M][N], int B[N][P], int C[M][P])//Aqui que começa a festinha, nossa função que irá multiplicar as matrizes e colocar na matriz C os resultados
{
    int multi;//Essa variável é para guardar o resultado de cada posição antes de ser atribuída, tendo em vista que a matriz C terá valores aleatórios e muito altos por não ter sido definido anteriormente.
    
    for(int i = 0; i<M; i++)//Esse for irá percorrer a linha da matriz C
    {
        for(int j = 0; j<P; j++)//Esse for irá percorrer a coluna da matriz C
        {
            multi = 0;//Seto a auxiliar como 0, para que cada iteração o multi não fique guardando valores passados
            
            for(int k = 0; k<M; k++)//Esse for irá ocorrer a multiplicação
            {
                multi+=A[i][k]*B[k][j];//Aqui estou multiplicando a matriz A pela B, multiplico um valor em uma posição da coluna de A por um valor em uma posição na linha de B. Depois somo a variável multi, o processo segue até tudo ser multiplicado e somado.
                C[i][j] = multi;//Depois de multiplicar os valores, atribuo o resultado a sua posição na matriz C
            }
        }
    }
    return 0;
}

int main()
{
    //Aqui estou apenas lendo os valores que definirão o tamanho das matrizes
    printf("Digite o valor de M!\n");
    scanf("%d", &M);
    printf("\nDigite o valor de N!\n");
    scanf("%d", &N);
    printf("\nDigite o valor de P!\n");
    scanf("%d", &P);

    //Aqui defino o tamanho das matrizes
    int A[M][N];
    int B[N][P];
    int C[M][P];
    
    preenche_matrizA(A);//Aqui faço a chamada para função que irá preencher a matriz A
    preenche_matrizB(B);//Aqui faço a chamada para função que irá preencher a matriz B
    multiplica_matrizes(A, B, C);//Aqui faço a chamada para função que irá multiplicas as matrizes A e B
    
    for(int i = 0; i<M; i++)//Aqui faço a impressão da matriz C como o resultado da multiplicação
    {
        for(int j = 0; j<P; j++)
        {
            printf("\nElemento da matriz C[%d][%d] = %d", i, j, C[i][j]);   
        }
    }
    return 0;
}
