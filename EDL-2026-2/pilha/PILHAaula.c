#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct pilha{
    int dados[100];
    int topo[MAX];
}
typedef struct pilha* Pilha;

Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p != NULL){
        p->topo=0;
    }
    return p;
}

int empilhar(Pilha p,int valor){ //push
    if(p->topo < MAX){
        p->dados[p->topo] = valor;
        p->topo++;
        return 1;
    }
    return 0;
}

int acessar_topo(Pilha p){  //peek
    if(p->topo == 0){ //pilha vazia
        return 0;
    }
    return p->dados[p->topo-1];
}

int desempilhar(Pilha p){ //pop
    if(p->topo == 0){ //pilha vazia
        return 0;
    }
    return p->topo--;
    return 1;
}


void destruir(){  //free
    if(p != NULL){
        free(p);
    }
}

int main(){
    Pilha p = criar();
    empilhar(p, 50);
    empilhar(p, 60);
    empilhar(p, 70);
    empilhar(p, 20);
    printf("Topo da pilha: %d\n", acessar_topo(p));
    desempilhar(p);
    desempilhar(p);
    printf("Topo da pilha: %d\n", acessar_topo(p));
    destruir(p);
    return 0;
}
