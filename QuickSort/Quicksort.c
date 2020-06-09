#include <stdio.h>
int particiona(int *v, int inicio, int fim);

void quick_sort(int *v, int inicio, int fim){
	int divisor=0;
	if(inicio<fim){
		divisor = particiona(v, inicio, fim);
		quick_sort(v,inicio, divisor-1);
		quick_sort(v,divisor+1, fim);
	}
}

int particiona(int *v, int inicio, int fim){
    int pivo= v[inicio];
    int esq = inicio +1; 
    int dir = fim;
    int temp=0;
    int divisor;
    
    while(esq<dir){
        while (v[esq]<= pivo && esq<=fim) esq=esq+1;
        while (v[dir] > pivo && dir>=inicio) dir=dir-1;
        if(esq<=dir){
            temp = v[esq];
            v[esq] = v[dir];
            v[dir] = temp;
        }
    }
    
    // colocando a raiz no local correto
     divisor = dir;
    
    if(v[inicio] > v[divisor]){
        temp = v[inicio];
        v[inicio] = v[divisor];
        v[divisor] = temp;
    }
    
    return(divisor);
}


