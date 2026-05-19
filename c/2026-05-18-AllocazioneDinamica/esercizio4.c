/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-18
*	Consegna: Rif. README.md
*	by jimbug // :)
*/


#include <stdio.h>
#include <stdlib.h>

int* matrice_trasposta(size_t rows, size_t cols, int*);

int main(void) {
	size_t rows, cols;

	printf("Inserisci il numero di righe della matrice (> 0): ");
	scanf("%zu", &rows);

	printf("Inserisci il numero di colonne della matrice (> 0): ");
	scanf("%zu", &cols);

	int* matrix = malloc(rows * cols * sizeof(int));

	for (size_t i = 0; i < rows; i++){
		for (size_t j = 0; j < cols; j++){
			printf("Inserisci l'elemento alla posizione [%zu][%zu]: ", i + 1, j + 1);
			scanf("%d", (i * cols + j + matrix));
		}
	}

	printf("\nMatrice di partenza: \n");
	for (size_t i = 0; i < rows; i++){
		for (size_t j = 0; j < cols; j++){
			printf("%d ", *(i * cols + j + matrix));
		}	
		printf("\n");
	}

	int* trasposed_matrix = matrice_trasposta(rows, cols, matrix);

	printf("\nMatrice trasposta: \n");
	for (size_t i = 0; i < cols; i++){
		for (size_t j = 0; j < rows; j++){
			printf("%d ", *(i * rows + j + trasposed_matrix));
		}	
		printf("\n");
	}

	free(matrix);
	free(trasposed_matrix);

	return 0;
}

int* matrice_trasposta(size_t rows, size_t cols, int* matrix){	
	int* t_matrix = malloc(cols * rows * sizeof(int));

	for (size_t i = 0; i < rows; i++){
		for (size_t j = 0; j < cols; j++){
			*(j * rows + i + t_matrix) = *(i * cols + j + matrix);		// m[j][i] = m[i][j]
		}
	}
	
	return t_matrix;
}
