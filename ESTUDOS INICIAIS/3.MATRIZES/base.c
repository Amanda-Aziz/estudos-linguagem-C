/******************************************************************************
 * DESCRIÇÃO:
 * Programa de manipulação de matrizes que realiza o preenchimento automático
 * dos elementos de uma matriz bidimensional e exibe seus valores utilizando
 * uma leitura transposta.
 *
 * FUNCIONAMENTO:
 * 1. Inicialização: O programa declara uma matriz de 3 linhas por 2 colunas.
 * 2. Preenchimento: Cada posição da matriz recebe a soma dos índices da linha
 *    e da coluna correspondentes.
 * 3. Processamento: Os valores são armazenados utilizando dois laços
 *    aninhados.
 * 4. Exibição: A matriz é percorrida trocando as posições de linha e coluna
 *    durante a impressão.
 * 5. Saída: Os elementos são apresentados em formato transposto em relação à
 *    organização original da matriz.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Matrizes: Utilização de um array bidimensional de inteiros.
 * - Estruturas de Repetição: Uso de laços for aninhados para preenchimento e
 *   exibição dos elementos.
 * - Índices de Matrizes: Manipulação das posições através das variáveis i e j.
 * - Operações Aritméticas: Preenchimento dos elementos por meio da soma dos
 *   índices da linha e da coluna.
 * - Transposição de Dados: Impressão dos elementos utilizando mat[j][i] em
 *   vez de mat[i][j].
 * - Entrada e Saída de Dados: Utilização de printf() para exibição dos
 *   resultados.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
int main ( ) {
    int mat [3][2],i,j;
    for(i = 0; i <= 2; i++) {
        for(j = 0; j <= 1; j++) {
            mat[i][j] = i + j;
        }
    }
    for(i = 0; i <= 1; i++) {
        for(j = 0; j <= 2; j++) {
            printf("%d ",mat[j][i]); //troca mat[i][j] por mat[j][i]
        }
        printf("\n");
    }
    return 0;
}
