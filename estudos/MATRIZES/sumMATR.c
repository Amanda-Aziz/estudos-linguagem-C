#include <stdio.h>
#define L 3
#define C 4

//importante colocar pelo menos o numero de colunas!
void preencher(int mat[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("Valor na posição [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}

void somarMATRIZES(int matA[][C], int matB[][C], int matC[][C]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void exibir(int matriz[][C], char nome){
    int i, j;
    printf("\nMatriz %c\n", nome);
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main ( ) {
    int a[L][C], b[L][C], c[L][C]; 
    
    printf("\nPREENCHENDO A MATRIZ A\n");
    preencher(a);
    printf("\nPREENCHENDO A MATRIZ B\n");
    preencher(b); 
    
    somarMATRIZES(a,b,c);
    
    printf("\n======== MATRIZES ========\n");
    exibir(a, 'A');
    exibir(b, 'B');
    exibir(c, 'C');
    
    return 0;
}
