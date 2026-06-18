/******************************************************************************
 * DESCRIÇÃO:
 * Jogo de exploração em matriz no qual o jogador deve encontrar motos
 * escondidas enquanto evita bombas. O objetivo é localizar todas as motos
 * antes que as chances ou vidas se esgotem.
 *
 * FUNCIONAMENTO:
 * 1. Inicialização: O programa gera uma matriz 10x10 preenchida com valores
 *    aleatórios representando posições vazias, bombas e motos.
 * 2. Menu: O usuário escolhe entre iniciar uma partida ou encerrar o programa.
 * 3. Jogabilidade: O jogador informa coordenadas de linha e coluna para
 *    explorar posições da matriz.
 * 4. Verificação: O sistema identifica se a posição contém uma moto, uma
 *    bomba ou está vazia.
 * 5. Atualização: As chances, vidas e quantidade de motos encontradas são
 *    atualizadas a cada jogada.
 * 6. Encerramento: O jogo termina quando todas as motos são encontradas,
 *    quando as vidas chegam a zero ou quando acabam as chances disponíveis.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição da ordem da matriz através da diretiva
 *   #define ORDEM 10.
 * - Matrizes: Utilização de uma matriz bidimensional para representar o
 *   campo de jogo.
 * - Geração Aleatória: Uso das funções rand(), srand() e time() para criar
 *   posições aleatórias.
 * - Modularização: Separação da lógica em funções de preenchimento e
 *   execução da partida.
 * - Estruturas de Repetição: Aplicação de laços for e do...while.
 * - Estruturas Condicionais: Uso de if/else e switch/case para controlar
 *   eventos e opções do sistema.
 * - Validação de Entrada: Verificação de coordenadas dentro dos limites da
 *   matriz.
 * - Controle de Jogo: Gerenciamento de vidas, chances e objetivos.
 * - Menu Interativo: Interface textual para iniciar ou encerrar partidas.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
