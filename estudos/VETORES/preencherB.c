#include <stdio.h>
#define TAM 10

void preencherVetor(int vet[]){
    int i;
    printf("\n---- PREENCHENDO O VETOR A ----\n");
    for(i=0; i<TAM; i++){
        printf("Valor na posição %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void calcularB(int vA[], int vB[]){
    int i;
    for(i=0; i<TAM; i++){
        if(vA[i]%2 == 0){
            vB[i] = vA[i]/2;
        } else {
            vB[i] = vA[i]*3;
        }
    }
}

void exibir(int v[], char nome){
    int i;
    printf("Vetor %c: ", nome);
    for(i=0; i<TAM; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int A[TAM], B[TAM];
    
    preencherVetor(A);
    calcularB(A, B);
    
    printf("\n---- EXIBINDO VETORES ----\n");
    exibir(A, 'A');
    exibir(B, 'B');
    
    return 0;
}
