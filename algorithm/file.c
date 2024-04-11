#include "file.h"
#include <stdio.h>

void cenarioEntrada(int geracaoAtual[linhas][colunas]) {
    FILE *arquivo;
    arquivo = fopen("cenario.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas ; j++) {
            fscanf(arquivo, "%1d", &geracaoAtual[i][j]);
        }
    }
    
    fclose(arquivo);
}

void salvarCenario(int geracaoAtual[linhas][colunas]) {
    FILE *arquivo;
    arquivo = fopen("cenario.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(arquivo, "%d ", geracaoAtual[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}
