/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de atualização de valores utilizando passagem de parâmetros por
 * referência, permitindo aplicar incrementos sucessivos a uma variável
 * informada pelo usuário.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa o valor inicial de X.
 * 2. Configuração: O usuário define o valor do incremento e a quantidade de
 *    vezes que ele será aplicado.
 * 3. Referência: O endereço de memória da variável X é enviado para a função.
 * 4. Processamento: O programa realiza a soma do incremento ao valor de X
 *    repetidamente, conforme a quantidade especificada.
 * 5. Atualização: A variável original é modificada diretamente através do
 *    ponteiro recebido pela função.
 * 6. Saída: O valor final de X é exibido após todas as atualizações.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Ponteiros: Utilização de parâmetros do tipo ponteiro para acessar e
 *   modificar variáveis externas à função.
 * - Passagem por Referência: Alteração direta da variável X através de seu
 *   endereço de memória.
 * - Operador de Endereço: Uso do operador & para obter o endereço da variável.
 * - Operador de Desreferenciação: Uso do operador * para acessar e modificar
 *   o conteúdo armazenado no endereço apontado.
 * - Estruturas de Repetição: Aplicação de um laço for para realizar múltiplos
 *   incrementos.
 * - Operações Aritméticas: Soma sucessiva de um valor de incremento.
 * - Modularização: Separação da lógica de processamento em uma função
 *   específica.
 * - Entrada e Saída de Dados: Utilização de scanf() e printf() para interação
 *   com o usuário.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

//Exercícios de passagem de parâmetros por referência

#include <stdio.h>

// O procedimento recebe X por referência (ponteiro) para poder alterá-lo
// O incremento e a quantidade são passados por valor (cópia)
void aplicarIncremento(int *X, int incremento, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        *X = *X + incremento; // Modifica diretamente o X da main
    }
}

int main() {
    int x_inicial, inc, qtd;

    printf("Digite o valor inicial de X: ");
    scanf("%d", &x_inicial);
    
    printf("\nDigite o valor do incremento: ");
    scanf("%d", &inc);
    
    printf("Digite a quantidade de vezes: ");
    scanf("%d", &qtd);

    // Chamada do procedimento: passamos o endereço de x_inicial (&) e os valores de inc e qtd
    aplicarIncremento(&x_inicial, inc, qtd);

    //Saída de dados feita na main
    printf("\nValor final de X: %d\n", x_inicial);

    return 0;
}
