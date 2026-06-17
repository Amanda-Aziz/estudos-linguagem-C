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
