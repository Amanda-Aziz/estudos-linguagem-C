#include <stdio.h>
#include <string.h>
#define TAM 3
#define TAM_NOME 80
#define TAM_RA 7

typedef struct pessoa{
    char RA[TAM_RA];
    char nome[TAM_NOME];
    float media;
    int faltas;
} Pessoa;

void preencher(Pessoa aluno[]){
    printf("\n=========== PREENCHENDO DADOS DA TURMA ===========\n");
    for(int i = 0; i < TAM; i++){
        printf("\nDigite o nome do aluno %d: ", i + 1);
        fgets(aluno[i].nome, TAM_NOME, stdin);
        
        printf("Digite o RA do aluno: ");
        fgets(aluno[i].RA, TAM_RA, stdin);

        printf("Digite a media do aluno: ");
        scanf("%f", &aluno[i].media);
        printf("Digite o número de faltas do aluno: ");
        scanf("%d", &aluno[i].faltas);

        getchar();
    }
}

void alunosEMfinal(Pessoa aluno[]){
    int finalistas = 0;
    printf("\n=========== ALUNOS NA FINAL ===========\n");
    for(int i = 0; i < TAM; i++){
        if(aluno[i].media < 7 && aluno[i].media >= 3){
            finalistas++;
            printf("\nAluno: %s", aluno[i].nome);
            printf("Media: %.2f\n", aluno[i].media);
        }
    }
    printf("\nTotal de alunos na final: %d\n", finalistas);
}

int main(){
    Pessoa aluno[TAM];
    preencher(aluno);
    alunosEMfinal(aluno);
    return 0;
}
