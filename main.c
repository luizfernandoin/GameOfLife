#include "game_of_life.h"
#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int delay = 1;

void main(int argc, char* argv[]) {
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            char* chave = strtok(argv[i], "=");
            char* valor = strtok(NULL, "=");

            if (strcmp(chave, "rows") == 0) {
                setLinhas(atoi(valor));
            } else if (strcmp(chave, "cols") == 0) {
                setColunas(atoi(valor));
            } else if (strcmp(chave, "sleep") == 0) {
                delay = atoi(valor);
            }
        }
    }

    int currentGenerationMatrix[getLinhas()][getColunas()];
    int nextGenerationMatrix[getLinhas()][getColunas()];
    int resultado = 0;
    
    fillRandom(currentGenerationMatrix);
    //cenarioEntrada(currentGenerationMatrix);

    while (1)
    {   
        printMatrix(currentGenerationMatrix);
        if (resultado == 1) {
            break;
        }
        resultado = proximaGeracao(currentGenerationMatrix, nextGenerationMatrix);
        imprimirEstatisticasCenario();
        
        sleep(delay);
    }
}