/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

int col_sum(int*, size_t, size_t, size_t);

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Use %s file.\n", argv[0]);
		return -1;
	}

	size_t rows, cols;
	FILE* input;

	if ((input = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Impossibile aprire il file.\n");
		return -1;
	}


	if (fscanf(input, "%zu %zu", &rows, &cols) != 2){
		fprintf(stderr, "File non valido.\n");
		fclose(input);
		return -1;
	}

	int* matrix;

	if ((matrix = malloc(rows * cols * sizeof(int))) == NULL){
		fprintf(stderr, "Impossibile allocare la memoria.\n");
		return -1;
	}

	for(size_t i = 0; i < rows; i ++){
		for (size_t j = 0; j < cols; j++){
			fscanf(input, "%d", (i * cols) + j + matrix);
		}
	}

	fclose(input);

	for (size_t i = 0; i < cols; i ++){
		printf("Somma della colonna %zu: %d.\n", i, col_sum(matrix, i, rows, cols));
	}


	free(matrix);

	return 0;
}

int col_sum(int* matrix, size_t col, size_t rows, size_t cols){
	int sum = 0;
	for (size_t i = 0; i < rows; i++){
		sum += matrix[i * cols + col];
	}

	return sum;
}
