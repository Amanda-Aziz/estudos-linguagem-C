#include <stdio.h>
#define TAM 10
#include <string.h>

void preencherGAB(char gab[]){
    int i;
    for(i=0; i<TAM; i++){
        printf("Gabarito da %dº questão: ", i+1);
        scanf("%c", &gab[i]);
        getchar();
    }
    printf("\n");
}
void preencherRESP(char resp[]){
    int i;
    for(i=0; i<TAM; i++){
        printf("Resposta da %dº questão: ", i+1);
        scanf("%c", &resp[i]);
        getchar();
    }
    printf("\n");
}

int nota(char g[], char r[]){
    int i;
    int total = 0;
    for(i=0; i<TAM; i++){
        if(g[i] == r[i]){
            total++;
        }
    }
    printf("\nTotal de questões corretas: %d", total);
}

int main(){
    char gabarito[TAM], respostas[TAM];
    
    preencherGAB(gabarito);
    preencherRESP(respostas);
    
    printf("\n----------- NOTA FINAL -----------");
    nota(gabarito, respostas);
    
    return 0;
}
