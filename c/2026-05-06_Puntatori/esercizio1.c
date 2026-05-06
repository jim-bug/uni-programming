/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-06
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define N 3
#define M 4

void min_max(size_t rows, size_t cols, int[][cols], int*, int*);

int main (void){
	int max, min;
	int matrix[N][M];

	for (int i = 0; i < N; i++){
		for (int j = 0;j < M; j++){
			printf("Inserisci l'elemento alla posizione [%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
		printf("\n");
	}

	min_max(N, M, matrix, &min, &max);

	printf("Il valore massimo della matrice è: %d\nIl valore minimo della matrice è: %d\n", min, max);

	return 0;

}

void min_max(size_t rows, size_t cols, int matrix[][cols], int *min, int *max){
	*max = matrix[0][0];
	*min = matrix[0][0];

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (matrix[i][j] > *max) {
				*max = matrix[i][j];
			}

			if (matrix[i][j] < *min){
				*min = matrix[i][j];
			}
		}
	}
}

