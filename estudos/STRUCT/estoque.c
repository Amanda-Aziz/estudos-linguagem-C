/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de controle de estoque que realiza o cadastro de produtos e
 * identifica aqueles cuja quantidade disponível está abaixo do limite mínimo
 * permitido para reposição.
 *
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário informa os dados de cada produto, incluindo código,
 *    descrição, fornecedor, quantidade mínima e quantidade em estoque.
 * 2. Armazenamento: As informações são registradas em um vetor de estruturas.
 * 3. Análise: O programa compara a quantidade real de cada produto com sua
 *    quantidade mínima permitida.
 * 4. Identificação: Os produtos com estoque abaixo do mínimo são selecionados.
 * 5. Saída: Exibe um relatório contendo os produtos que necessitam de reposição.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Structs: Utilização da estrutura Produto para agrupar informações de cada
 *   item do estoque.
 * - Constante: Definição da quantidade máxima de produtos através da diretiva
 *   #define TAM 500.
 * - Vetor de Estruturas: Armazenamento dos registros dos produtos em um array.
 * - Modularização: Separação da lógica em funções de cadastro e pesquisa.
 * - Manipulação de Strings: Uso de fgets() para leitura de textos e strcspn()
 *   para remoção do caractere de quebra de linha.
 * - Estruturas Condicionais: Verificação de produtos com estoque abaixo do
 *   limite mínimo estabelecido.
 * - Controle de Estoque: Comparação entre quantidade real e quantidade mínima.
 * - Variável Auxiliar: Utilização de um indicador para informar quando não há
 *   produtos com necessidade de reposição.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#define TAM 500

typedef struct {
    char codigo[8];
    char descricao[100];
    char fornecedor[50];
    int qtd_minima;
    int qtd_real;
} Produto;

void preencherCadastro(Produto vetor[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        printf("\n--- Cadastro do Produto %d ---\n", i + 1);
        
        printf("Código do produto: ");
        fgets(vetor[i].codigo, 8, stdin);
        vetor[i].codigo[strcspn(vetor[i].codigo, "\n")] = '\0'; // Apaga o Enter
        
        printf("Descrição: ");
        fgets(vetor[i].descricao, 100, stdin);
        vetor[i].descricao[strcspn(vetor[i].descricao, "\n")] = '\0';
        
        printf("Nome do fornecedor: ");
        fgets(vetor[i].fornecedor, 100, stdin);
        vetor[i].fornecedor[strcspn(vetor[i].fornecedor, "\n")] = '\0';
        
        printf("Quantidade mínima permitida: ");
        scanf("%d", &vetor[i].qtd_minima);
        
        printf("Quantidade real em estoque: ");
        scanf("%d", &vetor[i].qtd_real);
        
        getchar();
    }
}

void realizarPesquisa(Produto vetor[]) {
    int i;
    int encontrou = 0; // variavel auxiliar para avisar se nenhum produto estiver abaixo do estoque
    
    printf("\n===================================================\n");
    printf("     PRODUTOS COM ESTOQUE ABAIXO DO MÍNIMO PERMITIDO \n");
    printf("===================================================\n");
    
    for (i = 0; i < TAM; i++) {
        if (vetor[i].qtd_real < vetor[i].qtd_minima) {
            printf("Código: %s\n", vetor[i].codigo);
            printf("Descrição: %s\n", vetor[i].descricao);
            printf("Fornecedor: %s\n", vetor[i].fornecedor);
            printf("Estoque atual: %d (Mínimo exigido: %d)\n", vetor[i].qtd_real, vetor[i].qtd_minima);
            printf("---------------------------------------------------\n");
            encontrou = 1;
        }
    }
    
    if (encontrou == 0) {
        printf("Todos os produtos estão com o estoque regularizado!\n");
        printf("---------------------------------------------------\n");
    }
}

int main() {
    Produto listaProdutos[TAM];
    preencherCadastro(listaProdutos);
    realizarPesquisa(listaProdutos);
    return 0;
}
