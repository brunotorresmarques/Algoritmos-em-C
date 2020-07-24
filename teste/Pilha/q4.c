#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"
#include<time.h>


int main(){
	Pilha* j1 = criar();
	Pilha* j2 = criar();
	Pilha* aux1 = criar();
	Pilha* aux2 = criar();
	int valor,s;
	
	for(int i = 0; i < 5; i++){
		printf("Jogador 1 digite o valor: ");
		scanf("%d",&valor);
		inserir(j1, valor);
		printf("Jogador 2 digite o valor: ");
		scanf("%d",&valor);
		inserir(j2, valor);
	}
	
	while(!vazia(j1)){
		inserir(aux1, remover(j1));
		inserir(aux2, remover(j2));
	}
	srand(time(NULL));
	s = 1 + rand()%10;
	printf("O valor e %d \n",s);
	while(!vazia(aux1)){
		if(remover(aux1) == s){
			printf("Jogador 1 ganhou");
			break;
		}
		if(remover(aux2) == s){
			printf("Jogador 2 ganhou");
			break;
		}
			
		
	}
	
}
