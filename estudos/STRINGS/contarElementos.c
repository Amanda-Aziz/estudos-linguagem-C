#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 101

void contarElementos(char frase[]) {
    int i;
    int letras = 0;
    int digitos = 0;
    int espaços = 0;
    int simbolos = 0;

    for (i=0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            letras++;
        } 
        else if (isdigit(frase[i])) {
            digitos++;
        } 
        else if (isspace(frase[i])) {
            espaços++;
        } 
        else {
            simbolos++;
        }
    }
    
    printf("\n===== RESULTADO DA CONTAGEM =====\n");
    printf("Letras: %d\n", letras);
    printf("Dígitos numéricos: %d\n", digitos);
    printf("Espaços: %d\n", espaços);
    printf("Símbolos: %d\n", simbolos);
    printf("=================================\n");
}

int main() {
    char frase[TAM];

    printf("Digite uma frase (max 100 caracteres): ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0';   //remover enter

    contarElementos(frase);

    return 0;
}
