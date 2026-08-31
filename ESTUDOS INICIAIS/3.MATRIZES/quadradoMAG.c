/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de verificação de quadrado mágico que analisa uma matriz quadrada
 * de ordem 10 e determina se a soma de todas as linhas, colunas e diagonais
 * principais é igual.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa os valores de todos os elementos da matriz.
 * 2. Armazenamento: Os dados são registrados em uma matriz quadrada 10x10.
 * 3. Exibição: A matriz preenchida é apresentada na tela.
 * 4. Referência: O programa calcula a soma da primeira linha para servir como
 *    valor de comparação.
 * 5. Verificação: São calculadas as somas de todas as linhas, colunas e das
 *    duas diagonais da matriz.
 * 6. Saída: O sistema informa se a matriz representa ou não um quadrado
 *    mágico.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição da ordem da matriz através da diretiva
 *   #define ORDEM 10.
 * - Matrizes: Utilização de um array bidimensional para armazenamento dos
 *   elementos.
 * - Modularização: Separação das tarefas em funções de preenchimento,
 *   exibição e verificação.
 * - Estruturas de Repetição: Uso de laços for aninhados para percorrer a
 *   matriz.
 * - Estruturas Condicionais: Aplicação de if para validar as somas.
 * - Comparação de Dados: Verificação da igualdade entre linhas, colunas e
 *   diagonais.
 * - Diagonal Principal: Soma dos elementos das posições [i][i].
 * - Diagonal Secundária: Soma dos elementos das posições
 *   [i][ORDEM - 1 - i].
 * - Retorno Lógico: Utilização dos valores 1 (verdadeiro) e 0 (falso) para
 *   indicar se a matriz é um quadrado mágico.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#define ORDEM 10

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
    printf("\n=========== M A T R I Z ===========\n");
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("%2d ", ma[i][j]);
        }
        printf("\n");
    }
}

int ehMagico(int mat[][ORDEM]) {
    int i, j;
    int somaReferencia = 0;
    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;

    //Calculando a soma da primeira linha para servir de referência
    for (j = 0; j < ORDEM; j++) {
        somaReferencia += mat[0][j];   // += para somar e guardar
    }

    //Verificando a soma de cada uma das linhas
    for (i = 0; i < ORDEM; i++) {
        int somaLinha = 0;
        for (j = 0; j < ORDEM; j++) {
            somaLinha += mat[i][j];
        }
        if (somaLinha != somaReferencia){
            return 0; // Soma diferente encontrada
        }
    }

    //Verificando a soma de cada uma das colunas
    for (j = 0; j < ORDEM; j++) {
        int somaColuna = 0;
        for (i = 0; i < ORDEM; i++) {
            somaColuna += mat[i][j];
        }
        if (somaColuna != somaReferencia) return 0;
    }

    //Verificando as diagonais principal e secundária
    for (i = 0; i < ORDEM; i++) {
        somaDiagonalPrincipal += mat[i][i];                  // [0][0], [1][1], [2][2]
        somaDiagonalSecundaria += mat[i][ORDEM - 1 - i];     // [0][2], [1][1], [2][0]
    }

    if (somaDiagonalPrincipal != somaReferencia) return 0;
    if (somaDiagonalSecundaria != somaReferencia) return 0;

    return 1; // Se passou por todos os testes corretamente.
}

int main(){
    int matriz[ORDEM][ORDEM];
    preencher(matriz);
    exibir(matriz);
    
    if(ehMagico(matriz) == 1){
        printf("\nÉ um quadrado mágico");
    } else {
        printf("\nNão é um quadrado mágico");
    }
    
    return 0;
}
