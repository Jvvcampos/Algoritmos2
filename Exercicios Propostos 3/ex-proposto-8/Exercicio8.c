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
#include <math.h>

int vetor[9999], comp_binario, comp_sequencial;

int buscarx_sequencial(int x, int cont)//Função para busca sequencial
{
    int cont_negativo = 0, k = 0;
    while(k < cont)
    {
        if(x == vetor[k])
        {
            comp_sequencial+=1;
            return x;
        }
        else
        {
            cont_negativo+=1;
        }
        comp_sequencial+=1;
        k+=1;
    }
    if(cont_negativo == cont)
    {
        printf("Número não encontrado no vetor");
        return -1;
    }
}

int buscarx_binario(int x, int fim)//Função para busca binária
{
    int ini = 0, meio;
    while(ini<=fim)
    {
        meio=(ini+fim)/2;
        if(vetor[meio] == x){
            comp_binario+=1;
            return meio;
        }
        if(vetor[meio] < x){
            ini=meio+1;
        }
        if(vetor[meio] > x){
            fim=meio-1;
        }
        comp_binario+=1;
    }
    return -1;
}

int main()
{
    int cont = 0, aux = 0, x = 0, fim = 0;
    printf("Preencha o vetor com quantos valores achar suficiente!\n");

    while(cont<10000)//Preenchimento do vetor
    {
        printf("Digite o valor para a posição %d: ", cont);
        scanf("%d", &vetor[cont]);
        if(vetor[cont] == 0)//Flag para parada de leitura
        {
            fim+=1;
            cont+=1;
            break;
        }
        else if(vetor[cont] < 0){
            printf("Digite um valor positivo!\n");//Exigência de valores positivos
            cont-=1;
        }
        fim+=1;
        cont+=1;
    }
    printf("Digite o valor a ser localizado: ");
    scanf("%d", &x);
    int resposta_sequencial = buscarx_sequencial(x, cont);

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
    int resposta_binario = buscarx_binario(x, fim);
    //Saida de dados
    if(resposta_binario < 0 || resposta_sequencial < 0)//Por ser os mesmos valores, se ele não estiver em um método de busca, logo também não vai estar no outro.
    {
        printf("Número digitado não existe no vetor\n");
    }
    else
    {
        printf("O número foi encontrado na posição %d do vetor em modo de busca sequencial!\n", resposta_sequencial);
        printf("O número foi encontrado na posição %d do vetor em modo de busca binária!\n", resposta_binario);
    }

    if(comp_binario < comp_sequencial)
    {
        printf("O método de busca binário foi mais rápido e teve %d comparações realizadas!\n", comp_binario);
    }
    else if (comp_binario == comp_sequencial)
    {
        printf("Os métodos empataram! %d comparações realizadas no modo de busca binária e %d comparações realizadas no modo de busca sequencial\n", comp_binario, comp_sequencial);  
    }
    else
    {
        printf("O método de busca sequencial foi mais rápido e teve %d comparações realizadas!\n", comp_sequencial);  
    }
    return 0;
}