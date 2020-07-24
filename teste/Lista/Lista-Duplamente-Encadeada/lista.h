typedef struct lista Lista;
Lista* criar();
void inserir(Lista *l, int valor, int pos);
int remover(Lista *l, int pos);
int vazia(Lista *l);
int cheia(Lista *l);
void imprimir(Lista *l, int pos);
void liberar(Lista *l);


