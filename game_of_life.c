#include "game_of_life.h"
#include "system_info.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int TAMANHO = 21;
int bacteriasVivas = 0;
int bacteriasMortas = 0;
int geracao = -1;


int randomNumber() {
    return rand() % 2; 
}

void fillRandom(int currentGenerationMatrix[TAMANHO][TAMANHO]) {
    srand((unsigned)time(NULL));

    for (int row = 0; row < TAMANHO; row++) {
        for (int col = 0; col < TAMANHO; col++){
            int num = randomNumber();
            currentGenerationMatrix[row][col] = num;
        }
    }
}

void printMatrix(int matrix[TAMANHO][TAMANHO]) {
    system("clear");
        
    for (int row = 0; row < TAMANHO; row++) {
        for (int col = 0; col < TAMANHO; col++) {
            if (matrix[row][col] == 1) {
                printf("■ ");
            } else {
                printf("□ ");
            }
        }
        printf("\n");
    }
}

void imprimirEstatisticasCenario() {
    printf("====================\n");
    printf("Geracao: %d\n", geracao);
    printf("Bacterias Vivas: %d\n", bacteriasVivas);
    printf("Bacterias Mortas: %d\n", bacteriasMortas);
    
    imprimirEstatisticasDoSistema();
}

int calcularVizinhos(int matrix[TAMANHO][TAMANHO], int row, int col) {
    int totBacterias = 0;

    int vizinhos_x[3] = {row - 1, row, row + 1};
    int vizinhos_y[3] = {col - 1, col, col + 1};
    
    for (int i = 0; i < 3; i++) {
        for(int c = 0; c < 3; c++) {
            int vizinhosX = vizinhos_x[i];
            int vizinhoY = vizinhos_y[c];

            if (vizinhosX >= 0 && vizinhosX < TAMANHO && vizinhoY >= 0 && vizinhoY < TAMANHO && !(vizinhosX == row && vizinhoY == col)) {
                if (matrix[vizinhosX][vizinhoY] == 1) {
                    totBacterias++;
                }
            }
        }
    }

    return totBacterias;
}

int proximaGeracao(int currentGenerationMatrix[TAMANHO][TAMANHO], int nextGenerationMatrix[TAMANHO][TAMANHO]) {
    bacteriasMortas = 0;
    bacteriasVivas = 0;


    for (int row = 0; row < TAMANHO; row++) {
        for (int col = 0; col < TAMANHO; col++) {          
            int totBacterias = calcularVizinhos(currentGenerationMatrix, row, col);
            int frameAtual = currentGenerationMatrix[row][col];
            
            if (frameAtual == 1) {
                if (totBacterias < 2 || totBacterias > 3) {
                    nextGenerationMatrix[row][col] = 0;
                } else {
                    nextGenerationMatrix[row][col] = 1;
                }

                bacteriasVivas++;
            } else if (frameAtual == 0) {
                if (totBacterias == 3) {
                    nextGenerationMatrix[row][col] = 1;
                } else {
                    nextGenerationMatrix[row][col] = 0;
                }

                bacteriasMortas++;
            } else {
                nextGenerationMatrix[row][col] = 0;
            }
        }
    }

    return transferirDados(currentGenerationMatrix, nextGenerationMatrix);
}

int transferirDados(int currentGenerationMatrix[TAMANHO][TAMANHO], int nextGenerationMatrix[TAMANHO][TAMANHO]) {
    int estaVazia = 1;

    for (int row = 0; row < TAMANHO; row++) {
        for (int col = 0; col < TAMANHO; col++) {
            currentGenerationMatrix[row][col] = nextGenerationMatrix[row][col];
            if (currentGenerationMatrix[row][col] == 1) {
                estaVazia = 0;
            }
        }
    }

    geracao++;
    return estaVazia;
}