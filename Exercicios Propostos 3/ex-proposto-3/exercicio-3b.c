/*
Exercício 3. Escreva um programa que leia uma palavra do teclado e determine
se é um palíndromo.
Observação: Palíndromo é uma palavra, frase ou número que permanece igual
quando lida de trás para diante
*/

#include<stdio.h>
#include<string.h>
#include <locale.h>
  
void main()
{
   setlocale(LC_ALL, "Portuguese");
   char palavra[20];
   char inversa[20];

   printf("Digite uma palavra: ");
   fgets(palavra, 20, stdin);
   palavra[ strcspn( palavra, "\n" ) ] = '\0';
  
   for(int i = 0; palavra[i]; i++){
      palavra[i] = tolower(palavra[i]);
   }

   strcpy(inversa, palavra);
   strrev(inversa);

   int comparacao = 0;
   comparacao = strcmp(palavra, inversa) == 0;

   if(comparacao){
      printf("\n%s é um palíndromo\n", palavra);
   }
   else{
      printf("\n%s NÃO é um palíndromo\n", palavra);
   }
}