/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de cadastro e atualização salarial de funcionários, permitindo o
 * registro de dados pessoais e profissionais, além da aplicação automática
 * de aumento salarial para colaboradores que atendam a critérios específicos.
 *
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário informa os dados de cada funcionário, incluindo
 *    nome, matrícula, escolaridade, tempo de serviço e salário.
 * 2. Armazenamento: Os dados são guardados em um vetor de estruturas.
 * 3. Análise: O programa verifica quais funcionários atendem aos critérios
 *    para receber aumento salarial.
 * 4. Processamento: Funcionários com escolaridade nível 3, mais de 5 anos de
 *    serviço e salário inferior a R$ 1000,00 recebem aumento de 20%.
 * 5. Saída: Exibe os dados dos funcionários contemplados e seus novos salários.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Structs: Utilização da estrutura Funcionario para agrupar informações
 *   relacionadas a cada colaborador.
 * - Constante: Definição da quantidade de funcionários através da diretiva
 *   #define TAM.
 * - Vetor de Estruturas: Armazenamento dos cadastros em um array de registros.
 * - Modularização: Divisão da lógica em funções para cadastro e atualização
 *   salarial.
 * - Manipulação de Strings: Uso de fgets() para leitura de textos e strcspn()
 *   para remoção do caractere de quebra de linha.
 * - Estruturas Condicionais: Aplicação de critérios para concessão de aumento.
 * - Operações Aritméticas: Cálculo do reajuste salarial de 20%.
 * - Entrada de Dados: Leitura de informações numéricas e textuais fornecidas
 *   pelo usuário.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#define TAM 2 // Altere para 50

typedef struct {
    char nome[100];
    char matricula[7];
    int escolaridade; // 1, 2 ou 3
    int tempo_servico;
    float salario;
} Funcionario;


void preencherCadastro(Funcionario vetor[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        printf("\n====== Cadastro do Funcionario %d ======\n", i + 1);
        
        printf("Nome: ");
        fgets(vetor[i].nome, 100, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0'; // Remove o Enter
        
        printf("Matricula: ");
        fgets(vetor[i].matricula, 7, stdin);
        vetor[i].matricula[strcspn(vetor[i].matricula, "\n")] = '\0';
        
        printf("Grau de escolaridade (1, 2 ou 3): ");
        scanf("%d", &vetor[i].escolaridade);
        
        printf("Tempo de servico (em anos): ");
        scanf("%d", &vetor[i].tempo_servico);
        
        printf("Salario atual (R$): ");
        scanf("%f", &vetor[i].salario);
        getchar();
    }
}

void aplicarAumento(Funcionario vetor[]) {
    int i;
    printf("\n===================================================\n");
    printf("     FUNCIONARIOS QUE RECEBERAM AUMENTO DE 20%%     \n");
    printf("===================================================\n");
    
    for (i = 0; i < TAM; i++) {
        if (vetor[i].escolaridade == 3 && vetor[i].tempo_servico > 5 && vetor[i].salario < 1000.00) {
            vetor[i].salario *= 1.20;  //salario + 20% (*1.20) 
    
            printf("Nome: %s\n", vetor[i].nome);
            printf("Matricula: %s\n", vetor[i].matricula);
            printf("Novo Salario: R$ %.2f\n", vetor[i].salario);
            printf("---------------------------------------------------\n");
        }
    }
}

int main() {
    Funcionario cadastro[TAM];
    preencherCadastro(cadastro);
    aplicarAumento(cadastro);
    return 0;
}
