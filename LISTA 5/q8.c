#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void inicializaMatriz(int **m, int linha, int coluna) {

    srand(time(NULL));

    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < coluna; j++) {

            *(*(m + k) + j) = rand() % MAX;

        }

    }


}

void exibeMatriz(int **m, int linha, int coluna) {

    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < coluna; j++) {

            printf("%5d", *(*(m + k) + j));

        }

        printf("\n");

    }


}

void geraMatrizS(int **m, int linha, int coluna) {

    int t;

    printf("Digite um limiar T: ");
    scanf("%d", &t);

    // CRIA MATRIZ S
    int **matrizS = (int**)malloc(linha * (sizeof(int*)));
    for (int k = 0; k < linha; k++) {

        matrizS[k] = malloc(coluna * sizeof(int));

    }

    // INICIALIZA MATRIZ S
    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < coluna; j++) {

           if(*(*(m + k) + j) > t) {

            *(*(matrizS + k) + j) = 1;

           } else {

                *(*(matrizS + k) + j) = 0;

           }

        }

    }

    // IMPRIME MATRIZ S
    printf("MATRIZ S...\n");
    for (int k = 0; k < linha; k++) {

        for (int j = 0; j < coluna; j++) {

            printf("%5d", *(*(matrizS + k) + j));

        }

        printf("\n");

    }


}


int main(int argc, char *argv[]) {

    int **matriz = NULL;

    if (argc != 3) {

        printf("Formato\n\t\t%s <valor1> <valor2>\n", argv[0]);
		exit(1);

    }

    int lin = atoi(argv[1]);
    int col = atoi(argv[2]);

    matriz = (int**)malloc(lin * (sizeof(int*)));

    for (int k = 0; k < lin; k++) {

        matriz[k] = malloc(col * sizeof(int));

    }

    inicializaMatriz(matriz, lin, col);
    exibeMatriz(matriz, lin, col);
    printf("\n");
    geraMatrizS(matriz, lin, col);

    return 0;

}