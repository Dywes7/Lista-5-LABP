#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


void inicializaMatriz(int **m, int linha) {

    srand(time(NULL));

    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < linha; j++) {

            *(*(m + k) + j) = rand() % MAX;

        }

    }


}

void diagonalMatiz(int **m, int linha) {

    int somatorio_diagonal = 0;

    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < linha; j++) {

            if (k == j) {

                somatorio_diagonal += *(*(m + k) + j);

            }
            

        }

    }

    if (!(somatorio_diagonal % 2)) {

        printf("Somatorio da diagonal principal: %d (PAR)\n", somatorio_diagonal);

    } else {

        printf("Somatorio da diagonal principal: %d (IMPAR)\n", somatorio_diagonal);

    }

}

void exibeMatriz(int **m, int linha) {

    printf("\n");
    
    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < linha; j++) {

            printf("%5d", *(*(m + k) + j));

        }

        printf("\n");

    }


}

int main(int argc, char *argv[]) {

    int **matriz = NULL;

    if (argc != 2) {

        printf("Formato\n\t\t%s <valor1>\n", argv[0]);
		exit(1);

    }

    int lin = atoi(argv[1]);

    matriz = (int**)malloc(lin * (sizeof(int*)));

    for (int k = 0; k < lin; k++) {

        matriz[k] = malloc(lin * sizeof(int));

    }

    inicializaMatriz(matriz, lin);
    exibeMatriz(matriz, lin);
    diagonalMatiz(matriz, lin);

    return 0;
}