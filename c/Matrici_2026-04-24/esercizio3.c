/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-04-24
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

void swap_matrix(int n, int[][n]);
void print_matrix(int n, int[][n]);

int main(void){
	int n;

	do {
		printf("Inserisci la dimensione della matrice (> 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	int mat[n][n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("Inserisci l'elemento della  matrice alla posizione [%d:%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}

	swap_matrix(n, mat);
	print_matrix(n, mat);

	return 0;
}

void swap_matrix(int n, int mat[][n]){
	for (int i = 0; i < n; i++){
		int temp = mat[i][i];
		mat[i][i] = mat[i][n - i - 1];
		mat[i][n - i - 1] = temp;
	}
}

void print_matrix(int n, int mat[][n]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
