#include <stdio.h>

void ordenar(float *a, float *b, float *c){
    float troca;
    if(*a > *b){
        troca = *a; 
        *a = *b; 
        *b = troca;
    }
    if(*a > *c){
        troca = *a; 
        *a = *c; 
        *c = troca; 
    }
    if(*b > *c){
        troca = *b; 
        *b = *c; 
        *c = troca;
    }
}

int main() {
    float A, B, C;
    
    printf("\nDigite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    printf("Digite o valor de C: ");
    scanf("%f", &C);
    
    ordenar(&A, &B, &C);
    
    printf("\n=== NOVOS VALORES ===");
    printf("\nNovo valor de A: %.1f", A);
    printf("\nNovo valor de B: %.1f", B);
    printf("\nNovo valor de C: %.1f", C);
    
    return 0;
}
