/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de comparação numérica que recebe quatro valores inteiros e
 * determina qual é o maior e qual é o menor entre eles utilizando ponteiros
 * para retornar os resultados.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário informa quatro números inteiros.
 * 2. Armazenamento: Os valores são organizados em um vetor auxiliar dentro da
 *    função de processamento.
 * 3. Inicialização: O primeiro valor é considerado inicialmente como maior e
 *    menor.
 * 4. Comparação: O programa percorre os demais valores comparando-os com os
 *    valores armazenados como maior e menor.
 * 5. Atualização: Sempre que um valor maior ou menor é encontrado, as
 *    variáveis correspondentes são atualizadas.
 * 6. Saída: O programa exibe o maior e o menor valor informados pelo usuário.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Ponteiros: Utilização de parâmetros ponteiros para retornar múltiplos
 *   resultados por meio da função.
 * - Passagem por Referência: Alteração direta das variáveis maior e menor
 *   através de seus endereços de memória.
 * - Vetores: Uso de um array auxiliar para armazenar os quatro valores.
 * - Estruturas de Repetição: Aplicação de um laço for para percorrer os
 *   elementos do vetor.
 * - Estruturas Condicionais: Utilização de if para identificar os maiores e
 *   menores valores.
 * - Comparação Numérica: Análise dos elementos para determinar extremos.
 * - Funções: Separação da lógica de processamento da função principal.
 * - Entrada e Saída de Dados: Uso de scanf() e printf() para interação com o
 *   usuário.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>

void MaiorMenor(int v1,int v2,int v3,int v4, int *maior, int *menor){
    int valores[4] = {v1,v2,v3,v4};
    *maior = v1;
    *menor = v1;
    for(int i=1; i<4; i++){
        if(valores[i] > *maior){
            *maior = valores[i];
        }
        if(valores[i] < *menor){
            *menor = valores[i];
        }
    }
}


int main() {
    int a, b, c, d, max, min;
    printf("Informe um valor: ");
    scanf("%d", &a);
    printf("Informe um valor: ");
    scanf("%d", &b);
    printf("Informe um valor: ");
    scanf("%d", &c);
    printf("Informe um valor: ");
    scanf("%d", &d);

    MaiorMenor(a, b, c, d, &max, &min); //max e min ainda não têm valor, eles vão receber valores dentro da função

    printf("\nMenor valor: %d\nMaior valor: %d\n", min, max);
    return 0;
}
