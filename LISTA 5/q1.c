#include <stdio.h>
#include <stdlib.h>

typedef void (*Func)();

void somar(int, int, int*);
void multiplicar(int, int, int*);
void calcular (void (*pF) (int, int, int*), int a, int b, int *pR);

int main(int argc, char *argv[]) {

    if (argc != 4) {

        printf("Formato\n\t\t%s <valor1> <valor2> <codOper>\n",argv[0]);
		exit(1);

    }

    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int op = atoi(argv[3]);
    int r;

    
    Func v[] = {somar, multiplicar};

    calcular( v[op], n1, n2, &r);
    printf("Resultado: %d\n", r);

    return 0;


}

void somar(int n1, int n2, int *res) {

    *res = n1 + n2;

}

void multiplicar (int n1, int n2, int *res) {

    *res = n1 * n2;
    
}

void calcular (void (*pF) (int, int, int*), int a, int b, int *pR) {

    (*pF)(a, b, pR);

}