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

int *pegaEnderecoDoMenor(int *vetor, int tam) {

    int *adressMenor = NULL;
    int menorValor = *vetor;

    for (int i = 1; i < tam; i++) {

        if (menorValor > *(vetor + i)) {

            menorValor = *(vetor + i);
            adressMenor = vetor + i;

        }

    }

    return adressMenor;

}

void imprimeVetor(int *vetor, int tam) {

    for (int i = 0; i < tam; i++) {

        printf("Valor: %d, Endereco: %p\n", *(vetor + i), vetor + i);

    }

}


int main(int argc, char *argv[]) {

    int *elementos = NULL;
    int n;

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
    imprimeVetor(elementos, n);
    
    printf("\nO endereco do menor valor é: %p\n", pegaEnderecoDoMenor(elementos, n));

    
}