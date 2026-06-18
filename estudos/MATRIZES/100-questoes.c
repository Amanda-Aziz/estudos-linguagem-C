/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de correção automatizada de provas que registra um gabarito oficial,
 * coleta as respostas de vários alunos e calcula a quantidade de acertos de
 * cada participante, informando sua situação final.
 *
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário informa o gabarito oficial das 100 questões da prova.
 * 2. Validação: O sistema aceita apenas alternativas válidas (a, b, c, d ou e).
 * 3. Coleta: São registradas as respostas de até 50 alunos para todas as
 *    questões da avaliação.
 * 4. Processamento: As respostas dos alunos são comparadas com o gabarito.
 * 5. Correção: O programa contabiliza a quantidade de acertos de cada aluno.
 * 6. Saída: Exibe o total de acertos e informa se o aluno está aprovado ou
 *    reprovado com base na nota de corte de 70 questões.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constantes: Definição da quantidade de alunos, questões e colunas através
 *   das diretivas #define L 50, #define C 100 e #define QUEST 100.
 * - Matrizes: Utilização de uma matriz para armazenar as respostas dos alunos.
 * - Vetores: Armazenamento do gabarito oficial e da quantidade de acertos.
 * - Modularização: Separação da lógica em funções de preenchimento, correção
 *   e exibição de resultados.
 * - Estruturas de Repetição: Uso de laços for para percorrer questões e alunos.
 * - Estruturas Condicionais: Utilização de if e do...while para validação e
 *   classificação dos resultados.
 * - Validação de Entrada: Garantia de que apenas alternativas válidas sejam
 *   aceitas pelo sistema.
 * - Comparação de Dados: Verificação das respostas dos alunos em relação ao
 *   gabarito oficial.
 * - Processamento de Matrizes: Manipulação de dados bidimensionais para
 *   representar as respostas de múltiplos alunos.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#define QUEST 100
#define L 50
#define C 100

void preencherGAB(char g[]){
    int i;
    for(i = 0; i < C; i++){
        do {
            printf("Digite o gabarito da questão %d (a - e): ", i + 1);
            scanf(" %c", &g[i]);
            if (g[i] != 'a' && g[i] != 'b' && g[i] != 'c' && g[i] != 'd' && g[i] != 'e') {
                printf("Alternativa inválida.\n");
            }
        } while(g[i] != 'a' && g[i] != 'b' && g[i] != 'c' && g[i] != 'd' && g[i] != 'e');
    }
}

void preencherRESPS(char m[][C]){
    int i, j;
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            do{
               printf("Digite a resposta dada na questão %d [Coordenada: %d,%d]: ", j + 1, i, j);
                scanf(" %c", &m[i][j]); 
                if (m[i][j] != 'a' && m[i][j] != 'b' && m[i][j] != 'c' && m[i][j] != 'd' && m[i][j] != 'e') {
                printf("Alternativa inválida.\n");
                }
            } while(m[i][j] != 'a' && m[i][j] != 'b' && m[i][j] != 'c' && m[i][j] != 'd' && m[i][j] != 'e');
        }
    }
}

void calcularAcertos(char gab[], char resps[][C], int acertados[]){
    int i,j;
    for(i = 0; i < L; i++){
        acertados[i] = 0;
        for(j = 0; j < C; j++){
            if(resps[i][j] == gab[j]){
                acertados[i]++;
            }
        }
    }
}

void informarSituacao(int acertos[]){
    int i;
    for(i = 0; i < L; i++){
        if(acertos[i] >= 70){
            printf("O aluno número %d acertou %d questões e está aprovado.\n", i + 1, acertos[i]);
        } else {
            printf("O aluno número %d acertou %d questões e está reprovando.\n", i + 1, acertos[i]);
        }
    }
}

int main(){
    char mat[L][C];
    char gabarito[C];
    int acertos[L] = {0};

    preencherGAB(gabarito);
    preencherRESPS(mat);
    calcularAcertos(gabarito, mat, acertos);
    
    informarSituacao(acertos);
    return 0;
}
