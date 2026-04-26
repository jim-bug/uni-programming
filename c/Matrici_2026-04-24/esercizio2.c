/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-04-24
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#define N 2
#define M 2

int counter(int[], int, int);
int is_present(int[][M], int, int, int);

int main(void){
	int mat[N][M], k, count = 0;

	printf("Inserisci il valore di k: ");
	scanf("%d", &k);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("Inserisci l'elemento della  matrice alla posizione [%d, %d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}

	for (int i = 0;i < N; i++){
		count += counter(mat[i], M, k);
	}

	printf("Il numero %d%scompare, comparso: %d volte nella matrice.\n", k, (is_present(mat, N, M, k)) ? " " : " non ", count);
	
	return 0;
}

int counter(int arr[], int n, int k){
	int count = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] == k){
			count ++;
		}
	}

	return count;
}

int is_present(int matrix[][M], int n, int m, int k){
	for (int i = 0; i < n; i++){
		if(counter(matrix[i], m, k) > 0){
			return 1;
		}
	}

	return 0;
}
