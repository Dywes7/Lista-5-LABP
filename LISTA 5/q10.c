#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int *vetor, int tamanho, int limite) {

    for (int i = 0; i < tamanho; i++) {

        vetor[i] = rand() % limite;

    }
}

void preencherMatriz(int *matriz, int *X, int *Y, int tamanho) {

    for (int i = 0; i < tamanho; i++) {

        matriz[X[i] * tamanho + Y[i]]++;

    }
}

void imprimirMatriz(int *matriz, int tamanho) {

    for (int i = 0; i < tamanho; i++) {

        for (int j = 0; j < tamanho; j++) {

            printf("%d ", matriz[i * tamanho + j]);

        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {

        printf("Formato\n\t\t%s <valor1>\n", argv[0]);
		exit(1);

    }

    int N = atoi(argv[1]);
    
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
    int *M = (int *)calloc(N * N, sizeof(int));

    if (X == NULL || Y == NULL || M == NULL) {

        fprintf(stderr, "Erro na alocação de memória\n");

        exit(2);
    }

    preencherVetor(X, N, N);
    preencherVetor(Y, N, N);

    printf("X = [");
    for (int i = 0; i < N; i++) {

        printf("%d ", X[i]);

    }

    printf("]\n");

    printf("Y = [");
    for (int i = 0; i < N; i++) {

        printf("%d ", Y[i]);

    }
    printf("]\n");

    preencherMatriz(M, X, Y, N);

    printf("\nMatriz M:\n");
    imprimirMatriz(M, N);

    free(X);
    free(Y);
    free(M);

    return 0;

}
