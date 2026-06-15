#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarCodigo(char codigo[]) {

    if (strlen(codigo) != 9) {
        return 1;
    }

    if (codigo[0] != 'a' && codigo[0] != 'A') {
        return 2;
    }

    //verifica as próximas 3 letras (índices 1, 2 e 3)
    for (int i = 1; i < 4; i++) {
        if (!isalpha(codigo[i])) {
            return 2;
        }
    }

    //verifica os 5 dígitos numéricos (índices 4 a 8)
    for (int i = 4; i < 9; i++) {
        if (!isdigit(codigo[i])) {
            return 2;
        }
    }
    
    //se nao houver caso de erro:
    return 3;
}

int main() {
    char codigo[10];

    printf("Informe o código de um produto: ");
    scanf("%s", codigo);

    int resultado = validarCodigo(codigo);

    if (resultado == 3) {
        printf("O código %s é válido.\n", codigo);
    } 
    else if (resultado == 1) {
        printf("O código %s não é válido. Motivo: quantidade inválida de caracteres.\n", codigo);
    } 
    else if (resultado == 2) {
        printf("O código %s não é válido. Motivo: formato incorreto.\n", codigo);
    }

    return 0;
}
