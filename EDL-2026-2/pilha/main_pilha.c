#include <stdio.h>
#include "pilha.h"

void main() {
	Pilha* p;
	int topo;

	p = iniciar_pilha();
	empilhar(p, 10);
	empilhar(p, 20);
	empilhar(p, 30);
	topo = top(p);
	printf("\nO topo da pilha eh igual a %d", topo);
	desempilhar(p);
	topo = top(p);
	printf("\nO topo da pilha eh igual a %d", topo);
}
