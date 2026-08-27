#define pilha_h

typedef struct no {
	int dado;
	struct no *prox;
}No;

typedef struct pilha {
	No* inicio;
}Pilha;

No* criar_no(int novo_dado);
Pilha *iniciar_pilha();
void empilhar(Pilha* p, int novo_dado);
void desempilhar(Pilha* p);
int top(Pilha* p);
