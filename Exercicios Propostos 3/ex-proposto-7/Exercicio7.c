/*
Exercício 7. (Busca binária) O programa deste exercício é essencialmente o
mesmo que o anterior. Entretanto, neste exercício, você deve implementar o
algoritmo de busca binária (portanto, é necessário que você ordene o seu vetor
antes de fazer a busca).
*/
#include <stdio.h>
#include <math.h>

int vetor[9999];

int buscarx(int x, int fim)//Função para busca binária
{
    int ini=0, meio;
    while(ini<=fim){
        meio=(ini+fim)/2;

        if(vetor[meio]==x){
            return meio;
        }
        if(vetor[meio]<x){
            ini=meio+1;
        }
        if(vetor[meio]>x){
            fim=meio-1;
        }
    }
    return -1;
}

int main()
{
    int cont = 0, aux = 0, x = 0, fim = 0;
    printf("Preencha o vetor com quantos valores achar suficiente!\n");

    while(cont<10000){//Preenchimento do vetor
        printf("Digite o valor para a posição %d: ", cont);
        scanf("%d", &vetor[cont]);
        if(vetor[cont]==0){//Flag para parada de leitura
            fim+=1;
            cont+=1;
            break;
        }
        else if(vetor[cont]<0){//Exigência de valores positivos
            printf("Digite um valor positivo!\n");
            cont-=1;
        }
        fim+=1;
        cont+=1;
    }
    for(int i = 0; i < cont; i++){//Ordenação crescente do vetor
        for(int j = 0; j < cont; j++){
            if(vetor[i] <= vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("Digite o valor a ser localizado: ");
    scanf("%d", &x);
    int resposta = buscarx(x, fim);
    if(resposta<0){//Saida de dados
        printf("Número digitado não existe no vetor");
    }
    else{
        printf("O número foi encontrado na posição %d do vetor", resposta);
    }
    return 0;
}