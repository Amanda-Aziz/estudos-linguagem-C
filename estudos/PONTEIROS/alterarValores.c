#include <stdio.h>

void alterarValor(int *x, int *y){
    *x = *x + *y;
    *y = *x - *y;
}

int main() {
    int x, y;

    printf("Digite um valor para X: ");
    scanf("%d", &x);
    printf("Digite um valor para Y: ");
    scanf("%d", &y);
    
    alterarValor(&x, &y);
    
    printf("\n===== NOVOS VALORES DE X E Y =====\n");
    printf("X: %d\n", x);
    printf("Y: %d", y);
    
    return 0;
}
