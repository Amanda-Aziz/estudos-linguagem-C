/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de análise textual que recebe uma frase informada pelo usuário e
 * contabiliza a quantidade de vogais presentes no texto.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário digita uma frase de até 50 caracteres.
 * 2. Processamento: O programa percorre todos os caracteres da string.
 * 3. Conversão: Cada caractere é convertido para minúsculo para facilitar a
 *    comparação.
 * 4. Verificação: O sistema identifica se o caractere corresponde a uma das
 *    cinco vogais da língua portuguesa.
 * 5. Contagem: Cada vogal encontrada incrementa um contador.
 * 6. Saída: Exibe a quantidade total de vogais presentes na frase.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Strings: Utilização de um vetor de caracteres para armazenar a frase.
 * - Manipulação de Strings: Uso de fgets() para leitura da entrada e strlen()
 *   para determinar o tamanho da string.
 * - Biblioteca ctype.h: Aplicação da função tolower() para converter letras
 *   maiúsculas em minúsculas.
 * - Modularização: Separação da lógica de contagem em uma função específica.
 * - Estruturas de Repetição: Uso de laço for para percorrer a string.
 * - Estruturas Condicionais: Utilização de operadores lógicos para verificar
 *   se um caractere é uma vogal.
 * - Contadores: Registro da quantidade total de vogais encontradas.
 * - Processamento de Texto: Análise individual dos caracteres da frase.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
