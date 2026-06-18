/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de ordenação de números reais que recebe três valores informados
 * pelo usuário e os reorganiza em ordem crescente utilizando passagem de
 * parâmetros por referência.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa três valores reais (A, B e C).
 * 2. Referência: Os endereços de memória das variáveis são enviados para a
 *    função de ordenação.
 * 3. Comparação: O programa verifica a relação entre os valores utilizando
 *    estruturas condicionais.
 * 4. Troca: Quando necessário, os valores são permutados por meio de uma
 *    variável auxiliar.
 * 5. Ordenação: Ao final do processo, os valores ficam organizados do menor
 *    para o maior.
 * 6. Saída: O programa exibe os novos valores ordenados de A, B e C.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Ponteiros: Utilização de parâmetros ponteiros para modificar diretamente
 *   as variáveis da função principal.
 * - Passagem por Referência: Alteração dos valores originais através de seus
 *   endereços de memória.
 * - Operador de Endereço: Uso do operador & para enviar os endereços das
 *   variáveis para a função.
 * - Operador de Desreferenciação: Uso do operador * para acessar e modificar
 *   os valores apontados pelos ponteiros.
 * - Estruturas Condicionais: Aplicação de comandos if para realizar as
 *   comparações necessárias.
 * - Ordenação de Dados: Organização dos valores em ordem crescente.
 * - Variável Auxiliar: Utilização da variável troca para realizar a permuta
 *   entre os elementos.
 * - Manipulação de Números Reais: Uso do tipo float para armazenar e processar
 *   os valores.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>

void ordenar(float *a, float *b, float *c){
    float troca;
    if(*a > *b){
        troca = *a; 
        *a = *b; 
        *b = troca;
    }
    if(*a > *c){
        troca = *a; 
        *a = *c; 
        *c = troca; 
    }
    if(*b > *c){
        troca = *b; 
        *b = *c; 
        *c = troca;
    }
}

int main() {
    float A, B, C;
    
    printf("\nDigite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    printf("Digite o valor de C: ");
    scanf("%f", &C);
    
    ordenar(&A, &B, &C);
    
    printf("\n=== NOVOS VALORES ===");
    printf("\nNovo valor de A: %.1f", A);
    printf("\nNovo valor de B: %.1f", B);
    printf("\nNovo valor de C: %.1f", C);
    
    return 0;
}
