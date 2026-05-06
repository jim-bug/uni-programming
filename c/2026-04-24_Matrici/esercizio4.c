/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-04-24
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#define N 3

int search(char[], char, int);
int check(char[][N], char, int);

int main(void){
	char mat[N][N];
	char sequence[3] = {'X', 'O', '.'};
	char player;

	do {
		printf("Inserisci il giocatore di cui si vuole verificare la vittoria (X, O): ");
		scanf(" %c", &player);
	} while (!search(sequence, player, N-1));



	for (int i = 0;i < N; i++){
		for (int j = 0; j < N; j++){
			do {
				printf("Inserisci alla posizione %d:%d il segno (X, O, .): ", i, j);
				scanf(" %c", &mat[i][j]);
			} while (!search(sequence, mat[i][j], N));
		}
	}


	printf("\nIl giocatore %c %s.\n", player, (check(mat, player, N)) ? "ha vinto" : "ha perso");
	
	return 0;
}

int search(char arr[], char k, int len){
	for (int i = 0;i < len; i++){
		if (arr[i] == k){
			return 1;
		}
	}

	return 0;
}

int check(char mat[][N], char player, int n){

	if(mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) return 1;		// controllo sulla diagonale principale
	if(mat[0][2] == player && mat[1][1] == player && mat[2][0] == player) return 1;		// controllo sulla diagonale secondaria

	for (int i = 0; i < n; i++){
		if(mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) return 1;		// controllo sulle righe
		if(mat[0][i] == player && mat[1][i] == player && mat[2][i] == player) return 1;		// controllo sulle colonne
	}

	return 0;
}