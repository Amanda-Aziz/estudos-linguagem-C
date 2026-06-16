//fread(onde_guardar, tamanho, quantidade, arquivo);

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char codigo[50];   
    char descricao[200];
    float preco;
    int estoque;
} Produto;

int main() {
    //abre o arquivo binário em modo de leitura ("rb")
    FILE *arquivo = fopen("produtos.dat", "rb");
    //verifica se o arquivo existe e foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo produtos.dat\n");
        return 1; //forma de indicar que o programa terminou com erro
    }

    Produto p;
    int encontrou = 0;

    printf("--- PRODUTOS COM ESTOQUE ZERADO ---\n");
    //le os produtos do arquivo um por um até o fim (fread retorna 1 a cada leitura bem-sucedida)
    //while: enquanto conseguir ler um produto do arquivo...
    //enquanto o fread() conseguir ler 1 (==1) produto do arquivo, execute o laço...
    while (fread(&p, sizeof(Produto), 1, arquivo) == 1) {
        //verifica se a quantidade em estoque esta zerada
        if (p.estoque == 0) {
            printf("Código: %s | Descrição: %s\n", p.codigo, p.descricao);
            encontrou = 1;
        }
    }
    
    if (encontrou == 0) {
        printf("Nenhum produto com estoque zerado foi encontrado.\n");
    }
    
    fclose(arquivo);

    return 0;
}
