/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de gerenciamento de produtos que permite cadastrar, visualizar e
 * buscar produtos por código através de um menu interativo.
 *
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário informa nome, código e preço de cada produto.
 * 2. Armazenamento: Os dados são guardados em um vetor de estruturas.
 * 3. Consulta: O sistema permite exibir todos os produtos cadastrados.
 * 4. Pesquisa: O usuário pode informar um código para localizar um produto
 *    específico.
 * 5. Saída: As informações dos produtos são exibidas conforme a opção
 *    selecionada no menu principal.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Structs: Utilização da estrutura Produto para agrupar os dados de cada
 *   produto.
 * - Constantes: Definição dos limites de produtos e tamanho dos nomes através
 *   das diretivas #define TAM e #define TAM_NOME.
 * - Vetor de Estruturas: Armazenamento dos produtos em um array de registros.
 * - Modularização: Separação das funcionalidades em funções de cadastro,
 *   exibição e busca.
 * - Manipulação de Strings: Uso de fgets() para leitura de nomes e strcspn()
 *   para remoção do caractere de quebra de linha.
 * - Estruturas de Repetição: Utilização de laços for e do...while para
 *   percorrer os dados e controlar o menu.
 * - Estruturas Condicionais: Uso de if e switch/case para validação e controle
 *   das operações.
 * - Busca Sequencial: Pesquisa de produtos por código percorrendo o vetor.
 * - Menus Interativos: Interface textual para navegação entre as opções do
 *   sistema.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <string.h>

#define TAM 3
#define TAM_NOME 50

typedef struct produto{
    char nome[TAM_NOME];
    int codigo;
    float preco;
} Produto;

void cadastrar(Produto produtos[]){
    printf("\n=====================================\n");
    printf("      CADASTRO DE PRODUTOS\n");
    printf("=====================================\n");

    for(int i = 0; i < TAM; i++){

        printf("\nProduto %d\n", i + 1);
        printf("-------------------------------------\n");

        printf("Nome   : ");
        fgets(produtos[i].nome, TAM_NOME, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Codigo : ");
        scanf("%d", &produtos[i].codigo);

        printf("Preco  : R$ ");
        scanf("%f", &produtos[i].preco);

        getchar();
    }

    printf("\nProdutos cadastrados com sucesso!\n");
}

void exibir(Produto produtos[], int cadastrados){

    if(cadastrados == 0){
        printf("\nNenhum produto cadastrado!\n");
        return;
    }

    printf("\n=====================================\n");
    printf("       LISTA DE PRODUTOS\n");
    printf("=====================================\n");

    for(int i = 0; i < TAM; i++){

        printf("\n-------------------------------------\n");
        printf("Produto %d\n", i + 1);
        printf("-------------------------------------\n");

        printf("Nome   : %s\n", produtos[i].nome);
        printf("Codigo : %d\n", produtos[i].codigo);
        printf("Preco  : R$ %.2f\n", produtos[i].preco);
    }
}

void buscar(Produto produtos[], int cadastrados){

    if(cadastrados == 0){
        printf("\nNenhum produto cadastrado!\n");
        return;
    }

    int cod;

    printf("\n=====================================\n");
    printf("         BUSCAR PRODUTO\n");
    printf("=====================================\n");

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    for(int i = 0; i < TAM; i++){

        if(produtos[i].codigo == cod){

            printf("\n=====================================\n");
            printf("      PRODUTO ENCONTRADO!\n");
            printf("=====================================\n");

            printf("Nome   : %s\n", produtos[i].nome);
            printf("Codigo : %d\n", produtos[i].codigo);
            printf("Preco  : R$ %.2f\n", produtos[i].preco);

            return;
        }
    }

    printf("\nProduto nao encontrado.\n");
}

int main(){

    Produto produtos[TAM];
    int opcao;
    int cadastrados = 0;

    do{

        printf("\n");
        printf("=====================================\n");
        printf("      SISTEMA DE PRODUTOS\n");
        printf("=====================================\n");
        printf("[1] Cadastrar produtos\n");
        printf("[2] Exibir produtos\n");
        printf("[3] Buscar produto por codigo\n");
        printf("[0] Sair\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch(opcao){

            case 1:
                cadastrar(produtos);
                cadastrados = 1;
                break;

            case 2:
                exibir(produtos, cadastrados);
                break;

            case 3:
                buscar(produtos, cadastrados);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
