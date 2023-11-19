#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void inicializaVetor(int *vetor, int tam) {

    srand(time(NULL));

    for (int i = 0; i < tam; i++) {

        *(vetor + i) = rand() % (MAX + 1); 

    }

}

void pegaMenorMaior(int *vetor, int tam, int *v) {

    int *adressMenor = NULL;
    int menorValor = *vetor;
    int *adressMaior = NULL;
    int maiorValor = *vetor;

    for (int i = 1; i < tam; i++) {

        if (menorValor > *(vetor + i)) {

            menorValor = *(vetor + i);
            adressMenor = vetor + i;

        }

        if (maiorValor < *(vetor + i)) {

            maiorValor = *(vetor + i);
            adressMaior = vetor + i;

        }

    }

    v[0] = menorValor;
    v[1] = maiorValor;


}

void imprimeVetor(int *vetor, int tam) {

    for (int i = 0; i < tam; i++) {

        printf("Vetor[%d]: %d\n", i, *(vetor + i));

    }

}

void normalizaMinMax(int *vetor, int tam, int *minmax) {

    for (int i = 0; i < tam; i++) {

        *(vetor + i) = (*(vetor + i) - minmax[0]) / (minmax[1] - minmax[0]);

    }

}


int main(int argc, char *argv[]) {

    int *elementos = NULL;
    int n;
    int vet[2];


    if (argc != 2) {

        printf("Formato\n\t\t%s <valor1>\n",argv[0]);
		exit(1);

    }

    n = atoi(argv[1]);

    if(!(elementos = (int*)malloc(n * sizeof(int)))) {

        puts("Não há memória disponível :(");
        exit(2);

    }

    inicializaVetor(elementos, n);
    printf("========ANTES============\n");
    imprimeVetor(elementos, n);
    pegaMenorMaior(elementos, n, vet);
    normalizaMinMax(elementos, n, vet);
    printf("========DEPOIS============\n");
    imprimeVetor(elementos, n);

    
}