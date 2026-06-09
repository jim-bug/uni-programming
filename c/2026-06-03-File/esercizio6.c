/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Use %s file.\n", argv[0]);
		return -1;
	}

	size_t rows, cols;
	FILE* output;

	if ((output = fopen(argv[1], "w")) == NULL){
		fprintf(stderr, "Impossibile aprire il file.\n");
		return -1;
	}

	printf("Inserisci il numero di righe: ");
	scanf("%zu", &rows);

	printf("Inserisci il numero di colonne: ");
	scanf("%zu", &cols);

	int* matrix;

	if ((matrix = malloc(rows * cols * sizeof(int))) == NULL){
		fprintf(stderr, "Impossibile allocare la memoria.\n");
		return -1;
	}

	fprintf(output, "%zu %zu\n", rows, cols);

	for(size_t i = 0; i < rows; i ++){
		for (size_t j = 0; j < cols; j++){
			matrix[(i * cols) + j] = i * j;
			fprintf(output, "%zu ", i * j);
		}
		fprintf(output, "%c", '\n');
	}


	free(matrix);
	fclose(output);
	
	return 0;
}
