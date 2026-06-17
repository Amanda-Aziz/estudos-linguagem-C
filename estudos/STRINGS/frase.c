#include <stdio.h>
#include <string.h>
#include <ctype.h>
//100 caracteres + 1 para o caractere nulo '\0'
#define TAM 101

void digitar(char fr[]){
    printf("\nDigite uma frase (max 100 caracteres): ");
    fgets(fr, TAM, stdin);
}

int procurarCARACT(char fra[], char letra){
    int i;
    int contador = 0;
            // vvvvv "Continue rodando o laço ENQUANTO a letra atual da frase NÃO FOR o fim do texto"
    for(i=0; fra[i] != '\0'; i++){
        if(fra[i] == letra){
            contador++;
        }
    }
    return contador;
}

int main(){
    char frase[TAM];
    char caractere;
    int resultado;
    
    digitar(frase);
    
    printf("Digite um caractere para buscar: ");
    scanf(" %c", &caractere);
    
    resultado = procurarCARACT(frase, caractere);
    
    printf("\nO caractere '%c' aparece %d vez(es) na frase.\n", caractere, resultado);
    return 0;    
}
