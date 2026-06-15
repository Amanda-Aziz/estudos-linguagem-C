//Exercícios de passagem de parâmetros por referência

#include <stdio.h>

// O procedimento recebe X por referência (ponteiro) para poder alterá-lo
// O incremento e a quantidade são passados por valor (cópia)
void aplicarIncremento(int *X, int incremento, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        *X = *X + incremento; // Modifica diretamente o X da main
    }
}

int main() {
    int x_inicial, inc, qtd;

    printf("Digite o valor inicial de X: ");
    scanf("%d", &x_inicial);
    
    printf("\nDigite o valor do incremento: ");
    scanf("%d", &inc);
    
    printf("Digite a quantidade de vezes: ");
    scanf("%d", &qtd);

    // Chamada do procedimento: passamos o endereço de x_inicial (&) e os valores de inc e qtd
    aplicarIncremento(&x_inicial, inc, qtd);

    //Saída de dados feita na main
    printf("\nValor final de X: %d\n", x_inicial);

    return 0;
}
