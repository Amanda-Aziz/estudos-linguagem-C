#include <stdio.h>
#define TAM 5

void preencherVetor(int vet[]){
    int i=0;
    for(i=0; i<TAM; i++){
        printf("Valor da posição %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void somarVetores(int vetA[], int vetB[], int vetC[]){
    int i;
    for(i=0; i<TAM; i++){
        vetC[i] = vetA[i]+vetB[i];
    }
}

void exibirVetor(int vetor[], char nome){
    int i;
    printf("Vetor %c: ", nome);
    for(i=0; i<TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int A[TAM], B[TAM], C[TAM];
    
    printf("\n--- PREENCHENDO O VETOR A ---\n");
    preencherVetor(A);
    printf("\n--- PREENCHENDO O VETOR B ---\n");
    preencherVetor(B);
       
    somarVetores(A, B, C);
    exibirVetor(A, 'A'); //vetor, seu 'nome' (A, B ou o C...)
    exibirVetor(B, 'B');
    exibirVetor(C, 'C');
    
    return 0;
}
