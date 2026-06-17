#include <stdio.h>
#define L 4
#define C 5

void preencher(int m[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("\nValor na posição [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void somaLINHA(int mat[][C], int somaLinha[]){
    int i, j;
    for(i=0; i<L; i++){
        somaLinha[i] = 0;
        for(j=0; j<C ; j++){
            somaLinha[i] = somaLinha[i]+mat[i][j];
        }
    }
}

void somaCOLUNA(int mat[][C], int somaColuna[]){
    int i, j;
    for(j=0; j<C; j++){
        somaColuna[j] = 0;
        for(i=0; i<L; i++){
            somaColuna[j] = somaColuna[j] + mat[i][j];
        }
    }
}

int somaTUDO(int vetL[]){
    int i;
    int total = 0;
    // Como a soma de todas as linhas é o total da matriz, somamos o vetor vetL
    for(i = 0; i < L; i++) {
        total = total + vetL[i];
    }
    return total; // Devolve a soma de tudo
}

int main(){
    int matriz[L][C];
    int vetor_linhas[L];   
    int vetor_colunas[C];
    int somA;
    int i; // Variável para os prints
    
    preencher(matriz);
    
    somaLINHA(matriz, vetor_linhas);
    somaCOLUNA(matriz, vetor_colunas);
    
    somA = somaTUDO(vetor_linhas);
    
    printf("\n====== SOMA DAS LINHAS =====\n"); 
    for(i = 0; i < L; i++) {
        printf("Linha %d: %d\n", i, vetor_linhas[i]);
    }
    
    printf("\n====== SOMA DAS COLUNAS =====\n");
    for(i = 0; i < C; i++) {
        printf("Coluna %d: %d\n", i, vetor_colunas[i]);
    }
    
    printf("\n=============================\n");
    printf("A soma total da matriz: %d\n", somA);
    printf("===============================\n");
    
    return 0;
}
