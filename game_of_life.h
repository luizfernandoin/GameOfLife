#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

extern int linhas;
extern int colunas;

void setLinhas(int numLinhas);
void setColunas(int numColunas);
int getLinhas();
int getColunas();
int randomNumber();
void fillRandom(int currentGenerationMatrix[linhas][colunas]);
void printMatrix(int matrix[linhas][colunas]);
void imprimirEstatisticasCenario();
int calcularVizinhos(int matrix[linhas][colunas], int row, int col);
int proximaGeracao(int currentGenerationMatrix[linhas][colunas], int nextGenerationMatrix[linhas][colunas]);
int transferirDados(int currentGenerationMatrix[linhas][colunas], int nextGenerationMatrix[linhas][colunas]);

#endif
