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
