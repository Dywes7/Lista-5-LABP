#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para gerar um número aleatório entre 0 e 1
double random_double() {
    return (double)rand() / RAND_MAX;
}

// Função para calcular o erro médio quadrático entre dois vetores
double calcularErroMedioQuadratico(double *vetorA, double *vetorB, int N) {

    double somaQuadrados = 0.0;

    for (int i = 0; i < N; i++) {

        double diferenca = vetorA[i] - vetorB[i];

        somaQuadrados += diferenca * diferenca;

    }

    return somaQuadrados / N;

}

int main() {

    // Defina a dimensão do vetor
    int N = 10;

    // Aloque dinamicamente memória para os vetores A e B
    double *vetorA = (double *)malloc(N * sizeof(double));
    double *vetorB = (double *)malloc(N * sizeof(double));

    // Inicialize os vetores com números aleatórios entre 0 e 1
    for (int i = 0; i < N; i++) {

        vetorA[i] = random_double();
        vetorB[i] = random_double();
        
    }

    // Calcule o erro médio quadrático
    double erroMedioQuadratico = calcularErroMedioQuadratico(vetorA, vetorB, N);

    // Imprima os vetores e o resultado
    printf("Vetor A: ");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", vetorA[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", vetorB[i]);
    }
    printf("\n");

    printf("Erro Médio Quadrático: %.4f\n", erroMedioQuadratico);

    // Libere a memória alocada
    free(vetorA);
    free(vetorB);

    return 0;
}
