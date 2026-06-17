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
