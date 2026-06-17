#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 51

void substituirPorMaiuscula(char frase[], char letra){
    int i;
    char letraBusca = tolower(letra);
    
    for(i=0; frase[i] != '\0'; i++){
        if(tolower(frase[i]) == letraBusca){
            frase[i] = toupper(frase[i]);
        }
    }
}

int main() {
    char frase[TAM];
    char letra;
    
    printf("\nDigite uma frase (max 50 caracteres): ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    
    while(!isalpha(letra)){
        printf("\nEntrada inválida! Você DEVE digitar uma LETRA: ");
        scanf(" %c", &letra);
    }
    
    substituirPorMaiuscula(frase, letra);
    printf("\nFrase alterada: %s\n", frase);    
    return 0;
}
