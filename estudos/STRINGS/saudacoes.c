#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#define TAM 51

int validarNome(char name[]){
    int i;  
    for (i=0; name[i] != '\0'; i++){
        if (!isalpha(name[i]) && !isspace(name[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    char nome[TAM];
    
    printf("============================================\n");
    printf("Digite seu nome: ");
    fgets(nome, TAM, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    
    while(validarNome(nome) == 0){
        printf("Nome inválido. Digite novamente: ");
        fgets(nome, TAM, stdin);
    }
    
    printf("Olá, %s, prazer em te conhecer!\n", nome);
    
    return 0;
}
