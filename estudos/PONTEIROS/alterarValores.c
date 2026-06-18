/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de manipulação de variáveis utilizando ponteiros, permitindo a
 * alteração dos valores de duas variáveis inteiras através da passagem de
 * seus endereços de memória para uma função.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa os valores das variáveis X e Y.
 * 2. Referência: Os endereços de memória das variáveis são enviados para uma
 *    função através de ponteiros.
 * 3. Processamento: A função modifica diretamente os valores armazenados nas
 *    variáveis originais.
 * 4. Atualização: O valor de X passa a ser a soma entre X e Y.
 * 5. Atualização: O valor de Y passa a assumir o valor original de X.
 * 6. Saída: O programa exibe os novos valores das variáveis após a alteração.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Ponteiros: Utilização de parâmetros do tipo ponteiro para acessar e
 *   modificar variáveis fora da função principal.
 * - Passagem por Referência: Alteração direta dos valores armazenados na
 *   memória através dos endereços das variáveis.
 * - Operador de Endereço: Uso do operador & para obter os endereços de X e Y.
 * - Operador de Desreferenciação: Uso do operador * para acessar e modificar
 *   os valores apontados pelos ponteiros.
 * - Funções: Separação da lógica de processamento em uma função específica.
 * - Operações Aritméticas: Realização de soma e subtração para atualização dos
 *   valores das variáveis.
 * - Entrada e Saída de Dados: Utilização de scanf() e printf().
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>

void alterarValor(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
}

int main() {
    int x, y;

    printf("Digite um valor para X: ");
    scanf("%d", &x);
    printf("Digite um valor para Y: ");
    scanf("%d", &y);
    
    alterarValor(&x, &y);
    
    printf("\n===== NOVOS VALORES DE X E Y =====\n");
    printf("X: %d\n", x);
    printf("Y: %d", y);
    
    return 0;
}
