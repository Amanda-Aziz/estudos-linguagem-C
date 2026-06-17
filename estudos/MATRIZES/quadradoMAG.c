#include <stdio.h>
#define ORDEM 10

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
    printf("\n=========== M A T R I Z ===========\n");
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            printf("%2d ", ma[i][j]);
        }
        printf("\n");
    }
}

int ehMagico(int mat[][ORDEM]) {
    int i, j;
    int somaReferencia = 0;
    int somaDiagonalPrincipal = 0;
    int somaDiagonalSecundaria = 0;

    //Calculando a soma da primeira linha para servir de referência
    for (j = 0; j < ORDEM; j++) {
        somaReferencia += mat[0][j];   // += para somar e guardar
    }

    //Verificando a soma de cada uma das linhas
    for (i = 0; i < ORDEM; i++) {
        int somaLinha = 0;
        for (j = 0; j < ORDEM; j++) {
            somaLinha += mat[i][j];
        }
        if (somaLinha != somaReferencia){
            return 0; // Soma diferente encontrada
        }
    }

    //Verificando a soma de cada uma das colunas
    for (j = 0; j < ORDEM; j++) {
        int somaColuna = 0;
        for (i = 0; i < ORDEM; i++) {
            somaColuna += mat[i][j];
        }
        if (somaColuna != somaReferencia) return 0;
    }

    //Verificando as diagonais principal e secundária
    for (i = 0; i < ORDEM; i++) {
        somaDiagonalPrincipal += mat[i][i];                  // [0][0], [1][1], [2][2]
        somaDiagonalSecundaria += mat[i][ORDEM - 1 - i];     // [0][2], [1][1], [2][0]
    }

    if (somaDiagonalPrincipal != somaReferencia) return 0;
    if (somaDiagonalSecundaria != somaReferencia) return 0;

    return 1; // Se passou por todos os testes corretamente.
}

int main(){
    int matriz[ORDEM][ORDEM];
    preencher(matriz);
    exibir(matriz);
    
    if(ehMagico(matriz) == 1){
        printf("\nÉ um quadrado mágico");
    } else {
        printf("\nNão é um quadrado mágico");
    }
    
    return 0;
}
