/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de busca em texto que permite ao usuário informar uma frase e um
 * caractere específico, realizando a contagem de quantas vezes esse caractere
 * aparece no texto digitado.
 *
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário digita uma frase de até 100 caracteres.
 * 2. Coleta: O usuário informa o caractere que deseja procurar.
 * 3. Processamento: O programa percorre toda a frase caractere por caractere.
 * 4. Comparação: Cada posição da string é comparada com o caractere informado.
 * 5. Saída: Exibe a quantidade total de ocorrências encontradas na frase.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho máximo da string através da diretiva
 *   #define TAM 101.
 * - Strings: Utilização de um vetor de caracteres para armazenar a frase.
 * - Manipulação de Strings: Uso de fgets() para leitura da entrada textual.
 * - Modularização: Separação da lógica em funções para entrada e pesquisa.
 * - Estruturas de Repetição: Uso de um laço for para percorrer a string.
 * - Estruturas Condicionais: Utilização de if para verificar ocorrências do
 *   caractere pesquisado.
 * - Contadores: Registro da quantidade de vezes que o caractere aparece.
 * - Busca Sequencial: Pesquisa realizada percorrendo todos os caracteres da
 *   frase até encontrar o caractere nulo '\0'.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
