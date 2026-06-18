/******************************************************************************
 * DESCRIÇÃO:
 * Sistema de votação eletrônica que registra votos para candidatos, votos em
 * branco e votos nulos, realizando a apuração e a exibição dos resultados
 * finais da eleição.
 *
 * FUNCIONAMENTO:
 * 1. Votação: O eleitor escolhe uma opção entre os candidatos disponíveis.
 * 2. Registro: O programa contabiliza votos válidos, votos em branco e votos
 *    nulos.
 * 3. Continuação: Após cada voto, o usuário decide se deseja registrar outro
 *    eleitor.
 * 4. Processamento: Ao final da votação, o sistema calcula a quantidade e o
 *    percentual de votos recebidos por cada opção.
 * 5. Saída: Exibe um relatório completo contendo os resultados da eleição e
 *    o total geral de votos computados.
 *
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constante: Definição da quantidade de opções de votação através da
 *   diretiva #define TOTAL_OPCOES 10.
 * - Vetores: Armazenamento da contagem de votos e dos percentuais de cada
 *   opção em arrays.
 * - Estruturas de Repetição: Uso dos laços do...while e for para controle da
 *   votação e exibição dos resultados.
 * - Estruturas Condicionais: Utilização de if/else para identificar votos
 *   válidos e votos nulos.
 * - Contadores: Controle do total de votos recebidos por cada opção.
 * - Cálculo Percentual: Determinação da participação de cada candidato em
 *   relação ao total de votos registrados.
 * - Manipulação de Strings: Utilização de um vetor de ponteiros para armazenar
 *   os nomes dos candidatos e categorias de voto.
 * - Interação com o Usuário: Menu textual para entrada e acompanhamento da
 *   votação.
 *
 * Autor/User: Amanda-Aziz
 * Data: 18 de Junho de 2026
 *******************************************************************************/

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
