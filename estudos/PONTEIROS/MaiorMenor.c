#include <stdio.h>

void MaiorMenor(int v1,int v2,int v3,int v4, int *maior, int *menor){
    int valores[4] = {v1,v2,v3,v4};
    *maior = v1;
    *menor = v1;
    for(int i=1; i<4; i++){
        if(valores[i] > *maior){
            *maior = valores[i];
        }
        if(valores[i] < *menor){
            *menor = valores[i];
        }
    }
}


int main() {
    int a, b, c, d, max, min;
    printf("Informe um valor: ");
    scanf("%d", &a);
    printf("Informe um valor: ");
    scanf("%d", &b);
    printf("Informe um valor: ");
    scanf("%d", &c);
    printf("Informe um valor: ");
    scanf("%d", &d);

    MaiorMenor(a, b, c, d, &max, &min); //max e min ainda não têm valor, eles vão receber valores dentro da função

    printf("\nMenor valor: %d\nMaior valor: %d\n", min, max);
    return 0;
}
