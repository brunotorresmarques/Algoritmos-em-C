//#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no{
	int valor;
	struct no *prox;
}No;

struct pilha{
   No *base, *topo;
   int qtd_elem;
};

Pilha* criar(){
   Pilha *p = (Pilha*) malloc(sizeof(struct pilha));
   p->base = NULL;
   p->topo = NULL;
   p->qtd_elem=0;
   return p;
}


void inserir(Pilha *p, int valor){
    if(p->qtd_elem == 0){
       p->base = (No*) malloc(sizeof(struct no));
       p->topo = p->base;
       p->base->valor = valor;
       p->base->prox = NULL;
    }else{
	No *n= (No*) malloc(sizeof(struct no));
	n->valor = valor;
        n->prox = p->topo;
        p->topo =  n;
	
    }
    p->qtd_elem++;
	
}

int vazia(Pilha *p){
   if(p->qtd_elem == 0) return 1;
   else return 0; 
}

int remover(Pilha *p){
   if(!vazia(p)){
      int valor = p->topo->valor;
      No *temp = p->topo;
      p->topo = p->topo->prox;
      free(temp);
      p->qtd_elem--;
      return(valor);
   }else{
     printf("A pilha está vazia");
     exit(1);
   }
}


int cheia(Pilha *p){
    return 0;
}

void imprimir(Pilha *p){
    printf("%d", p->topo->valor);
}

void liberar(Pilha *p){
  free(p);
}
