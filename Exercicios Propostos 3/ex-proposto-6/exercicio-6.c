/*
Exercício 6. (Busca sequencial) Faça um programa que leia uma sequência de números positivos terminada com o número 0 e os armazene em um vetor.
Depois disso, seu programa deve solicitar um número ao usuário e pesquisar se o número digitado ocorre no vetor. Seu programa deve implementar o algoritmo de busca sequencial.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i = 0;
    int num[100000];
    while(1){
        printf("Digite um número: ");
        scanf("%d", &num[i]);

        if(num[i] == 0){
            break;
        }

        //Não considera números menores que 0
        if(num[i] < 0){
            printf("\nDigite um número maior que 0!\n");
            i--;
        }
        i++;
    }

    int pesquisa;

    printf("\n\nDigite o número que deseja pesquisar: ");
    scanf("%d", &pesquisa);

    int cont_negativo = 0;
    for(int k = 0; k < i; k++){
        if(pesquisa == num[k]){
            printf("\nO número está na posição %d.", k+1);
        }else{
            cont_negativo++;
        }
    }

    //Se o número não estiver em nenhuma posição do vetor
    if(cont_negativo == i){
        printf("\nNão conseguimos encontrar o seu número na lista :/\n");
    }

    return 0;
}