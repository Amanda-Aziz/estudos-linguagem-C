#include <stdio.h>
#include <string.h>
#define TAM 100
#define TAM_NOME 80

typedef struct {
    char nome[TAM_NOME];
    char genero;
    int idade;
    float peso;
    float altura;
} Aluno;

/* (b) BUSCAR ALUNO ESPECIFICO */
int buscar_aluno(Aluno cadastro[], int n, const char nome[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(cadastro[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; //sinalizador universal, porque a posição 0 seria o primeiro aluno do vetor [1].
}

/* (a) CADASTRAR ALUNO NOBO */
void cadastrar_novo(Aluno cadastro[], int *n, const char nome[]) {
    int pos;
    if (*n >= TAM) {
        printf("Cadastro cheio.\n");
        return;
    }
    pos = buscar_aluno(cadastro, *n, nome);
    if (pos != -1) {
        printf("Aluno com esse nome ja cadastrado.\n");
        return;
    }

    strcpy(cadastro[*n].nome, nome);

    printf("Informe o genero (M/F): ");
    scanf(" %c", &cadastro[*n].genero);

    printf("Informe a idade: ");
    scanf("%d", &cadastro[*n].idade);

    printf("Informe o peso: ");
    scanf("%f", &cadastro[*n].peso);

    printf("Informe a altura: ");
    scanf("%f", &cadastro[*n].altura);

    (*n)++;
    printf("Aluno cadastrado com sucesso.\n");
}

/* (c) EXIBIR ALUNOS */
void exibir_nomes(Aluno cadastro[], int n) {
    int i;
    if (n == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        printf("%s\n", cadastro[i].nome);
    }
}

/* (d) ALUNO ESPECIFICO */
void exibir_dados_aluno(Aluno cadastro[], int n, const char nome[]) {
    int pos = buscar_aluno(cadastro, n, nome);
    if (pos == -1) {
        printf("\nAluno nao encontrado.\n");
        return;
    }
    printf("\nNome: %s\n", cadastro[pos].nome);
    printf("Genero: %c\n", cadastro[pos].genero);
    printf("Idade: %d\n", cadastro[pos].idade);
    printf("Peso: %.2f\n", cadastro[pos].peso);
    printf("Altura: %.2f\n", cadastro[pos].altura);
}
int main(void) {
    Aluno cadastro[TAM];
    int n = 0;
    int opcao;
    char nome[TAM_NOME];

    do {
        printf("\n===== Academia malhacao - Informe a opcao desejada. ===== \n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Exibir nomes dos alunos cadastrados\n");
        printf("3 - Exibir dados de um aluno especifico\n");
        printf("0 - Encerrar o programa\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Limpar o caractere '\n'
            while (getchar() != '\n'); 

            printf("Nome do novo aluno: ");
            fgets(nome, TAM_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha do final

            cadastrar_novo(cadastro, &n, nome);
        } else if (opcao == 2) {
            exibir_nomes(cadastro, n);
        } else if (opcao == 3) {
            // Limpar o caractere '\n'
            while (getchar() != '\n');

            printf("Nome do aluno: ");
            fgets(nome, TAM_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0'; 

            exibir_dados_aluno(cadastro, n, nome);
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
