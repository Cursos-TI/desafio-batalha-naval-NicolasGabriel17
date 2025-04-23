#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro
#define NAVIO 3
#define HABILIDADE 5

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar navio horizontal (tamanho 3)
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    // Posicionar navio vertical (tamanho 3)
    tabuleiro[4][6] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    // Posicionar navio na diagonal principal (↘)
    tabuleiro[2][2] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[4][4] = NAVIO;

    // Posicionar navio na diagonal secundária (↙)
    tabuleiro[2][7] = NAVIO;
    tabuleiro[3][6] = NAVIO;
    tabuleiro[4][5] = NAVIO;

    // Habilidade em formato de cone (centro no topo e abre para baixo)
    int origemLinha = 6;
    int origemColuna = 4;

    for (i = 0; i < 3; i++) { // altura do cone
        for (j = -i; j <= i; j++) {
            int lin = origemLinha + i;
            int col = origemColuna + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                if (tabuleiro[lin][col] == 0) {
                    tabuleiro[lin][col] = HABILIDADE;
                }
            }
        }
    }

    // Imprimir o tabuleiro
    printf("\nTABULEIRO BATALHA NAVAL\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}