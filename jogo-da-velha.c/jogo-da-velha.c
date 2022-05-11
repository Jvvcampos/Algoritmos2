#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JOGADOR_X 'X';
#define JOGADOR_O 'O';
#define VAZIO '_'

int linha;
int coluna;
int cont = 0;
char tabuleiro[3][3];
char nome_um[40];
char nome_dois[40];

void abertura() 
{
    printf("**************************\n");
    printf("*** Bem-Vindo ao Jogo! ***\n");
    printf("**************************\n\n");
    printf("Usaremos como referencia a seguinte matriz:\n");

    for(int i=1; i<=9; i++)
    {
        printf(" %d", i);
        if(i == 3 || i == 6) 
        {
            printf("\n");
        }
    }
    printf("\n\nLembrando que quem for jogar com X, vai jogar primeiro, tudo bem?\n");

    for(int linha = 0; linha < 3; linha++) 
    {
        for(int coluna = 0; coluna < 3; coluna++) 
        {
            tabuleiro[linha][coluna] = VAZIO;
        }
    }
    printf("\n\nEae, qual o nome de quem vai querer jogar com o X?\n");
    fgets(nome_um, 40, stdin);
    printf("\n\nBeleza! Quem vai jogar com o O?\n");
    fgets(nome_dois, 40, stdin);
}

char * leitura_verificacao()
{
    while(cont < 9) 
    {
        char jogador_atual;
        int base = cont % 2 == 0;
        char *ganhador = malloc(40);

        if(base == 1) 
        {
            jogador_atual = JOGADOR_X;
            strcpy(ganhador, nome_um);
        } 
        else 
        {
            jogador_atual = JOGADOR_O;
            strcpy(ganhador, nome_dois);
        }
        int posicao;
        printf("\n\n\nMarque um %c, %s", jogador_atual, ganhador);
        printf("\nEscolha uma posicao para marcar: ");
        scanf(" %d", &posicao);
        printf("\n\n");

        switch (posicao)
        {
        case 1:
            if(tabuleiro[0][0] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else 
            {
                tabuleiro[0][0] = jogador_atual;
            }
            break;
        case 2:
            if(tabuleiro[0][1] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[0][1] = jogador_atual;
            }
            break;
        case 3:
            if(tabuleiro[0][2] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[0][2] = jogador_atual;
            }
            break;
        case 4:
            if(tabuleiro[1][0] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[1][0] = jogador_atual;
            }
            break;
        case 5:
            if(tabuleiro[1][1] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[1][1] = jogador_atual;
            }
            break;
        case 6:
            if(tabuleiro[1][2] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[1][2] = jogador_atual;
            }
            break;
        case 7:
            if(tabuleiro[2][0] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[2][0] = jogador_atual;
            }
            break;
        case 8:
            if(tabuleiro[2][1] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[2][1] = jogador_atual;
            }
            break;
        case 9:
            if(tabuleiro[2][2] != VAZIO) 
            {
                printf("\nValor ja digitado!\n");
                continue;
            }
            else
            {
                tabuleiro[2][2] = jogador_atual;
            }
            break;
        default:
            printf("\nValor invalido!");
            continue;
        }
        printf("\n\n");

        for(int linha = 0; linha < 3; linha++) 
        {
            for(int coluna = 0; coluna < 3; coluna++) 
            {
                if(tabuleiro[linha][coluna] == VAZIO) 
                {
                    printf(" _");
                } else {
                    printf(" %c", tabuleiro[linha][coluna]);
                }
                if(coluna == 2) {
                    printf("\n");
                }
            }
        }
        if(cont >= 4) //começa a verificar quem ganhou depois da quarta jogada
        {
            if(tabuleiro[0][0] != VAZIO && tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][0] == tabuleiro[0][2])//primeira linha
            {
                return ganhador;
            }
            else if(tabuleiro[1][0] != VAZIO && tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][0] == tabuleiro[1][2])//segunda linha
            {
                return ganhador;
            }
            else if(tabuleiro[2][0] != VAZIO && tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][0] == tabuleiro[2][2])//terceira linha
            {
                return ganhador;
            }
            else if(tabuleiro[0][0] != VAZIO && tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[0][0] == tabuleiro[2][0])//primeira coluna
            {
                return ganhador;
            }
            else if(tabuleiro[0][1] != VAZIO && tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[0][1] == tabuleiro[2][1])//segunda coluna
            {
                return ganhador;
            }
            else if(tabuleiro[0][2] != VAZIO && tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[0][2] == tabuleiro[2][2])//terceira coluna
            {
                return ganhador;
            }
            else if(tabuleiro[0][0] != VAZIO && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])//diagonal principal
            {
                return ganhador;
            }
            else if(tabuleiro[0][2] != VAZIO && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])//diagonal secundaria
            {
                return ganhador;
            }
        }

        cont++;

        if(cont == 9) {
            printf("\n\nJogo empatado!\n");
            return ganhador = 0;
        }
    } 
    
}

int main() 
{
    abertura();
    char *resultado = leitura_verificacao();

    if(resultado != 0) {
        printf("\nParabens por ganhar o jogo, %s", resultado);
    }

    return 0;
}