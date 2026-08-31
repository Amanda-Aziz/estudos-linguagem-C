/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de manipulação de vetores inteiros que gera um segundo vetor a
 * partir dos valores de um vetor original, aplicando regras diferentes para
 * números pares e ímpares.
 *
 * FUNCIONAMENTO:
 * 1. Coleta: O usuário informa 10 valores inteiros para o vetor A.
 * 2. Processamento: O programa percorre o vetor A e gera o vetor B.
 * 3. Regra de Transformação:
 *    - Se o valor for par, divide-o por 2.
 *    - Se o valor for ímpar, multiplica-o por 3.
 * 4. Armazenamento: Os resultados são guardados nas respectivas posições do
 *    vetor B.
 * 5. Saída: Exibe os vetores A e B para comparação dos resultados.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho dos vetores através da diretiva
 *   #define TAM 10.
 * - Vetores: Utilização de dois arrays inteiros para armazenamento de dados.
 * - Modularização: Divisão da lógica em 3 funções principais.
 * - Estruturas de Repetição: Uso de laços for para preenchimento e exibição.
 * - Estruturas Condicionais: Uso do if/else para verificar se um número é
 *   par ou ímpar.
 * - Operador Módulo: Aplicação do operador % para identificação da paridade.
 * - Processamento de Dados: Criação de um novo vetor com base nos valores de
 *   outro vetor.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#define TAM 10

void preencherVetor(int vet[]){
    int i;
    printf("\n---- PREENCHENDO O VETOR A ----\n");
    for(i=0; i<TAM; i++){
        printf("Valor na posição %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void calcularB(int vA[], int vB[]){
    int i;
    for(i=0; i<TAM; i++){
        if(vA[i]%2 == 0){
            vB[i] = vA[i]/2;
        } else {
            vB[i] = vA[i]*3;
        }
    }
}

void exibir(int v[], char nome){
    int i;
    printf("Vetor %c: ", nome);
    for(i=0; i<TAM; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int A[TAM], B[TAM];
    
    preencherVetor(A);
    calcularB(A, B);
    
    printf("\n---- EXIBINDO VETORES ----\n");
    exibir(A, 'A');
    exibir(B, 'B');
    
    return 0;
}
