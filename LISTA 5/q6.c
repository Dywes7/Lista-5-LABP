#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20


void inicializarVetor(int *vetor, int tamanho) {

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {

        *(vetor + i) = rand() % (MAX + 1);

    }

}

void exibirVetor (int *vetor, int tamanho) {

    printf("\n");

    for (int i = 0; i < tamanho; i++) {

        printf("Vetor[%d]: %d\n", i, *(vetor + i));

    }

}

float retornaMedia (int *vetor, int tamanho) {

    float media = 0;

    for (int i = 0; i < tamanho; i++) {

        media += *(vetor + i);

    }

    return media / tamanho;

}

void reordenaVetor(int *vet, int tamanho) {

    for (int k = 0; k < tamanho; k++) {

        for (int j = 0; j < tamanho - 1; j++) {

            if (*(vet + j) > *(vet + j + 1)) {

                *(vet + j) = *(vet + j) ^ *(vet + j + 1);
                *(vet + j + 1) = *(vet + j) ^ *(vet + j + 1);
                *(vet + j) = *(vet + j) ^ *(vet + j + 1);

            }

        }

    }

}

float retornaMediana(int *vetor, int tamanho) {

    float mediana;

    if (!(tamanho % 2)) {

        mediana = (*(vetor + (tamanho / 2)) + *(vetor + ((tamanho / 2) - 1))) / 2;

    } else {

        mediana = *(vetor + (tamanho / 2));

    }

    return mediana;

}

int retornaModa(int *vetor, int tamanho) {

    int *newVetor = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {

        *(newVetor + i) = 0;

        for (int j = 0; j < tamanho; j++) {

            if (*(vetor + i) == *(vetor + j)) {

                (*(newVetor + i))++;

            }

        }

    }

    int maiorValor = *newVetor;
    int indice;
    for (int i = 1; i < tamanho; i++) {

        if (maiorValor < *(newVetor + i)) {

            maiorValor = *(newVetor + i);
            indice = i;

        }

    }

    return *(vetor + indice);

}

int main(int argc, char *argv[]) {

    int *vet = NULL;

    if (argc != 2) {

        printf("Formato\n\t\t%s <valor1>\n",argv[0]);
		exit(1);

    }

    int tam = atoi(argv[1]);

    if (!(vet = (int*)malloc(tam * (sizeof(int))))) {

        puts("Não há memória disponível :(");
        exit(2);

    }

    inicializarVetor(vet, tam);
    reordenaVetor(vet, tam);
    exibirVetor(vet, tam);
   
    printf("\nMEDIA DO VETOR: %.2f\n", retornaMedia(vet, tam));
    printf("MEDIANA DO VETOR: %.2f\n", retornaMediana(vet , tam));
    printf("MODA DO VETOR: %d\n", retornaModa(vet, tam));

    free(vet);

    return 0;


}