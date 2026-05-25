#include <stdio.h>

void bubblesort(int* v, int n) {
    int i, fim, pos;
    int chave;
    int troca;
    fim = n - 1;

    do {
        troca = 0;
        for (i = 0; i < fim; i++) {
            if (v[i] > v[i + 1]) {

                chave = v[i];
                v[i] = v[i + 1];
                v[i + 1] = chave;
                pos = i;
                troca = 1;
            }
        }
        fim = pos;
    } while (troca == 1);
}

void preencher(int* v) {
    int i;

    for (i = 0; i < 10; i++) {
        printf("Informe um numero: ");
        scanf("%d", &v[i]);
    }
}

void exibir(int* v) {
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
}

int main() {

    int numeros[10];

    printf("Preenchimento do vetor\n");

    preencher(numeros);

    bubblesort(numeros, 10);

    printf("Vetor ordenado em ordem crescente:\n");

    exibir(numeros);

    return 0;
}
