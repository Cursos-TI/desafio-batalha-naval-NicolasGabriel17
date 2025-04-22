#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posição inicial do navio horizontal
    int linhaH = 1;      // Linha 2 (lembrando que começa do 0)
    int colunaH = 0;     // Coluna A

    // Verifica se o navio cabe horizontalmente e se não há sobreposição
    if (colunaH + 3 <= 10 &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {

        tabuleiro[linhaH][colunaH] = 3;
        tabuleiro[linhaH][colunaH + 1] = 3;
        tabuleiro[linhaH][colunaH + 2] = 3;
    }

    // 3. Posição inicial do navio vertical
    int linhaV = 2;     // Linha 3
    int colunaV = 2;    // Coluna C

    // Verifica se o navio cabe verticalmente e se não há sobreposição
    if (linhaV + 3 <= 10 &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = 3;
        tabuleiro[linhaV + 1][colunaV] = 3;
        tabuleiro[linhaV + 2][colunaV] = 3;
    }

    // 4. Exibindo o tabuleiro
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho das colunas (letras A até J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + 10; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // número da linha
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
