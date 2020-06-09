#include <stdio.h>
#include <stdlib.h>

//Essa função serve para preencher os elementos do jogo (tabuleiro e jogadas).
void Tabuleiro(char tab[3][3]){
	
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t======JOGO DA VELHA======\n\n");
	
	printf ("\t\t         -------------- \n");
	printf ("\t\t colunas | 1 |  2 | 3 | \n");
	printf ("\t\t         -------------- \n");
	
	printf("\n");
	
	//Essa parte trata da construção do tabuleiro e de seu preenchimento.
	printf ("\t\t linha 1   %c | %c  | %c \n",tab[0][0],tab[0][1],tab[0][2]);
	printf ("\t\t          ---+----+--- \n");
	printf ("\t\t linha 2   %c | %c  | %c \n",tab[1][0],tab[1][1],tab[1][2]);
	printf ("\t\t          ---+----+--- \n");
	printf ("\t\t linha 3   %c | %c  | %c \n",tab[2][0],tab[2][1],tab[2][2]);
	
	system("color b"); //Essa linha serve para mudar a cor do codigo.
}

int main(){
	
	
char matriz[3][3];
	Tabuleiro(matriz);
	char r;                                    // variavel para mudar a cor do texto
	int jogadas, l, c, vez=0, i, j;
	
	do{
		jogadas=1;
		
		for(i=0; i<=2; i++){
			for(j=0; j<=2; j++){
				matriz[i][j]=' ';
			}
		}
		do{
			Tabuleiro(matriz);
			if(vez%2==0){
				printf("\n\n");
				                                                      
				printf("\t   Jogador X \n");
			}else{  
				printf("\n\n");                                                           // mostar quem esta jogando no momento
				printf("\t   Jogador O \n");
			}
			printf("\tDigite uma linha: ");
			scanf("%d", &l);
			
			printf("\n");
			
			printf("\tDigite uma coluna: ");
			scanf("%d", &c);
			if(l<1 || c<1 || l>3 || c>3){                               // verificar casos de jogadas invalidas
				l=0;
				c=0;
				system("color 6");                                    // comando para ficar vermelho quando for invalido
				printf("\n\n    Posicao invalida\n\n");
				system("pause");                                      // da uma pausa e manda continuar quando for invalida
			}else if(matriz[l-1][c-1] !=' '){                         // verificar posições ja ocupadas
				l=0;
				c=0;
				system("color 6");
				printf("\n");
				printf("\t     ESSA POSICAO JA ESTA OCUPADA\n \n");
				printf("\t   JOGUE NOVAMENTE EM OUTRA POSICAO\n \n");
				
				system("pause");
			}else{                                               // casos para preencher com X ou O
				if(vez%2==0) {
					matriz[l-1][c-1]='X';
				}else{
					matriz[l-1][c-1]='O';
				}
				vez++;
				jogadas++;
			}
			
			// essa parte verifica as possiveis condições de vitoria
			if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X') {jogadas=11;}      // condições de vitoria do X
			if(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X') {jogadas=11;}
			if(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X') {jogadas=11;}
			if(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X') {jogadas=11;}
			if(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X') {jogadas=11;}
			if(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X') {jogadas=11;}
			if(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X') {jogadas=11;}
			if(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X') {jogadas=11;}
			
			if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O') {jogadas=12;}	// condições de vitoria do O
			if(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O') {jogadas=12;}
			if(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O') {jogadas=12;}
			if(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O') {jogadas=12;}
			if(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O') {jogadas=12;}
			if(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O') {jogadas=12;}
			if(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O') {jogadas=12;}
			if(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O') {jogadas=12;}
			
		}while(jogadas<=9);                       
		
		Tabuleiro(matriz);   // comando para mostrar a ultima casa do tabuleiro caso der empate
		
		int jogX=0, jogO=0, ptx;
		
		if(jogadas==10) printf("\t\n\n     Deu velha!\n");
		
		if(jogadas==11) printf("\t\n\n      Jogador X venceu! \n"); 
		
		if(jogadas==12) printf("\t\n\n       Jogador O vencedor! \n");
			 
		printf("\t\n    Deseja jogar novamente?[s-n]");
		
		scanf(" %c",&r);
	}while(r=='s');
	 
	
}
