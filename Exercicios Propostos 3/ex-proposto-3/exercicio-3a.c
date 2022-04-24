/*
Exercício 3. Escreva um programa que leia uma palavra do teclado e determine
se é um palíndromo.
Observação: Palíndromo é uma palavra, frase ou número que permanece igual
quando lida de trás para diante.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
 
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char palavra[30];
    
	printf("Digite uma palavra: ");
	fgets(palavra, 30, stdin);
	palavra[ strcspn( palavra, "\n" ) ] = '\0';

	int i = 0;
	int cont = strlen(palavra);
	cont--;
	int errado = 0;

	while(cont - 1 >= i){
		if(tolower(palavra[i]) != tolower(palavra[cont])){
			errado++;
		}
		i++;
		cont--;
	}

	if(errado == 0){
		printf("\nA palavra %s é palíndroma!\n", palavra);
	} else{
		printf("\nA palavra %s não é palíndroma!\n", palavra);
	}
	return 0;
}