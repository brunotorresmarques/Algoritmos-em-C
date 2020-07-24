typedef struct pilha Pilha;

typedef struct peca{
		char nome;
		int prioridade;
		int quebrada;
}Peca;


Pilha* criar();

void inserir(Pilha *p, Peca *peca);

Peca* remover(Pilha *p);

int vazia(Pilha *p);

int cheia(Pilha *p);

void imprimir(Pilha *p);

void liberar(Pilha *p);
