/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de análise de matrizes quadradas que verifica se uma matriz de
 * ordem 4 é simétrica, comparando seus elementos em relação à diagonal
 * principal.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa os valores de todos os elementos da matriz.
 * 2. Armazenamento: Os dados são registrados em uma matriz quadrada de ordem 4.
 * 3. Exibição: O programa apresenta a matriz preenchida na tela.
 * 4. Verificação: Cada elemento da posição [i][j] é comparado com o elemento
 *    correspondente da posição [j][i].
 * 5. Análise: Caso todos os pares comparados sejam iguais, a matriz é
 *    considerada simétrica.
 * 6. Saída: O sistema informa se a matriz é ou não simétrica.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição da ordem da matriz através da diretiva
 *   #define ORDEM 4.
 * - Matrizes: Utilização de um array bidimensional para armazenamento dos
 *   elementos.
 * - Modularização: Separação da lógica em funções de preenchimento, exibição
 *   e verificação.
 * - Estruturas de Repetição: Uso de laços for aninhados para percorrer a
 *   matriz.
 * - Estruturas Condicionais: Aplicação de if para verificar a condição de
 *   simetria.
 * - Comparação de Dados: Verificação da igualdade entre elementos simétricos.
 * - Conceito de Matriz Simétrica: Análise da relação entre os elementos
 *   a[i][j] e a[j][i].
 * - Retorno de Funções: Uso de valores inteiros para indicar verdadeiro (1)
 *   ou falso (0).
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#define ORDEM 4

void preencher(int m[][ORDEM]){
    int i,j;
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void exibir(int ma[][ORDEM]){
    int i,j;
    printf("\n===== M A T R I Z =====\n");
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("%2d ", ma[i][j]);
        }
        printf("\n");
    }
}

int ehSimetrica(int mat[][ORDEM]){
    for (int i = 0; i < ORDEM; i++) {
        for (int j = 0; j < ORDEM; j++) {
            // Se algum elemento a_ij for diferente de a_ji, não é simétrica
            if (mat[i][j] != mat[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int matriz[ORDEM][ORDEM];
    preencher(matriz);
    
    exibir(matriz);
    
    if(ehSimetrica(matriz) == 1){
        printf("\nÉ simétrica.");
    } else {
        printf("\nNão é simétrica.");
    }
    
    return 0;
}
