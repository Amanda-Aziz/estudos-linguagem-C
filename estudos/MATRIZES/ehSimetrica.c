#include <stdio.h>
#define ORDEM 4

void preencher(int m[][ORDEM]){
    int i,j;
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void exibir(int ma[][ORDEM]){
    int i,j;
    printf("\n===== M A T R I Z =====\n");
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("%2d ", ma[i][j]);
        }
        printf("\n");
    }
}

int ehSimetrica(int mat[][ORDEM]){
    for (int i = 0; i < ORDEM; i++) {
        for (int j = 0; j < ORDEM; j++) {
            // Se algum elemento a_ij for diferente de a_ji, não é simétrica
            if (mat[i][j] != mat[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int matriz[ORDEM][ORDEM];
    preencher(matriz);
    
    exibir(matriz);
    
    if(ehSimetrica(matriz) == 1){
        printf("\nÉ simétrica.");
    } else {
        printf("\nNão é simétrica.");
    }
    
    return 0;
}
