/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de operações com vetores inteiros que realiza a soma dos elementos
 * correspondentes de dois vetores e armazena o resultado em um terceiro vetor.
 *
 * FUNCIONAMENTO:
 * 1. Coleta: O usuário informa os valores dos vetores A e B.
 * 2. Processamento: O programa soma os elementos de mesma posição dos vetores.
 * 3. Armazenamento: Cada resultado é guardado na posição correspondente do
 *    vetor C.
 * 4. Saída: Exibe os vetores A, B e C para visualização dos dados e dos
 *    resultados obtidos.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho dos vetores através da diretiva
 *   #define TAM 5.
 * - Vetores: Utilização de três arrays inteiros para armazenamento de dados.
 * - Modularização: Divisão da lógica em funções específicas para preenchimento,
 *   processamento e exibição.
 * - Estruturas de Repetição: Uso de laços for para percorrer os vetores.
 * - Operações Aritméticas: Realização da soma entre elementos correspondentes.
 * - Manipulação de Vetores: Criação de um vetor resultante a partir de outros
 *   dois vetores.
 * - Passagem de Parâmetros: Utilização de vetores como argumentos de funções.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#define TAM 5

void preencherVetor(int vet[]){
    int i=0;
    for(i=0; i<TAM; i++){
        printf("Valor da posição %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void somarVetores(int vetA[], int vetB[], int vetC[]){
    int i;
    for(i=0; i<TAM; i++){
        vetC[i] = vetA[i]+vetB[i];
    }
}

void exibirVetor(int vetor[], char nome){
    int i;
    printf("Vetor %c: ", nome);
    for(i=0; i<TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int A[TAM], B[TAM], C[TAM];
    
    printf("\n--- PREENCHENDO O VETOR A ---\n");
    preencherVetor(A);
    printf("\n--- PREENCHENDO O VETOR B ---\n");
    preencherVetor(B);
       
    somarVetores(A, B, C);
    exibirVetor(A, 'A'); //vetor, seu 'nome' (A, B ou o C...)
    exibirVetor(B, 'B');
    exibirVetor(C, 'C');
    
    return 0;
}
