/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-06
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int conta_positivi(int*, size_t);

int main (void){
	size_t n;
	
	do {
		printf("Inserisci la lunghezza della sequenza (> 0): ");
		scanf("%lu", &n);
	} while (n <= 0);

	int array[n];

	for (int i = 0; i < n; i++){
		printf("Inserisci l'elemento alla posizione %d: ", i);
		scanf("%d", array+i);
	}

	printf("Nell'array sono stati trovati %d numeri positivi\n", conta_positivi(array, n));
	return 0;

}

int conta_positivi(int *array, size_t num_elements){
	int counter = 0;
	for (int i = 0;i < num_elements; i++){
		if (*(array + i) > 0) counter ++;
	}

	return counter;
}
