/******************************************************************************
 * DESCRIÇÃO: 
 * Implementação do algoritmo Bubble Sort para ordenação de vetores inteiros.
 * 
 * FUNCIONAMENTO:
 * 1. Preenchimento: Solicita ao usuário 10 números inteiros.
 * 2. Ordenação: Organiza os elementos em ordem crescente usando Bubble Sort.
 * 3. Troca de Valores: Compara posições adjacentes e realiza trocas quando necessário.
 * 4. Exibição: Mostra o vetor já ordenado na tela.
 * 
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Algoritmo Bubble Sort: Método de ordenação baseado em comparações sucessivas.
 * - Vetores: Armazenamento e manipulação de números inteiros.
 * - Ponteiros: Uso de ponteiros para acessar e modificar posições do vetor.
 * - Estruturas de Repetição: Uso de for e do-while para percorrer e ordenar dados.
 * - Otimização Simples: Controle de trocas e redução do limite de comparação.
 * 
 * Autor/User: Amanda-Aziz
 * Data: 25 de Maio de 2026
 *******************************************************************************/

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
