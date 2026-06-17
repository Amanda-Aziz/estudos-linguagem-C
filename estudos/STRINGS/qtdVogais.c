#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contar(char vogais[]){
    int i;
    int qtdVogais = 0;
    int cont = strlen(vogais); //strlen para contar o tamanho de uma string
    
    for(i=0; i<cont; i++){
        vogais[i] = tolower(vogais[i]);
        if(vogais[i] == 'a' || vogais[i] == 'e' || vogais[i] == 'i' || vogais[i] == 'o' || vogais[i] == 'u'){
            qtdVogais++;
        }
    }
    return qtdVogais;
}

int main(){
    char frase[51];
    int vogais = 0;
    
    printf("Digite uma frase: ");
    fgets(frase, 51, stdin);
    
    vogais = contar(frase);
    
    printf("\nTotal de %d vogais.", vogais);
    
    return 0;    
}
