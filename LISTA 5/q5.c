#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void inicializaVetor(float *vetor, int tam) {

    srand(time(NULL));

    for (int i = 0; i < tam; i++) {

        *(vetor + i) = ((float)rand() / RAND_MAX) * 100; 

    }

}

void imprimeVetor(float *vetor, int tam) {

    for (int i = 0; i < tam; i++) {

        printf("Vetor[%d]: %.2f\n", i, *(vetor + i));

    }

}

void somaVetor(float *vetor, int tam, float *res) {

    for (int i = 0; i < tam; i++) {

        *res += *(vetor + i); 

    }

}


int main(int argc, char *argv[]) {

    float *elementos = NULL;
    float soma = 0;
    int n;

    if (argc != 2) {

        printf("Formato\n\t\t%s <valor1>\n",argv[0]);
		exit(1);

    }

    n = atoi(argv[1]);

    if(!(elementos = (float*)malloc(n * sizeof(float)))) {

        puts("Não há memória disponível :(");
        exit(2);

    }

    inicializaVetor(elementos, n);
    imprimeVetor(elementos, n);
    somaVetor(elementos, n, &soma);

    printf("\nRESULTADO DA SOMA: %.2f\n", soma);




}