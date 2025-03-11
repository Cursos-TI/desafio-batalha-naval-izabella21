#include <stdio.h>

#define N 10  // Tamanho do tabuleiro

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade "Cone"
void aplicarCone(int tabuleiro[N][N], int origemX, int origemY, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = origemY - i; j <= origemY + i; j++) {
            if (i + origemX < N && j >= 0 && j < N) {
                tabuleiro[i + origemX][j] = 5;  // Marca a área do cone
            }
        }
    }
}

// Função para aplicar a habilidade "Cruz"
void aplicarCruz(int tabuleiro[N][N], int origemX, int origemY, int tamanho) {
    for (int i = -tamanho; i <= tamanho; i++) {
        if (origemX + i >= 0 && origemX + i < N) {
            tabuleiro[origemX + i][origemY] = 5;  // Marca a linha da cruz
        }
        if (origemY + i >= 0 && origemY + i < N) {
            tabuleiro[origemX][origemY + i] = 5;  // Marca a coluna da cruz
        }
    }
}

// Função para aplicar a habilidade "Octaedro"
void aplicarOctaedro(int tabuleiro[N][N], int origemX, int origemY, int tamanho) {
    for (int i = -tamanho; i <= tamanho; i++) {
        for (int j = -tamanho; j <= tamanho; j++) {
            // Verifica se a célula está dentro da área do octaedro
            if ((i + j >= -tamanho) && (i + j <= tamanho) && origemX + i >= 0 && origemX + i < N && origemY + j >= 0 && origemY + j < N) {
                tabuleiro[origemX + i][origemY + j] = 5;  // Marca a área do octaedro
            }
        }
    }
}

int main() {
    // Inicializando o tabuleiro com 0 (água)
    int tabuleiro[N][N] = {0};

    // Colocando navios no tabuleiro (exemplo)
    tabuleiro[2][2] = 3; // Navio 1
    tabuleiro[3][3] = 3; // Navio 1
    tabuleiro[4][4] = 3; // Navio 1
    tabuleiro[7][7] = 3; // Navio 2
    tabuleiro[8][7] = 3; // Navio 2
    tabuleiro[9][7] = 3; // Navio 2

    // Aplicando as habilidades
    aplicarCone(tabuleiro, 1, 5, 3);  // Exemplo: cone com origem em (1, 5)
    aplicarCruz(tabuleiro, 5, 5, 3);  // Exemplo: cruz com origem em (5, 5)
    aplicarOctaedro(tabuleiro, 5, 5, 3);  // Exemplo: octaedro com origem em (5, 5)

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
