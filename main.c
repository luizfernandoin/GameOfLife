#include "game_of_life.h"
#include "file.h"
#include <stdio.h>
#include <unistd.h>

void main() {
    int currentGenerationMatrix[TAMANHO][TAMANHO];
    int nextGenerationMatrix[TAMANHO][TAMANHO];
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
        sleep(1);
    }
}