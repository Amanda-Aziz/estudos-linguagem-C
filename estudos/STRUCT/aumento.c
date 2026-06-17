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
