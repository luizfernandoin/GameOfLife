#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


const int TAMANHO = 20;

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

    // for (int row = 0; row < TAMANHO; row++) {
    //     for (int col = 0; col < TAMANHO; col++) {
    //         printf("%d", matrix[row][col]);
    //     }
    //     printf("\n");
    // }
}

// void cenarioEntrada(int *geracaoAtual[TAMANHO]) {
//     //FILE *fopen (const char * "entrada.txt" , const char * access_mode );

// }

// void proximoCenario() {

// }



void main() {
    int currentGenerationMatrix[TAMANHO][TAMANHO];
    int nextGenerationMatrix[TAMANHO][TAMANHO];

    while (1) {
        fillRandom(currentGenerationMatrix);
        printMatrix(currentGenerationMatrix);
        sleep(1);
    }

}