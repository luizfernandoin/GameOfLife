#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

extern const int TAMANHO;

int randomNumber();
void fillRandom(int currentGenerationMatrix[TAMANHO][TAMANHO]);
void printMatrix(int matrix[TAMANHO][TAMANHO]);
void imprimirEstatisticasCenario();
int calcularVizinhos(int matrix[TAMANHO][TAMANHO], int row, int col);
int proximaGeracao(int currentGenerationMatrix[TAMANHO][TAMANHO], int nextGenerationMatrix[TAMANHO][TAMANHO]);
int transferirDados(int currentGenerationMatrix[TAMANHO][TAMANHO], int nextGenerationMatrix[TAMANHO][TAMANHO]);

#endif
