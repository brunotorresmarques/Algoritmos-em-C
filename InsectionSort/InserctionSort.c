#include <stdio.h>

int inserctionSort(int *v, int n){
	int i = 0, j = 0, temp = 0;
	for(i =1 ; i<n; i++){
		temp = v[i];
		for(j =i-1 ; j>=0; j--){
			if(v[j]>temp) v[j+1] = v[j];
			else break;
		}
		v[j+1] = temp;	
	}
}


