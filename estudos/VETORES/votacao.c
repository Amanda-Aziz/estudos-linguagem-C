#include <stdio.h>
#define TOTAL_OPCOES 10


int main(){
    int votos[TOTAL_OPCOES] = {0};
    float percentuais[TOTAL_OPCOES] = {0.0};
    int total_geral = 0;
    int voto;
    char continuar;

    
    do{
        
        printf("\n=====================================\n");
        printf("          PAINEL DE VOTAÇÃO          \n");
        printf("=====================================\n");
        printf(" 0 - Voto em branco\n");
        printf(" 1 - Voto em João\n");
        printf(" 2 - Voto em Maria\n");
        printf(" 3 - Voto em Pedro\n");
        printf(" 4 - Voto em Luís\n");
        printf(" 5 - Voto em Ana\n");
        printf(" 6 - Voto em Luiza\n");
        printf(" 7 - Voto em Silvia\n");
        printf(" 8 - Voto em André\n");
        printf("-------------------------------------\n");
        printf(" Qualquer outro número será NULO\n");
        printf("=====================================\n");
        
        
        printf("Digite seu voto (0 - 8): ");
        scanf("%d", &voto);
        getchar();
        if(voto >= 0 && voto <=8 ){
            votos[voto]++;
        } else {
            votos[9]++;
        }
        total_geral++;
        
        do {
            printf("Deseja continuar? (S/N): ");
            scanf(" %c", &continuar); // Espaço antes de %c limpa o Enter do teclado
        } while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
        
    }while(continuar == 's' || continuar == 'S');
    
    
    char *nomes[TOTAL_OPCOES] = {"Voto em Branco", "\nJoão", "\nMaria", "\nPedro", "\nLuís", "\nAna", "\nLuiza", "\nSilvia", "\nAndré", "\nVoto Nulo"};
    
    printf("\n===================================\n");
    printf("        RESULTADO DA ELEIÇÃO         \n");
    printf("=====================================\n");
    
    if(total_geral > 0){
        for(int i=0; i<TOTAL_OPCOES; i++){
            percentuais[i] = (votos[i]/total_geral)*100;
            printf("%s: %d votos (%.2f%%)", nomes[i], votos[i], percentuais[i]);
        }
        printf("\n====================================\n");
        printf("Total Geral de Votos: %d\n", total_geral);
    } else {
        printf("Nenhum voto foi computado.\n");
    }
    
    return 0;
}
