#include "file.h"
#include <stdio.h>

void cenarioEntrada(int geracaoAtual[TAMANHO][TAMANHO]) {
    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fscanf(arquivo, "%1d", &geracaoAtual[i][j]);
        }
    }
    
    fclose(arquivo);
}
