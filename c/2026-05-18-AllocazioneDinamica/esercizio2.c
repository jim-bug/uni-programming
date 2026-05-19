/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-18
*	Consegna: Rif. README.md
*	by jimbug // :)
*/


#include <stdio.h>
#include <stdlib.h>

int get_element(int[], size_t, size_t, size_t);
void set_element(int, int[], size_t, size_t, size_t);

int main(void) {
	size_t rows, cols;
	char op;

	printf("Inserisci il numero di righe della matrice (> 0): ");
	scanf("%zu", &rows);

	printf("Inserisci il numero di colonne della matrice (> 0): ");
	scanf("%zu", &cols);

	int *matrix = malloc(rows * cols * sizeof(int));

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			printf("Inserisci l'elemento alla posizione [%zu, %zu]: ", i, j);
			scanf("%d", &matrix[i * cols + j]);
		}
	}

	do {
		printf("Opzioni del menu:\n\t1) Sovrascrivi elemento, digitare s\n\t2) Stampare a video elemento, digitare g\n\t3) Uscita, qualsiasi restante carattere\nOpzione scelta: ");
		scanf(" %c", &op);

		switch (op) {
			case 's': {
				size_t n_rows, n_cols;
				int value;

					do {
							printf("Inserisci il numero di righe dell'elemento da sostituire (>= 0 < %zu): ", rows);
							scanf("%zu", &n_rows);
					} while (n_rows >= rows);

					do {
							printf("Inserisci il numero di colonne dell'elemento da sostituire (>= 0 < %zu): ", cols);
							scanf("%zu", &n_cols);
					} while (n_cols >= cols);
				
				printf("Inserisci l'elemento da sostituire: ");
				scanf("%d", &value);
		
				set_element(value, matrix, cols, n_rows, n_cols);

				break;
			}
		
			case 'g': {
				size_t n_rows, n_cols;

				do {
						printf("Inserisci il numero di righe dell'elemento da mandare a video (>= 0 < %zu): ", rows);
						scanf("%zu", &n_rows);
				} while (n_rows >= rows);

				do {
						printf("Inserisci il numero di colonne dell'elemento da mandare a video (>= 0 < %zu): ", cols);
						scanf("%zu", &n_cols);
				} while (n_cols >= cols);

				printf("Valore dell'elemento alla posizione [%zu, %zu]: %d\n", n_rows, n_cols, get_element(matrix, cols, n_rows, n_cols));

				break;
			}
			default: break;
		}
	} while (op == 's' || op == 'g');

	free(matrix);

	return 0;
}

int get_element(int arr[], size_t cols, size_t get_row, size_t get_col) {
	return arr[get_row * cols + get_col];
}

void set_element(int value, int arr[], size_t cols, size_t set_row, size_t set_col){
	arr[set_row * cols + set_col] = value;
}
