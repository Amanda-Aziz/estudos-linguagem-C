/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de análise textual que recebe uma frase informada pelo usuário e
 * realiza a contagem dos diferentes tipos de caracteres presentes nela.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário digita uma frase de até 100 caracteres.
 * 2. Processamento: O programa percorre cada caractere da string.
 * 3. Classificação: Cada caractere é identificado como letra, dígito,
 *    espaço em branco ou símbolo.
 * 4. Contagem: Os totais de cada categoria são armazenados em variáveis
 *    contadoras.
 * 5. Saída: Exibe um relatório com a quantidade de letras, números,
 *    espaços e símbolos encontrados na frase.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho máximo da string através da diretiva
 *   #define TAM 101.
 * - Strings: Utilização de um vetor de caracteres para armazenar a frase.
 * - Manipulação de Strings: Uso de fgets() para leitura da entrada e
 *   strcspn() para remoção do caractere de quebra de linha.
 * - Estruturas de Repetição: Uso de um laço for para percorrer a string.
 * - Biblioteca ctype.h: Aplicação das funções isalpha(), isdigit() e
 *   isspace() para classificação dos caracteres.
 * - Estruturas Condicionais: Utilização de if/else para determinar a
 *   categoria de cada caractere.
 * - Contadores: Registro da quantidade de elementos encontrados em cada
 *   classificação.
 * - Processamento de Texto: Análise individual dos caracteres de uma frase.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
