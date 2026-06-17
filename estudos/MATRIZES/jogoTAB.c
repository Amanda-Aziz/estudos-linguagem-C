#include <stdio.h>
#define ORDEM 10

#include <stdlib.h>
#include <time.h>

void preencher(int m[][ORDEM]){
    int i,j;
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            m[i][j] = rand()%3; // 0 1 ou 2 de forma aleatoria
        }
    }
}

void jogarOjogo(int mat[][ORDEM]){
    int i,j;
    int chances = 10;
    int vidas = 5;
    int motos_achadas = 0;
    
    do{
        printf("\n========================================");
        printf("\nChances: %d | Vidas: %d | Motos: %d/5", chances, vidas, motos_achadas);
        printf("\nDigite a linha (0-9) e coluna (0-9): ");
        scanf("%d %d", &i, &j);
        
        // Validação para o usuário não digitar coordenadas fora da matriz
        if(i < 0 || i >= ORDEM || j < 0 || j >= ORDEM) {
            printf("Coordenada invalida.\n");
            chances--;
            continue;
        }
        
        // Verifica o que tem na posição digitada
        if(mat[i][j] == 2){
            printf("\nVoce achou uma MOTO!\n");
            motos_achadas++;
            mat[i][j] = 0;// Limpa a posição para não achar a mesma moto
            chances--;
        }
        else if(mat[i][j] == 1) {
            printf("\nVoce achou uma BOMBA.\n");
            vidas--;
            mat[i][j] = 0;
            chances--;
        }
        else{
            printf("\nNada aqui...\n");
            chances--;
        }
    }while(chances>0 && vidas > 0 && motos_achadas < 5);
    
    printf("\n========================================");
    if(motos_achadas == 5) {
        printf("\nPARABENS! Voce ganhou uma moto de verdade!\n");
    } else if(vidas == 0) {
        printf("\nFim de jogo! Voce perdeu todas as suas vidas.\n");
    } else {
        printf("\nFim de jogo! Suas chances acabaram.\n");
    }
}

int main(){
    srand(time(NULL));
    int matriz[ORDEM][ORDEM];
    int opcao;
    
    do{
        printf("\n========================================");
        printf("\n1 - Jogar\n");
        printf("2 - Encerrar o programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: 
                preencher(matriz);
                jogarOjogo(matriz);
                break;
            case 2: 
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n\n");
                break;
        }
        
    } while(opcao != 2); //continua rodando até digitar 2
    
    return 0;
}
