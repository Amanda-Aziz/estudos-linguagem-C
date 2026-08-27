#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pilha.h"

No* criar_no(int novo_dado) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = novo_dado;
    novo_no->prox = NULL;
    return novo_no;
}

Pilha* iniciar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->inicio = NULL;
    return p;
}

void empilhar(Pilha* p, int novo_dado) {
    No* novo_no = criar_no(novo_dado);
    novo_no->prox = p->inicio;
    p->inicio = novo_no;
}

void desempilhar(Pilha* p) {
    if (p->inicio == NULL) {
        printf("Erro: pilha vazia!\n");
    } else {
        No* temp = p->inicio;
        p->inicio = p->inicio->prox;
        free(temp);
    }
}

int top(Pilha* p) {
    if (p->inicio != NULL) {
        return p->inicio->dado;
    } else {
        printf("Pilha vazia!\n");
        return INT_MIN;
    }
}
