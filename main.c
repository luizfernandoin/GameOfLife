#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


const int TAMANHO = 50;

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

int calcularVizinhos(int matrix[TAMANHO][TAMANHO], int row, int col, int totVizinhos, int quadrante) {
    int totBacterias = 0;

    switch (totVizinhos) {
        case 3:
            switch(quadrante) {
                case 1:
                    for (int rowSub = (row - 1); rowSub <= row; rowSub++) {
                        for (int colSub = (col - 1); colSub <= col; colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            };
                        }
                    }
                    break;
                case 2:
                    for (int rowSub = (row - 1); rowSub <= row; rowSub++) {
                        for (int colSub = col; colSub <= (col+1); colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    for (int rowSub = row; rowSub <= (row+1); rowSub++) {
                        for (int colSub = (col - 1); colSub <= col; colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
                case 4:
                    for (int rowSub = row; rowSub <= (row+1); rowSub++) {
                        for (int colSub = col; colSub <= (col+1); colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
            }
            break;
        case 5:
            switch (quadrante) {
                case 1:
                    for (int rowSub = (row - 1); rowSub <= row; rowSub++) {
                        for (int colSub = (col-1); colSub <= (col+1); colSub++) {
                            if ((matrix[rowSub][colSub] == 1)) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
                case 2:
                    for (int rowSub = row; rowSub <= (row+1); rowSub++) {
                        for (int colSub = (col-1); colSub <= (col+1); colSub++) {
                            if (matrix[rowSub][colSub] == 1)  {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    for (int rowSub = row-1; rowSub <= (row+1); rowSub++) {
                        for (int colSub = (col-1); colSub <= (col); colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
                case 4:
                    for (int rowSub = row-1; rowSub <= (row+1); rowSub++) {
                        for (int colSub = col; colSub <= (col+1); colSub++) {
                            if (matrix[rowSub][colSub] == 1) {
                                if (rowSub != row || colSub != col) {
                                    totBacterias++;
                                }
                            }
                        }
                    }
                    break;
            }
            break;
        case 8:
            for (int rowSub = (row - 1); rowSub <= (row+1); rowSub++) {
                for (int colSub = (col - 1); colSub <= (col+1); colSub++) {
                    if (matrix[rowSub][colSub] == 1) {
                        if (rowSub != row || colSub != col) {
                            totBacterias++;
                        }
                    }
                }
            }
            break;
    }

    return totBacterias;
}

int proximaGeracao(int currentGenerationMatrix[TAMANHO][TAMANHO], int nextGenerationMatrix[TAMANHO][TAMANHO]) {
    int vizinhos = 0;
    int quadrante = 0;

    for (int row = 0; row < TAMANHO; row++) {
        for (int col = 0; col < TAMANHO; col++) {
            if ((row > 0 && row < (TAMANHO - 1)) && (col > 0 && col < (TAMANHO - 1))) {
                vizinhos = 8;
            } 
            else if (((row == 0 || row == TAMANHO - 1) && (col > 0 && col < TAMANHO-1)) || ((col == 0 || col == TAMANHO - 1) && (row > 0 && row<TAMANHO-1)) ) {
                vizinhos = 5;
                if (row == 0 && (col > 0 && col < TAMANHO-1)) quadrante = 2;
                else if (row == TAMANHO-1 && (col > 0 && col < TAMANHO-1)) quadrante = 1;
                else if (col == 0 && (row > 0 && row < TAMANHO-1)) quadrante = 4;
                else if (col == TAMANHO-1 && (row > 0 && row < TAMANHO-1)) quadrante = 3;
            } else {
                vizinhos = 3;
                if (row == 0 && col == 0) quadrante = 4;
                else if (row == 0 && col == TAMANHO-1) quadrante = 3;
                else if (row == TAMANHO-1 && col == 0) quadrante = 2;
                else quadrante = 1;
            }
            
            int totBacterias = calcularVizinhos(currentGenerationMatrix, row, col, vizinhos, quadrante);
        
            if (currentGenerationMatrix[row][col] == 0 && totBacterias == 3) {
                nextGenerationMatrix[row][col] = 1;
            } else if (currentGenerationMatrix[row][col] == 1 && totBacterias < 2) {
                nextGenerationMatrix[row][col] = 0;
            } else if (currentGenerationMatrix[row][col] == 1 && totBacterias > 3) {
                nextGenerationMatrix[row][col] = 0;
            } else if (currentGenerationMatrix[row][col] == 1 && (totBacterias == 2 || totBacterias == 3)) {
                nextGenerationMatrix[row][col] = 1;
            }

            quadrante = 0;
            vizinhos = 0;
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

    return estaVazia;
}


void main() {
    int currentGenerationMatrix[TAMANHO][TAMANHO];
    int nextGenerationMatrix[TAMANHO][TAMANHO];
    int resultado = 0;
    int cont = 0;
    
    fillRandom(currentGenerationMatrix);
    
    while (1)
    {   
        printMatrix(currentGenerationMatrix);
        if (resultado == 1) {
            break;
        }
        resultado = proximaGeracao(currentGenerationMatrix, nextGenerationMatrix);
        printf("Geracao: %d\n", cont);
        sleep(1);
        cont++;
    }
}