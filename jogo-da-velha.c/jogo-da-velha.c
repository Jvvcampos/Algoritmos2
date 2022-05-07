#include <stdio.h>

#define JOGADOR_X 'X';
#define JOGADOR_O 'O';
#define VAZIO '_'

void abertura() {
    printf("Bem-Vindo ao Jogo!\n");
    printf("Usaremos como referencia a seguinte matriz:\n");

    for(int i=1; i<=9; i++){
        printf(" %d", i);
        if(i == 3 || i == 6) {
            printf("\n");
        }
    }
}

int main() {
    abertura();
    int linha;
    int coluna;
    char tabuleiro[3][3];
    int cont = 0;

    for(int linha = 0; linha < 3; linha++) {
            for(int coluna = 0; coluna < 3; coluna++) {
                tabuleiro[linha][coluna] = VAZIO;
            }
    }

    while(1) {

        char jogador_atual;
        int base = cont % 2 == 0;

        if(base == 1) {
            jogador_atual = JOGADOR_X;
        } else {
            jogador_atual = JOGADOR_O;
        }

        int posicao;
        printf("\n\nEscolha uma posicao para marcar: ");
        scanf(" %d", &posicao);

        printf("\n\n");
        if(posicao == 1) {
            tabuleiro[0][0] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 2) {
            tabuleiro[0][1] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 3) {
            tabuleiro[0][2] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 4) {
            tabuleiro[1][0] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 5) {
            tabuleiro[1][1] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 6) {
            tabuleiro[1][2] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 7) {
            tabuleiro[2][0] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 8) {
            tabuleiro[2][1] = jogador_atual;
            printf(" %c", jogador_atual);
        }
        else if(posicao == 9) {
            tabuleiro[2][2] = jogador_atual;
            printf(" %c", jogador_atual);
        }

        printf("\n\n");
        for(int linha = 0; linha < 3; linha++) {
            for(int coluna = 0; coluna < 3; coluna++) {
                if(tabuleiro[linha][coluna] == VAZIO) {
                    printf(" _");
                } else {
                    printf(" %c", tabuleiro[linha][coluna]);
                }
                if(coluna == 2) {
                    printf("\n");
                }
            }
        }
        cont++;
    } 
}