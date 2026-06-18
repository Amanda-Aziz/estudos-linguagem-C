/******************************************************************************
 * DESCRIÇÃO:
 * Sistema simples de correção de prova objetiva utilizando um gabarito e as
 * respostas fornecidas por um aluno.
 *
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário informa o gabarito oficial das 10 questões.
 * 2. Coleta: O usuário registra as respostas do aluno para cada questão.
 * 3. Processamento: O programa compara cada resposta com o gabarito.
 * 4. Saída: Exibe a quantidade total de acertos obtidos pelo aluno.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição do tamanho da prova através da diretiva #define TAM 10.
 * - Vetores: Armazenamento do gabarito e das respostas em arrays de caracteres.
 * - Modularização: Divisão da lógica em 3 funções principais.
 * - Estrutura de Repetição: Uso de laços for para percorrer as questões.
 * - Comparação de Dados: Verificação de igualdade entre respostas e gabarito.
 * - Entrada de Caracteres: Utilização de scanf() e getchar() para leitura e
 *   controle do buffer de entrada.
 *
 * Autor/User: Amanda-Aziz
 * Data: Junho de 2026
 *******************************************************************************/

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
