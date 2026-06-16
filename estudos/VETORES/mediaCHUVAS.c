#include <stdio.h>
#define TAM 30

//item a
void preencher(float v[]){
    int i;
    printf("======================================================\n");
    printf("                  REGISTRO DE CHUVAS                  \n");
    printf("======================================================\n");
    for(i=0; i<TAM; i++){
        printf("Digite a quantidade de chuvas no %dº dia (em mm): ", i+1);
        scanf("%f", &v[i]);
    }
    printf("\n");
}

//item b
float calcularMEDIA(float vet[]){
    int i;
    float soma=0.0;
    for(i = 0; i < TAM; i++) {
        soma=soma+vet[i];
    }
    // Retorna o resultado da divisão (soma total dividido por 30)
    return soma/TAM;
}

//item c
int diasACIMAdaMedia(float vetor[], float media_calculada){
    int i=0;
    int contador=0;
    for(i=0; i<TAM; i++){
        // Se a chuva do dia for maior que a média, contamos esse dia
        if(vetor[i] > media_calculada){
            contador++;
        }
    }
    return contador; // devolve a quantidade total de dias
}

//item d
float menorREGISTRO(float Vetor[]){
    int i;
    float menor=Vetor[0];
    for(i = 0; i < TAM; i++) {
        if(Vetor[i] < menor){
            menor = Vetor[i];
        }
    }
    return menor; // Retorna a menor chuva encontrada
}

//item e
float maiorREGISTRO(float Vetor[]){
    int i;
    float maior=Vetor[0];
    for(i = 0; i < TAM; i++) {
        if(Vetor[i] > maior){
            maior = Vetor[i];
        }
    }
    return maior; // Retorna a menor chuva encontrada
}

int main(){
    float chuvas[TAM];
    float media;
    int dias_acima;
    float maior, menor;
    
    preencher(chuvas);                                  //a
    media = calcularMEDIA(chuvas);                      //b
    dias_acima = diasACIMAdaMedia(chuvas, media);      //c
    menor = menorREGISTRO(chuvas);                    //d
    maior = maiorREGISTRO(chuvas);                    //e
    
    //exibindo os resultados
    
    printf("======================================================\n");
    printf("               RELATÓRIO MENSAL                   \n");
    printf("======================================================\n");
    printf("Média diária de chuvas: %.2f mm\n", media);
    printf("Dias com chuva acima da média: %d dia(s)\n", dias_acima);
    printf("Menor quantidade de chuva registrada: %.2f mm\n", menor);
    printf("Maior quantidade de chuva registrada: %.2f mm\n", maior);
    printf("======================================================\n");
    
    return 0;
}
