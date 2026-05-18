/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-03-27
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

#include <stdio.h>


int contains_value(int[], int, int);
int main(void) {
	int size, target_value;
	printf("Inserisci il valore da cercare: ");
	scanf("%d", &target_value);

	do {
		printf("Inserisci la dimensione dell'array: ");
		scanf("%d", &size);

	} while (size <= 0);
	
	int array[size];
	
	for(int i = 0; i < size; i++) {
		printf("Inserisci l'elemento alla posizione %d dell'array: ", i);
		scanf("%d", &array[i]);
	}

	printf("Il valore %d %s presente!\n", target_value, contains_value(array, size, target_value) ? "è" : "non è");

	return 0;
}

int contains_value(int values[], int size, int target_value) {
	for(int i = 0; i < size; i++){
		if (values[i] == target_value){
			return 1;
		}
	}
	return 0;
}
