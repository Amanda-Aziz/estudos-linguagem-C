/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de busca em matrizes que gera uma matriz preenchida com números
 * aleatórios, procura um valor informado pelo usuário e exibe apenas as
 * posições onde esse valor foi encontrado.
 *
 * FUNCIONAMENTO:
 * 1. Geração: O programa cria uma matriz 10x15 preenchida com números
 *    aleatórios entre 1 e 10.
 * 2. Exibição: A matriz original é apresentada na tela.
 * 3. Pesquisa: O usuário informa um valor que deseja localizar.
 * 4. Processamento: O sistema percorre toda a matriz procurando ocorrências
 *    do número informado.
 * 5. Marcação: Uma segunda matriz registra com o valor 1 as posições onde o
 *    número foi encontrado.
 * 6. Saída: O programa exibe uma matriz filtrada, mostra as coordenadas das
 *    ocorrências e informa a quantidade total de vezes que o valor aparece.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constantes: Definição do número de linhas e colunas através das diretivas
 *   #define L 10 e #define C 15.
 * - Matrizes: Utilização de matrizes bidimensionais para armazenamento dos
 *   dados originais e das marcações de busca.
 * - Geração Aleatória: Uso das funções rand(), srand() e time() para criar
 *   valores aleatórios.
 * - Modularização: Separação da lógica em funções de preenchimento, exibição,
 *   pesquisa e relatório.
 * - Estruturas de Repetição: Aplicação de laços for aninhados para percorrer
 *   as matrizes.
 * - Estruturas Condicionais: Uso de if para identificar ocorrências do valor
 *   procurado.
 * - Busca Sequencial: Verificação de todos os elementos da matriz.
 * - Matrizes Auxiliares: Utilização de uma segunda matriz para registrar as
 *   posições encontradas.
 * - Contadores: Registro da quantidade total de ocorrências do número
 *   pesquisado.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h> //Contém as funções rand() e srand()
#include <time.h>   //Contém a função time()
#define L 10
#define C 15

void preencher(int vet[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            vet[i][j] = (rand() % 10)+1;
        }
    }
}

void exibir(int v[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%2d ", v[i][j]); // %2d para as colunas ficarem retas na tela
        }
        printf("\n");
    }
}

void procurar(int vetor[][C], int numero_procurado, int matriz_zerada[][C]){
    int i, j;
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++) {
            if(vetor[i][j] == numero_procurado){
                matriz_zerada[i][j] = 1; // Altera a matriz que veio por parâmetro
            }
        }
    }
}

void exibirZerada(int matZeros[][C], int matOriginal[][C], int numero_procurado){
    int i, j;
    int contador = 0;

    printf("\n============== MATRIZ FILTRADA ==============\n");
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++) {
            if(matZeros[i][j] == 1) {
                printf("%2d ", matOriginal[i][j]);
            } else { 
                printf(" 0 ");
            }
        }
        printf("\n"); 
    }
    printf("=============================================\n");
    
    //listagem de coordenadas idêntica ao modelo da imagem
    printf("\nPosições onde o valor %d foi encontrado:\n", numero_procurado);
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++) {
            if(matZeros[i][j] == 1) {
                printf("%d,%d\n", i, j); // Formato linha,coluna da foto
                contador++; 
            }
        }
    }
    printf("O valor procurado aparece %d vezes na matriz.\n", contador);
}


int main(){
    srand(time(NULL));  
    
    int A[L][C];
    int A_zerada[L][C] = {0};
    int valor_procurar;
    
    preencher(A);
    exibir(A);
    
    printf("\nDigite um valor (1 a 10): ");
    scanf("%d", &valor_procurar);
    
    procurar(A, valor_procurar, A_zerada);
    
    exibirZerada(A_zerada, A, valor_procurar);
    
    return 0;
}
