/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de manipulação de texto que permite ao usuário informar uma frase e
 * uma letra específica, convertendo para maiúsculo todas as ocorrências dessa
 * letra encontradas no texto.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário digita uma frase de até 50 caracteres.
 * 2. Validação: O programa solicita uma letra e verifica se a entrada é um
 *    caractere alfabético válido.
 * 3. Processamento: A frase é percorrida caractere por caractere.
 * 4. Comparação: Cada letra da frase é comparada com a letra informada,
 *    desconsiderando diferenças entre maiúsculas e minúsculas.
 * 5. Alteração: As ocorrências encontradas são convertidas para maiúsculo.
 * 6. Saída: Exibe a frase modificada após as substituições realizadas.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho máximo da string através da diretiva
 *   #define TAM 51.
 * - Strings: Utilização de um vetor de caracteres para armazenar a frase.
 * - Manipulação de Strings: Uso de fgets() para leitura do texto e strcspn()
 *   para remoção do caractere de quebra de linha.
 * - Biblioteca ctype.h: Aplicação das funções tolower(), toupper() e
 *   isalpha() para tratamento e validação de caracteres.
 * - Estruturas de Repetição: Uso de laço for para percorrer a string e
 *   while para validação da entrada.
 * - Estruturas Condicionais: Verificação das ocorrências da letra pesquisada.
 * - Processamento de Texto: Alteração seletiva de caracteres dentro da frase.
 * - Validação de Entrada: Garantia de que apenas letras sejam aceitas pelo
 *   programa.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
