#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no{
	int valor;
	struct no *prox;
	struct no *ant;
}No;

struct lista{
   No *ini;
};

Lista* criar(){
   Lista *l = (Lista*) malloc(sizeof(struct lista));
   l->ini = NULL;
   return l;
}

void inserir(Lista *l, int valor, int pos){
    if(l->ini == NULL){
       l->ini = (No*) malloc(sizeof(struct no));
       l->ini->valor = valor;
       l->ini->prox = NULL;
       l->ini->ant = NULL;
    }else{
	No *n= (No*) malloc(sizeof(struct no));
	n->valor = valor;
        int i = 0;

        if(pos==0){
           n->prox = l->ini;
	   n->ant = NULL;
           l->ini->ant = n;
           l->ini = n;
        }else{
          No *temp = l->ini;
          while(i<pos-1 && temp->prox != NULL){
             i++;
             temp = temp->prox;
          }
          
          if(i == pos-1){
            n->prox = temp->prox;
            n->ant = temp;
            if(temp->prox!=NULL) temp->prox->ant = n;
            temp->prox = n;
          }else{printf("Não é possível inserir na posição indicada");}        
		}
    }	
}

int vazia(Lista *l){
   if(l->ini == NULL ) return 1;
   else return 0; 
}

int remover(Lista *l, int pos){  
   int i=0;
   No *temp = l->ini;
   int valor = 0;
   if(!vazia(l)){
        if(pos==0){
           valor = temp->valor;           
           l->ini = l->ini->prox;        
           if(l->ini != NULL) l->ini->ant = NULL;
           free(temp);
        }else{
           while(i<pos && temp != NULL){
             i++;
             temp = temp->prox;
           }
         
           if(i == pos && temp!=NULL){
             valor = temp->valor;
              if(temp->prox != NULL) temp->prox->ant = temp->ant;
               temp->ant->prox = temp->prox;
             free(temp);
           }else{printf("Não é possível remover na posição indicada"); 
                 exit(1);
           }
        } 
      return(valor);
   }else{
     printf("A lista está vazia");
     exit(1);
   }
}


int cheia(Lista *l){
    return 0;
}

void imprimir(Lista *l, int pos){
        int i =0;
        No *temp = l->ini;
        while(i<pos && temp != NULL){
           i++;
           temp = temp->prox;
        }
        if(temp != NULL) printf("%d", temp->valor);
}

void liberar(Lista *l){
  if(l->ini != NULL){
    No *temp = l->ini;
    No *temp2 = l->ini->prox;
    while(temp!=NULL){
       free(temp);
       temp = temp2;
       if(temp2 != NULL) temp2= temp2->prox;
    }
   
  }
  free(l);
}
