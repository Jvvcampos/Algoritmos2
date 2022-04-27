/*
Exercício. Crie um algoritmo que ordene um vetor com n posições em ordem crescente. 
Iremos utilizar os métodos: Insertion Sort, Selection Sort, BubbleSort, QuickSort e MergeSort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int vetor[10000];
int cont_insertion = 0, cont_selection = 0, cont_bubble = 0, cont_quick = 0;

int ordenacao_insertion(int cont)//Função Insertion Sort
{
    int aux = 0;
    for(int i=1; i<cont; i++) 
    {
        aux = vetor[i];
        int j = i - 1;

        while(j >= 0 && aux < vetor[j]) 
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
        //cont_insertion+=1;
    }
    return 0;
}

int ordenacao_selection(int cont)//Função Selection Sort
{
    int aux = 0;
    for(int i = 0; i < cont; i++)//Ordenação crescente do vetor
    {
        for(int j = 0; j < cont; j++)
        {
            if(vetor[i] <= vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    return 1;
}

int ordenacao_bubble(int cont)//Função Bubble Sort
{
    int aux = 0;
    for(int i = cont-1; i >= 1; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return 0;
}

int ordenacao_quick(int vetor[], int ini, int fim)//Função Quick Sort
{
    int pivo = 0, i, j, aux = 0;
    i = ini;
    j = fim - 1;
    pivo = vetor[(ini+fim)/2];
    while(i <= j)
    {
        while(vetor[i] < pivo && i < fim)
        {
            i+=1;
        }
        while(vetor[j] > pivo && j > ini)
        {
            j-=1;
        }
        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i+=1;
            j-=1;
        }
        if(j > ini)
        {
            ordenacao_quick(vetor, ini, j+1);
        }
        if(i < fim)
        {
            ordenacao_quick(vetor, i, fim);
        }
    }
    return 0;
}

int main()
{
    int cont = 0, opcao;
    printf("Preencha o vetor com quantos valores achar suficiente!\n");

    while(cont<10000)//Preenchimento do vetor
    {
        printf("Digite o valor para a posição %d: ", cont);
        scanf("%d", &vetor[cont]);
        if(vetor[cont] == 0)//Flag para parada de leitura
        {
            cont+=1;
            break;
        }
        else if(vetor[cont] < 0){
            printf("Digite um valor positivo!\n");//Exigência de valores positivos
            cont-=1;
        }
        cont+=1;
    }
    printf("\nVetor antes da ordenação:\n");
    printf("{");
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("}\n");
    int selecao = 0;
    printf("Selecione o método de ordenação do vetor!\n1 - Insertion Sort, 2 - Selection Sort, 3 - BubbleSort e 4 - QuickSort\n\n");

    while(selecao == 0)
    {
        scanf("%d",&opcao);
        selecao+=1;
        if(opcao == 0)
        {
            printf("Digite um dos valores solicitados!\n\n");
            selecao = 0;
        }
    }
    switch (opcao)
    {
        case 1://Insertion Sort
        {
            ordenacao_insertion(cont);
            break;
        }
    
        case 2://Selection Sort
        {
            ordenacao_selection(cont);
            break;
        }
        case 3://Bubble Sort
        {
             ordenacao_bubble(cont);
             break;
        }
        case 4://Quick Sort
        {
            ordenacao_quick(vetor, 0, cont);
            break;
        }
    }
    //Saida de dados
    printf("\nVetor depois de ordenado!\n");
    printf("{");
    for(int i = 0; i < cont; i++)
    {
        printf(" %d ", vetor[i]);
    }
    printf("}\n");


    return 0;
}