/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de operações com matrizes que realiza a soma de duas matrizes de
 * mesma dimensão e armazena o resultado em uma terceira matriz.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário preenche todos os elementos da matriz A.
 * 2. Entrada: O usuário preenche todos os elementos da matriz B.
 * 3. Processamento: O programa percorre as duas matrizes simultaneamente.
 * 4. Soma: Cada elemento da matriz C recebe a soma dos elementos
 *    correspondentes de A e B.
 * 5. Armazenamento: Os resultados são registrados na matriz C.
 * 6. Saída: O sistema exibe as matrizes A, B e C na tela.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constantes: Definição do número de linhas e colunas através das diretivas
 *   #define L 3 e #define C 4.
 * - Matrizes: Utilização de arrays bidimensionais para armazenamento dos
 *   dados.
 * - Modularização: Separação da lógica em funções de preenchimento, soma e
 *   exibição.
 * - Estruturas de Repetição: Uso de laços for aninhados para percorrer as
 *   matrizes.
 * - Operações Aritméticas: Soma dos elementos correspondentes das matrizes.
 * - Passagem de Matrizes por Parâmetro: Envio de matrizes para funções.
 * - Manipulação de Dados Bidimensionais: Processamento de linhas e colunas.
 * - Entrada e Saída de Dados: Utilização de scanf() e printf().
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#define L 3
#define C 4

//importante colocar pelo menos o numero de colunas!
void preencher(int mat[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("Valor na posição [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}

void somarMATRIZES(int matA[][C], int matB[][C], int matC[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void exibir(int matriz[][C], char nome){
    int i, j;
    printf("\nMatriz %c\n", nome);
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main ( ) {
    int a[L][C], b[L][C], c[L][C]; 
    
    printf("\nPREENCHENDO A MATRIZ A\n");
    preencher(a);
    printf("\nPREENCHENDO A MATRIZ B\n");
    preencher(b); 
    
    somarMATRIZES(a,b,c);
    
    printf("\n======== MATRIZES ========\n");
    exibir(a, 'A');
    exibir(b, 'B');
    exibir(c, 'C');
    
    return 0;
}
